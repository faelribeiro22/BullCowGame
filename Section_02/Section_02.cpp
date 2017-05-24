/*This is the console executable, that makes us of the BullCow class
This acts as the view im a MVC pattern, and is responsibile for all
user interaction. For game logic see the FBullCowGame class.
	
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;

void PrintIntro();
FText GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
FBullCowGame BCGame; //instantiate a new game
void PrintGameSumary(FBullCowGame BCGame);

// the entry point four our application
int32 main()
{
	do {
		PrintIntro();
		PlayGame();

	} while (AskToPlayAgain());
	system("pause");

    return 0; //exit the application
}

// introduce the game
void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWorldLength();
	std::cout << " letter isogran I'm thinking of?\n";
	return;
}

void PrintGameSumary(FBullCowGame BCGame) {
	if (BCGame.IsGameWon()) 
	{
		std::cout << "You won!!!\n";
	}
	else 
	{
		std::cout << "Bad Luck!!!\n";
	}
}

void PlayGame()
{
	// repeat the guess back to them
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();
	// loop asking for guesses while the game is NOT won
	// and there are still tries remaing
	
	while (!BCGame.IsGameWon() && BCGame.GetMyCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess(); 

		// submit valid guess to the game, and receive counts 
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		// print number of bulls and cows

		std::cout << "Bulls = " << BullCowCount.Bulls << "\n";
		std::cout << "Cows = " << BullCowCount.Cows << "\n";
	}
	PrintGameSumary(BCGame);
	return;
	// TODO summarise game 
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (y/n)";
	FText Response = "";
	std::getline(std::cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}


// loop continually until the user gives a valid guess
FText GetValidGuess() 
{
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	FText Guess = "";
	do
	{
		int32 CurrentyTry = BCGame.GetMyCurrentTry();
		std::cout << "Try " << CurrentyTry << ". Enter your guess: ";
		std::getline(std::cin, Guess);
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWorldLength() << " letter word.\n";
			break;

		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			return Guess;
		}
	} while (Status != EGuessStatus::OK); // keep looping untill we get no errors 
	return Guess;
}
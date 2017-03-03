#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
std::string GetGuess();
void PlayGame();
bool AskToPlayAgain();
FBullCowGame BCGame; //instantiate a new game

// the entry point four our application
int main()
{
	std::cout << BCGame.GetMyCurrentTry();
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
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH;
	std::cout << " letter isogran I'm thinking of?\n";
	return;
}


void PlayGame()
{
	// repeat the guess back to them
	BCGame.Reset();
	constexpr int NUMBER_OF_TURNS = 5;
	// loop for the numbers of turns asking for guesses
	// TODO change from FOR to WHILE loop once we are validating tries
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		std::string Guess = GetGuess(); // TODO make loop checking valid
		// submit valid guess to the game
		// print number of bulls and cows
		std::cout << "Your guess was: " << Guess << std::endl;
	}

	// TODO summarise game 
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? ";
	std::string Response = "";
	std::getline(std::cin, Response);
	return Response[0] == 'y' || Response[0] == 'Y';
}


// get a guess from the player
std::string GetGuess()
{
	std::cout << "Enter your guess: ";
	std::string Guess = "";
	std::getline(std::cin, Guess);
	return Guess;
}
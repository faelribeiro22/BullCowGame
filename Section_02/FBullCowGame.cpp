#include "FBullCowGame.h"
#include <map>
#define TMap std::map

FBullCowGame::FBullCowGame()
{
	Reset();
}



void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "ant";

	MaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	setbWinGame(false);
	return;
}

int32 FBullCowGame::GetMaxTries() const
{
	return MaxTries;
}

int32 FBullCowGame::GetMyCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWorldLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return GetbWinGame();
}

bool FBullCowGame::GetbWinGame() const
{
	return bWinGame;
}

void FBullCowGame::setbWinGame(bool winGame)
{
	bWinGame = winGame;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{	
	if (!IsIsogram(Guess)) // if the guess isn't an isogran 
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess isn't all lowercase 
	{
		return EGuessStatus::Not_Lowercase; // TODO write function
	}
	else if (GetHiddenWorldLength() != Guess.length()) // if the guess length is wrong
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}
}

// received a VALID guess, increments turn, and returns count 
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;

	// loop through all letters in the guess 
	int32 WorldLength = MyHiddenWord.length(); // assuming same length as guess

	for (int32 MHWChar = 0; MHWChar < WorldLength; MHWChar++)
	{
		// compare letters agains the guess
		for (int32 GChar = 0; GChar < WorldLength; GChar++)
		{
			if (Guess[GChar] == MyHiddenWord[MHWChar]) { 	// if they match then
				if (MHWChar == GChar) {
					BullCowCount.Bulls++; // increment bulls
				}
				else {
					BullCowCount.Cows++; // increment cows
				}
			}
		}
		if (BullCowCount.Bulls == WorldLength) 
		{
			setbWinGame(true);
		}else 
		{
			setbWinGame(false);
		}
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{
	// treat 0 and 1 letter words as isograms

	// loop through all the letters of the word
		// if the letters is in  the map
			// we do NOT Isogram
		// otherwise
			// add the letter to the map as seen
	return true; // for example in cases where /0 is entered
}

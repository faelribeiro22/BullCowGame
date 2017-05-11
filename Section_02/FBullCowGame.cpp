#include "FBullCowGame.h"

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
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{	
	if (false) // if the guess isn't an isogran 
	{
		return EGuessStatus::Not_Isogram;
	}
	else if (false) // if the guess isn't all lowercase 
	{
		return EGuessStatus::Not_Lowercase;
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
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;
	// setup a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in the guess 
	int32 HiddenWorldLength = MyHiddenWord.length();
	int32 MyGuess = Guess.length();
	for (int32 MHWChar = 0; MHWChar < HiddenWorldLength; MHWChar++)
	{
		// compare letters agains the hidden word
		for (int32 GChar = 0; GChar < HiddenWorldLength; GChar++)
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
	}
	return BullCowCount;
}

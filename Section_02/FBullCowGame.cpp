#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
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

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
// received a VALID guess, increments turn, and returns count 
BullCowCount FBullCowGame::SubmitGuess(FString)
{
	// increment the turn number
	MyCurrentTry++;
	// setup a return variable
	BullCowCount BullCowCount;
	// loop through all letters in the guess 
		// compare letters agains the hidden word
	return BullCowCount;
}

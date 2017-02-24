#include "FBullCowGame.h"

void FBullCowGame::Reset()
{
}

int FBullCowGame::GetMaxTries() const
{
	return MaxTries;
}

int FBullCowGame::GetMyCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string)
{
	return false;
}

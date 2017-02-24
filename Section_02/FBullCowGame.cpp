#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	return;
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

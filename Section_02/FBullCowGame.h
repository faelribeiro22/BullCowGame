#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// all values initialised to zero
struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {

public:
	FBullCowGame(); // constructor
	void Reset(); //TODO make a more rich return value.
	int32 GetMaxTries() const;
	int32 GetMyCurrentTry() const;
	int32 GetHiddenWorldLength() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString) const; //TODO make a more rich return value.
	FBullCowCount SubmitGuess(FString);

// Please try and ignore this and focus on the interface above ^^
private:
	int32 MyCurrentTry;
	int32 MaxTries;
	FString MyHiddenWord;
};
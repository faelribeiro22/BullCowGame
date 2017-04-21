#pragma once
#include <string>

using FString = std::string;
using int32 = int;

class FBullCowGame {

public:
	FBullCowGame(); // constructor
	void Reset(); //TODO make a more rich return value.
	int32 GetMaxTries() const;
	int32 GetMyCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(FString); //TODO make a more rich return value.
	// provide a method for counting bulls & cows, and increassing turn # 

// Please try and ignore this and focus on the interface above ^^
private:
	int32 MyCurrentTry;
	int32 MaxTries;
};
#pragma once
#include <string>

class FBullCowGame {

public:
	FBullCowGame(); // constructor
	void Reset(); //TODO make a more rich return value.
	int GetMaxTries() const;
	int GetMyCurrentTry() const;
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string); //TODO make a more rich return value.

// Please try and ignore this and focus on the interface above ^^
private:
	int MyCurrentTry;
	int MaxTries;
};
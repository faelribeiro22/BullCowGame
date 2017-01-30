#include <iostream>
#include <string>

using namespace std;

void printIntro();
string getGuess();
void PlayGame();


// the entry point four our application
int main()
{
	printIntro();
	PlayGame();
	system("pause");

    return 0; //exit the application
}

// introduce the game
void printIntro()
{
	constexpr int WORLD_LENGTH = 9;
	cout << "Welcome to Bulls and Cows a fun word game.\n";
	cout << "Can you guess the " << WORLD_LENGTH;
	cout << " letter isogran I'm thinking of?\n";
	return;
}


void PlayGame()
{
	// repeat the guess back to them
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string guess = getGuess();
		cout << "Your guess was: " << guess << endl;
	}
}


// get a guess from the player
string getGuess()
{
	cout << "Enter your guess: ";
	string guess = "";
	getline(cin, guess);
	return guess;
}
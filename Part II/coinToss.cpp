/*
	Mary Taboada

	coinToss.cpp

	Simulate the tossing of a coin a certain number of times

	Input: Number of times the coin will be tossed

	Processing: 1. Prompt user for number of times the coin will be tossed (n)
				2. From 1 to n:
						Generate a random number (0 or 1)
							if 0 => Heads
							if 1 => Tails
				3. Display result

	Output: Simulated coin tosses (Heads/Tails) as many times as indicated
		    by the user
*/

// Header Files
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function Prototypes
int getN();
void tossCoin();

int main()
{
	// Variables
	int n;			// Number of times the coin will be tossed
	char tryAgain;	// 'y' if user wants to try again

	// Intro
	cout << "\nCoin Toss Simulator ..." << endl;

	// Seed random function
	srand(time(0));

	do
	{
		// Prompt user for number of times the coin will be tossed
		n = getN();

		// Simulate the coin toss n times
		for (int i = 1; i <= n; i++)
			tossCoin();

		// Check wheter to try again
		cout << "\nWould you like to try again (y/n)? ";
		cin >> tryAgain;

	} while (tolower(tryAgain) == 'y');

	return 0;
}

/*
	int getN()

	Prompt user for number of times the coin will be tossed (>0),
	and return it back to the caller.

	Return Value: Number of times the coin will be tossed. 

*/
int getN()
{
	int n;

	// Prompt user for number of time the coin will be tossed
	do
	{
		// Prompt
		cout << "\nHow many times will the coin be tossed (>0)? ";
		cin >> n;

		// Validate
		if (n < 1)
			cout << "Error ... Invalid number. Try again." << endl;
	} while (n < 1);

	return n;
}

/*
	void tossCoin()

	Simulates a coin toss & displays Heads/Tails

	Return Value: None
*/
void tossCoin()
{
	int toss;

	// Generate random toss (0 or 1)
	toss = rand() % 2;

	// Display toss
	if (toss == 0)
		cout << "\tHeads" << endl;
	else
		cout << "\tTails" << endl;

	return;
}
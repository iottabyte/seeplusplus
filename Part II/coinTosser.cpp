/*
*	Kim Claros
* 
*	coinTosser.cpp
* 
*	simulate the flipping of a cin a certain number of times
* 
*	i:	number of coin tosses
* 
*	p:	1 - prompt user for number of times coin will be tossed (n)
*		2 - from 1 to n:
*				generate a random number (0 or 1)
*				0 for heads, 1 for tails
*				display results
*	o:	a series of head/tails
*/

// header files
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function protos
int getN();
void tossCoin();

int main()
{
	// variables
	int n;			// number of tosses
	char tryAg;		// loop control variable (y/n)

	// intro
	cout << "\nCoin Toss Simulator" << endl;

	// seed random function
	srand(time(0));

	do
	{
		// prompt user for n
		n = getN();

		for (int i = 1; i <= n; i++)
			tossCoin();

		cout << "\nWould you like to try again? (y/n) ";
		cin >> tryAg;
	} while (tolower(tryAg) == 'y');

	return 0;
}

/*
	int getN()

	prompts user for number of coin tosses

	return val: n
*/
int getN()
{
	int n;

	do
	{
		cout << "\nHow many times will the coin be tossed (>0)? ";
		cin >> n;

		if (n <= 0)
			cout << "\nERROR: Invalid number. Try again.";
	} while (n <= 0);

	return n;
}

/*
	void tossCoin()
*/
void tossCoin()
{
	int toss;

	toss = rand() % 2;

	if (toss == 0)
		cout << "\tHeads" << endl;
	else
		cout << "\tTails" << endl;

	return;
}
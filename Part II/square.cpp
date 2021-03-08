/*
	Kim Claros

	square.cpp

	prompt user for the length of a square (1-10) and display it filled with stars

	i:	length of square (1-10)

	p:	1 - prompt user for length of the suare (1-10)
		2 - display square:
			one line at a time
				one star at a time

	o:	square filled with length x length stars
*/

// header files
#include <iostream>
using namespace std;

int main()
{
	// variables
	int length, row, star;

	// intro
	cout << "\nStarry Square Generator" << endl;	

	// validate value
	do
	{
		// input
		cout << "\nEnter the length of square (1-10): ";
		cin >> length;

		if (length < 1 || length > 10)
			cout << "\nERROR: Invalid length. Please enter a length within stated parameters." << endl;

	} while (length < 1 || length > 10);

	cout << endl;	// move to next line
	row = 1;		// initialize star counter

	// output
	while (row <= length)
	{
		star = 1;

		while (star <= length)
		{
			cout << "* ";	// display star
			star++;			// increment star counter
		}

		cout << endl;

		row++;				// increment row counter
	}

	return 0;
}
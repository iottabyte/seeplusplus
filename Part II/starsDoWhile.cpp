/*
	Kim Claros

	starsWhile.cpp

	use data input to display a line of specific quantity of stars

	I - length of line (>0)

	P - 1. Prompt user for length of the line (>0)
		2. Display the line filled with "length" stars (one star at a time)

	O - line made of stars
*/

// header files
#include <iostream>
using namespace std;

int main()
{
	// variables
	int length,
		count;

	// collection
	cout << "\nDraw a Line App" << endl;

	do
	{
		cout << "\nEnter length of line (>0): ";
		cin >> length;

		// validate input
		if (length <= 0)
			// display error
			cout << "\nERROR IL01: Invalid length. Please try again." << endl;
	} while (length <= 0);
	
	cout << endl;

	// display line of stars
	count = 1;		// initializa counter

	while (count <= length)	// test counter
	{
		cout << "* ";	// display star

		count++;		// update counter
	}
	cout << endl;

	return 0;
}
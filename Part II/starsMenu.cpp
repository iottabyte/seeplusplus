/*
	Kim Claros

	starsMenu.cpp

	Menu-driven interface program that allows the user to draw either a
	line, square, right traingle, or quit.

	i: user's choice of shape, as well as line length, square length, or triangle length

	p:	1 - display menu
		2 - prompt user for choice
		3 - drive menu options
			i. line
			ii. square
			iii. right triangle
			iv. quit

	o: a line, square, or right triangle made of stars
*/

// header files
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// constants and variables
	const int QUIT = 4;
	int choice;
	double length;

	// intro
	cout << "\nAsterisk Shape Maker!!" << endl;

	// menu interface
	do
	{
		// prompt user for choice
		cout << "\nChoose one of the following options..." << endl
			 << "\n\t1 - Draw a line." << endl
			 << "\t2 - Draw a square." << endl
			 << "\t3 - Draw a right triangle." << endl
			 << "\t4 - Quit." << endl
			 << "\nOption: ";
		cin >> choice;

		// drive menu options
		switch (choice)
		{
		case 1:		// line [INCOMPLETE]
			
			break;
		case 2:		// square [INCOMPLETE]
			;
			break;
		case 3:		// right triangle
			cout << "\nStarry Right Triangle..." << endl;

			do
			{
				cout << "\nEnter desired base/height of right triangle (> 0): ";
				cin >> length;
				cout << endl;

				if (length <= 0)	// validate non-negative
					cout << "ERROR: Invalid base/height. Enter a positive value." << endl;
			} while (length <= 0);

			// draw the triangle
			for (int line = 1; line <= length; line++)
			{
				for (int star = 1; star <= line; star++)
					cout << "* ";
				cout << endl;
			}

			break;
		case QUIT:
			cout << "\nFarewell traveler..." << endl << endl;
			break;
		default:	// error
			cout << "ERROR: Invalid option. Please try again." << endl;
		}
	} while (choice != QUIT);


	return 0;
}
/*

	Kim Claros

	highLow.cpp

	Menu driven interface program that allows the user to the the highest
	and lowest of three numbers.

	I - user's choice, three numbers
	P - 1. display menu
		2. prompt user for choice
		3. drive menu options: case 1-3
	O - based on user's choice, highest or lowest of three numbers
		or quit program

*/

// header files
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// constants and variables
	int choice;
	double uno, dos, tres, highn, lown;

	// intro
	cout << "\nHighest/Lowest App" << endl;
	cout << fixed << showpoint << setprecision(1);

	// display menu
	cout << "\nChoose one of the following options" << endl
		<< "\t1 - Get the highest of three numbers." << endl
		<< "\t2 - Get the lowest of three numbers." << endl
		<< "\t3 - Quit the program." << endl
		<< "Option: ";
	cin >> choice;

	// drive menu options
	switch (choice)
	{
		case 1: // highest
			cout << "\nEnter three numbers: ";
			cin >> uno >> dos >> tres;

			highn = uno; // determine highest value
			if (dos > highn)
				highn = dos;
			if (tres > highn)
				highn = tres;

			cout << "The highest value is " << highn << endl;

			break;
		case 2: // lowest
			cout << "\nEnter three numbers: ";
			cin >> uno >> dos >> tres;

			lown = uno;
			if (dos < lown)
				lown = dos;
			if (tres < lown)
				lown = tres;

			cout << "The lowest value is " << lown << endl;

			break;
		case 3: // quit
			cout << "\nGoodbye..." << endl << endl;
			break;
		default: // error
			cout << "ERROR 2A: Invalid Option. Please try again." << endl;
	}

	return 0;
}
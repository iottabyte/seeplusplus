/*
	Kim Claros

	days_ifElseIf.cpp

	prompt user for a number (1-7) and display the corresponding day of the week

	input: a number between 1 and 7

	processing: determine corresponding day of the week (Monday - Sunday)
				using the if-else-if form

	output: corresponding day of the week
*/

// header files
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	// variables
	int numbie;
	string day;

	// extraction
	cout << "\nDay Discovery App" << endl;

	cout << "\nPlease enter a number (1-7): ";
	cin >> numbie;

	// determination
	if (numbie == 1)
		day = "Monday";
	else if (numbie == 2)
		day = "Tuesday";
	else if (numbie == 3)
		day = "Wednesday";
	else if (numbie == 4)
		day = "Thursday";
	else if (numbie == 5)
		day = "Friday";
	else if (numbie == 6)
		day = "Saturday";
	else if (numbie == 7)
		day = "Sunday";
	else  // to handle numbers outside of range
	{
		cout << "ERROR - Invalid number. Try again." << endl;
		day = "";
	}

	// output
	if (!day.empty()) // equivalent to day != ""
		cout << "The day #" << numbie << " is " << day << "." << endl << endl;

	return 0;
}
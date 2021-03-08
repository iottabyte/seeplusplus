/*
	Kim Claros

	averageFive.cpp

	calculate and display the average of five user-given numbers

	i: five numbers

	p:  1 - initialize accumulator sum = 0
		2 - from 1 to 5: (one at a time)
			prompt user for number
			add number to sum
		3 - calculate average
			average = sum / 5.0
		4 - display average

	o: average of five numbers
*/

// header files
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	// constants and variables
	const int NUMBIES = 5;
	double numero, sum, average;

	// intro
	cout << "\n~ Average of Five ~ Application" << endl << endl;

	sum = 0.0;	// initialize accumulator

	// loop autogenerates prompt for each number
	for (int count = 1; count <= NUMBIES; count++)		// index of the loop
	{
		// prompt user
		cout << "\tNumber " << count << ": ";
		cin >> numero;

		sum += numero;		// add number to sum
	}

	// calculate and display

	average = sum / NUMBIES;
	cout << "\nThe average is "
		 << fixed << showpoint << setprecision(3)
		 << average << endl << endl;

	return 0;
}
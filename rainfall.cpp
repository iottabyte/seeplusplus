/*
	Kim Claros

	rainAvg.cpp

	given the amount of rain recorded for each of three months, calculate
	and display the average rainfall for the quarter

	input: name of each month in quarter, amount of rain (in inches) recorded for each month

	processing: 1 - collect user data: month names and corresponding rain recorded
				2 - calculate the average rainfall for the quarter
					avgRain - (rain1 + rain2 + rain3) / 3.0;
				3 - display average rainfall for the quarter

	output: average rainfall for the quarter
*/

// header files
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	// constants and variables
	const int YOO = 35;
	string month1, month2, month3;
	double rain1, rain2, rain3, avgRain;

	// intro
	cout << "\nAverage Quarterly Rainfall Calculator" << endl;

	// data collection
	cout << endl << setw(YOO) << left << "Enter name of 1st month:";
	getline(cin, month1);
	cout << setw(YOO) << left << "Enter rainfall for " + month1 + ":"; // concat operator needed so setw applies to string as well
	cin >> rain1;

	cout << endl << setw(YOO) << left << "Enter name of 2nd month:";
	cin.ignore(); // flushing input buffer
	getline(cin, month2);
	cout << setw(YOO) << left << "Enter rainfall for " + month2 + ":";
	cin >> rain2;

	cout << endl << setw(YOO) << left << "Enter name of 3rd month:";
	cin.ignore();
	getline(cin, month3);
	cout << setw(YOO) << left << "Enter rainfall for " + month3 + ":";
	cin >> rain3;

	// calculations
	avgRain = (rain1 + rain2 + rain3) / 3.0;

	// results
	cout << "\nThe average rainfall for " << month1 << ", " << month2 << ", and " << month3 << " is "
		<< fixed << showpoint << setprecision(3)
		<< avgRain << " inches." << endl << endl;

	return 0;
}
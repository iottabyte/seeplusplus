/*
	Kim Claros

	monthDays.cpp

	display the number of days for each month of the year
	(sample program) 
*/

// header files
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	const int MONTHS = 12;

	string monthNms[MONTHS] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun",
								"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	int daysMon[MONTHS] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	cout << "\nDays per Month App" << endl;

	// display number of days per month
	cout << setw(15) << left << "\nMonth" << "Days" << endl << endl;
		for (int i = 0; i < MONTHS; i++)
			cout << setw(15) << left << monthNms[i] << daysMon[i] << endl;

	return 0;
}
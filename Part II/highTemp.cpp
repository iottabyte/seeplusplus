/*
	Kim Claros

	hiTemp.cpp

	given the highest temperatures recorded during a year,
	a menu-driven interface program that allows the user to
	view data in several different ways

	i:	a file containing the highest daily temperatures for 
		a year (52 weeks / 7 days)

	p:	1 - read highest temperatures into a 2-dimensional array (52 x 7)
		2 - display menu and prompt user for choice
		3 - drive menu options
			i.	display hgihest temperature for a week/day
				RANDOM ACCESS
			ii.	display the average highest temperature for a week
				ROW PROCESSING
			iii.display the average highest temperature for a day
				COLUMN PROCESSING
			iv.	display the average highest temperature for a year
				ARRAY PROCESSING
			v.	quit

	o:	highest temperature on a a particular week/day
		average highest temperature for a:
		- week (1-52)
		- day (1: Monday - 7: Sunday)
		- year
*/

// header files
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// global constants
const int WEEKS = 52;
const int DAYS = 7;
const string dName[] = { "Monday", "Tuesday", "Wednesday", "Thursday",
						"Friday", "Saturday", "Sunday" };

// function prototypes
void readTemp(int[][DAYS]);
int getWeek();
int getDay();
double calcAvgD(int[][DAYS], int);
double calcAvgW(int[][DAYS], int);
double calcAvgY(int[][DAYS]);

int main()
{
	const int QUIT = 5;
	int choice, weekIdx, dayIdx;
	double average;
	int hiTemp[WEEKS][DAYS];

	cout << "\nHigh Temp Yearly Reporting App" << endl;	// intro
	cout << fixed << noshowpoint << setprecision(0);	// set formatting

	readTemp(hiTemp);		// read highest temperatures for a year
	
	// menu
	do
	{
		// display menu and prompt for choice
		cout << "\nChoose one of the following options to display..." << endl
			<< "\t1 - Highest temperature on a specific day" << endl
			<< "\t2 - Average highest temperature for a week" << endl
			<< "\t3 - Average highest temperature for a day" << endl
			<< "\t4 - Average highest temperature for a year" << endl
			<< "\t5 - Quit" << endl
			<< "\nOption: ";
		cin >> choice;

		// drive menu
		switch (choice)
		{
		case 1:	// temp on a day
			cout << "\nHighest temperature on a certain day..." << endl;

			// prompt user
			weekIdx = getWeek();
			dayIdx = getDay();

			cout << "The highest temperature was " << hiTemp[weekIdx][dayIdx] << endl;

			break;
		case 2:	// avg for week
			cout << "\nAverage highest temperature for a week..." << endl;

			// calculate average and display
			average = calcAvgW(hiTemp, dayIdx);
			cout << "\nThe average highest temperature for each week was " << average << endl;
				
			break;
		case 3:	// avg for day
			cout << "\nAverage highest temperature for a day..." << endl;

			dayIdx = getDay();		// prompt user

			// calculate average and display
			average = calcAvgD(hiTemp, dayIdx);
			cout << "\nThe average highest temperature for " << dName[dayIdx] << " was " << average << endl;

			break;
		case 4:	// avg for year
			cout << "\nAverage highest temperature for the year..." << endl;

			// calculate and display
			average = calcAvgY(hiTemp);
			cout << "\nThe average highest temperature for the year was " << average << endl;

			break;
		case QUIT:
			cout << "\nGoodbye...\n" << endl;
			break;
		default:
			cout << "\nERROR: Invalid selection. Please try again." << endl;
		}

	} while (choice != QUIT);

	return 0;
}

/*

*/
void readTemp(int arr[][DAYS])
{
	string filename;
	ifstream archiv;

	cout << "\nEnter name of data file: ";
	getline(cin, filename);

	archiv.open(filename);		// open file
	if (!archiv)
	{
		cout << "\nFatal Error...could not open " << filename << endl;
		exit(EXIT_FAILURE);
	}

	// read file content into array
	for (int week = 0; week < WEEKS; week++)
		for (int day = 0; day < DAYS; day++)
			archiv >> arr[week][day];

	archiv.close();				// close file
}

/*

*/
int getWeek()
{
	int wIdx;

	do
	{
		cout << "\nEnter a week (1-52): ";
		cin >> wIdx;

		if (wIdx < 1 || wIdx > 52)
			cout << "ERROR: Invalid week. Try again." << endl;
	} while (wIdx < 1 || wIdx > 52);

	return wIdx;
}

/*

*/
int getDay()
{
	int dIdx;

	do
	{
		cout << "\nEnter a weekday (1: Monday - 7: Sunday): ";
		cin >> dIdx;

		if (dIdx < 1 || dIdx > 7)
			cout << "ERROR: Invalid entry. Try again." << endl;
	} while (dIdx < 1 || dIdx > 7);

	return dIdx;
}

double calcAvgD(int arr[][DAYS], int day)
{
	double average;
	int sumTemps = 0;

	for (int week = 0; week < WEEKS; week++)
		sumTemps += arr[week][day];

	average = static_cast <double> (sumTemps) / WEEKS;

	return average;
}

double calcAvgY(int arr[][DAYS])
{
	double average;
	int sumTemps = 0;

	for (int week = 0; week < WEEKS; week++)
		for (int day = 0; day < DAYS; day++)
			sumTemps += arr[week][day];

	average = static_cast <double> (sumTemps) / (WEEKS * DAYS);

	return average;
}

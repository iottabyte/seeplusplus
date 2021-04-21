/*
	Kim Claros

	corpSales.cpp

	database management system that keeps track of quarterly, annual, and average
	sales for a coorporation that has four divisions (north, west, sout, east)

	i:	quarterly sales per division

	p:	1 - prompt user for quarterly sales per division
		2 - calculate annual and average sales per division
		3 - display sales report

	o:	report showing each division's annual and average sales
*/

// header files
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// user-defined data types
struct qSales
{
	double q1sales;
	double q2sales;
	double q3sales;
	double q4sales;
};

struct divSales
{
	string divName;			// name of division
	qSales divQSales;		// division sales per quarter
	double annSales;		// annual sales
	double average;			// average quarterly sales
};

const int DIV = 4;			// global constant (also functions as QUARTERS)

// function protos
void getQSales(divSales&);
double getSales(string);
void calcAAsales(divSales&);
void display(divSales);

int main()
{
	// variables
	divSales corpDiv[DIV] = { {"North"}, {"South"}, {"East"}, {"West"} };

	cout << "\nCorporate Sales Management System" << endl;		// intro

	// prompt user for data
	for (int d = 0; d < DIV; d++)
		getQSales(corpDiv[d]);

	// calculate, update, and display
	cout << "\nSales Report" << endl;
	for (int d = 0; d < DIV; d++)
	{
		calcAAsales(corpDiv[d]);
		display(corpDiv[d]);
	}

	return 0;
}

/*
	loops getSales for each division
*/
void getQSales(divSales &div)		// ref parameter bc we want to UPDATE the record
{
	double qsales;

	cout << "\nEnter Sales for " << div.divName << " Division" << endl;

	for (int q = 1; q <= DIV; q++)
	{
		switch (q)
		{
			case 1: 
				qsales = getSales("First");
				div.divQSales.q1sales = qsales;
				break;
			case 2:
				qsales = getSales("Second");
				div.divQSales.q2sales = qsales;
				break;
			case 3:
				qsales = getSales("Third");
				div.divQSales.q3sales = qsales;
				break;
			case 4:
				qsales = getSales("Fourth");
				div.divQSales.q4sales = qsales;
				break;
		}
	}

	return;
}

/*
	prompts user for sales in each quarter and
	feeds it to getQSales

	return val: sales 
*/
double getSales(string quarter)
{
	double sales;

	// prompt for sales
	do
	{
		cout << "\t" << quarter << " Quarter Sales: ";
		cin >> sales;

		if (sales < 0)
			cout << "\nERROR: Invalid sales. Try again." << endl;

	} while (sales < 0);
	
	return sales;

}

/*
	calculates annual sales and average sales for
	each division
*/
void calcAAsales(divSales& div)
{
	div.annSales = div.divQSales.q1sales + div.divQSales.q2sales
					+ div.divQSales.q3sales + div.divQSales.q4sales;

	div.average = div.annSales / DIV;

	return;
}

/*
	displays report of annual and average sales
	for each division
*/
void display(divSales div)
{
	cout << "\n" << div.divName << " Sales" << endl
		<< fixed << showpoint << setprecision(2)
		<< setw(15) << left << "Annual:" << '$' << div.annSales << endl
		<< setw(15) << left << "Average:" << '$' << div.average << endl;

	return;
}
/*
	Kim Claros

	paintEstimator.cpp

	A program that calculates the needed materials and expenses
	of a paint job using user input.

	I:	price per gallon of paint (>=0), number of rooms being painted (>0),
		square footage of each room (>=25)

	P:	1 -	prompt user for price of paint, rooms to be painted, and 
			square feet of wall space in each room
		2 -	calculate gallons of paint needed and cost, hours of labor
			needed and cost
				initialize HRS = 8.0, LABOR = 25.0
				totGals = ceil(space / 110.0);
				totHrs = totGals * HRS;
				totGalCost = priceGal * totGals;
				totHrsCost = totHrs * LABOR;
				final = totHrsCost + totGalCost;

	O:	gallons of paint required, hours of labor required, cost of labor,
		cost of paint, and total cost of job
*/

// header files
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// function prototypes
double priceGal();
int roomTings(int);
void calcAll(int, double, double&, double&);

int main()
{
	// constants and variables
	int roomNum, wallspace;
	double galPrice, labor = 25.0, hrs = 8.0;

	// intro
	cout << "\n\tPaint Job Estimator"
		<< "\n------------------------------------" << endl;

	galPrice = priceGal();		// get price of paint

	// get number of rooms
	do
	{
		cout << "\nNumber of rooms to be painted: ";
		cin >> roomNum;

		if (roomNum < 1)
			cout << "\nERROR: Invalid number of rooms. Please try again." << endl;

	} while (roomNum < 1);

	// get square feet of space
	wallspace = roomTings(roomNum);

	// calculate and display estimate
	calcAll(wallspace, galPrice, labor, hrs);

	return 0;
}

/*
	double priceGal()

	prompts user for price of paint per gallon
	(0 <=) and returns to caller

	return val: price
*/
double priceGal()
{
	double price;

	do
	{
		cout << "\nEnter price of paint per gallon: ";
		cin >> price;

		if (price <= 0)
			cout << "\nInvalid entry: price must be greater than zero. Try again." << endl;

	} while (price <= 0);

	return price;
}

/*
	int roomTings(int&)

	prompt user for number of rooms (>0) and
	square feet of wall space (>=25) in each room

	return val: wall space
*/
int roomTings(int rooms)
{
	int walls = 0;		// square footage of walls

	cout << "\nEnter square feet of of wall space (>=25 ft.)" << endl;

	for (int i = 0; i < rooms; i++)
	{
		cout << "\tRoom " << (i + 1) << ": ";
		cin >> walls;
			
		while (walls < 25)		// validate wall space
		{
			cout << "\nERROR: Square footage must be greater than 25. Try again: ";
			cin >> walls;
		}
	}

	return walls;
}


/*
	void calcAll(int space, double price, int& gal, double& cost)

	calculates cost of labor and paint and displays them

	return val: none
*/
void calcAll(int space, double priceGal, double& labor, double& hrs)
{
	double totGals, totHrs, totGalCost, totHrsCost, final;

	// calculations
	totGals = ceil(space / 110.0);
	totHrs = totGals * hrs;
	totGalCost = priceGal * totGals;
	totHrsCost = totHrs * labor;
	final = totHrsCost + totGalCost;

	// display
	cout << "\n\tPaint Job Estimate" << endl
		<< "----------------------------------" << endl
		<< "\nMaterials..." << endl
		<< "gallons of paint needed:" << setw(13) << right << totGals << endl
		<< "cost of required paint:" << fixed << showpoint << setprecision(2)
		<< setw(10) << right << "$ " << totGalCost << endl;

	cout << "\nLabor..." << endl
		<< "hours of labor needed:" << setw(13) << right << totHrs << endl
		<< "cost of labor required:" << setw(10) << right << "$ " << totHrsCost << endl
		<< setw(40) << right << "---------" << endl
		<< "\nTotal Cost:" << setw(23) << right << "$ " << final << endl;

	return;
}

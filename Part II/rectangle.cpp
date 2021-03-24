/*
	Kim Claros

	rectangle.cpp

	prompt user for width/height of a rectable, calculate its area, 
	and display the result

	i:	rectangle's width & height

	p:	1 - prompt user for rectangle width and height
		2 - calculate area: area = width * height
		3 - display result (2 decimal places)

	o:	rectangle's area
*/

// header files
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// function prototypes
double calcRecArea(double, double);
void dispRecArea(double, double, double);

int main()
{
	// varaibles
	double width, height, area;

	// prompting and gathering
	cout << "\nRectangle Area Calculator" << endl;

	// calculate area
	area = calcRecArea(width, height);

	// display result
	dispRecArea(width, height, area);
	
	return 0;
}

/*
	double calcRecArea(double w, double h)

	given the width (w) and height (h) of a rectangle
	calculates its area and returns it back to the caller

	return value: rectangle's area
*/
double calcRecArea(double w, double h)
{
	double area;

	// calculate area
	area = w * h;

	return area;
}

/*
	void dispRecArea(double w, double h, double a)

	given the width (w) and height (h) of a square/rectangle,
	disply its area (a)

	return value: none
*/
void dispRecArea(double w, double h, double a)
{
	string shape;

	// determine shape
	if (w == h)
		shape = "square";
	else
		shape = "rectangle";

	// display message
	cout << "\nThe are of a " << w << " by " << h
		<< " " << shape << " is " << fixed << showpoint
		<< setprecision(3) << a << endl;

	return;		// not necessary, just a formality
}

/*
	Kim Claros
	
	rectangle.cpp
	
	Prompt user for the dimensions of a rectangle,
	calculate its area, and then display the result
	
*/

//Header Files
#include <iostream>
using namespace std;

int main()
{
	//variables
	double width, height, area;

	//intro
	cout << "Welcome to the Marvelous Rectangle Area Calculator..." << endl << endl;

	//prompt user for width and height
	cout << "Please enter the rectangle's width: ";
	cin >> width;
	cout << "Enter the rectangle's height: ";
	cin >> height;

	//calcualte area
	area = width * height;

	//display result
	cout << "The area is " << area << "." << endl;

	return 0;

}
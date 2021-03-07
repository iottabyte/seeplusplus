/*
	Kim Claros	

	volumeCalculator.cpp

	A program that allows users to select and calculate the volume of
	five different types of 3-D figures.

	Input:		A number 1 - 6 for initial choice, then figure dimensions.
				(length, height, width/base length, radius)
 
	Processing:   i - Initialize constant PI = 3.14159
				 ii - Display menu
				iii - Drive menu options: case 1-6
				 iv - Prompt user for figure dimensions
				  v - Check for negative values
				 vi - calculate figure volume
					1. rec prism - volume = length * width * height
					2. tri prism - volume = (width * height * length) / 2.0
					3. cylinder - volume = PI * height * (pow(radius, 2.0))
					4. pyramid - volume = (width * height * length) / 3.0
					5. cone - volume = (PI * height * pow(radius, 2.0)) / 3.0
					6. quit program

	Output:		Selected figure's volume or goodbye message.
*/

// header files
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	// constants and variables
	const double PI = 3.14159;
	int choice;
	double volume, length, width, height, radius;

	// intro
	cout << "\n~ Volume Calculator Application ~" << endl;
	cout << fixed << showpoint << setprecision(5);

	// serve up the menu
	cout << "\nCalculate the volume of which figure?" << endl
		 << "\n\t1 - Rectangular Prism" << endl
		 << "\t2 - Triangular Prism" << endl
		 << "\t3 - Cylinder" << endl
		 << "\t4 - Pyramid" << endl
		 << "\t5 - Cone" << endl
		 << "\t6 - None. Quit Program!" << endl
		 << "\n\tOption (1 - 6): ";
	cin >> choice;

	// the meat and potatoes
	switch (choice)
	{
		case 1: // rectangular
			cout << "\n~ Rectangular Prism..." << endl
				 << "\nEnter the prism's length, width, and height: ";
			cin >> length >> width >> height;
			if (length > 0 && width > 0 && height > 0)
			{
				volume = length * width * height;
				cout << "\nThe volume is: " << volume << endl;
			}
				else
				{
					cout << "\nPlease enter non-negative dimensions.";
				}
			break;

		case 2: // triangular
			cout << "\n~ Triangular Prism..." << endl
				 << "\nEnter the prism's length, traingle base, and height: ";
			cin >> length >> width >> height; // b = w in this case
			if (width > 0 && height > 0 && length > 0)
			{
				volume = (width * height * length) / 2.0;
				cout << "\nThe volume is: " << volume << endl;
			}
				else
				{
					cout << "\nPlease enter non-negative dimensions.";
				}
			break;

		case 3: // cylinder
			cout << "\n~ Cylinder..." << endl
				<< "\nEnter the cylinder's radius and height: ";
			cin >> radius >> height;
			if (radius > 0 && height > 0)
			{
				volume = (PI * height) * (pow(radius, 2.0));
				cout << "\nThe volume is: " << volume << endl;
			}
				else
				{
					cout << "\nPlease enter non-negative dimensions.";
				}
			break;

		case 4: // pyramid
			cout << "\n~ Pyramid..." << endl
				 << "\nEnter the pyramid's length, width, and height: ";
			cin >> length >> width >> height;
			if (width > 0 && height > 0 && length > 0)
			{
				volume = (width * height * length) / 3.0;
				cout << "\nThe volume is: " << volume << endl;
			}
				else
				{
					cout << "\nPlease enter non-negative dimensions.";
				}
			break;

		case 5: // cone
			cout << "\n~ Cone-ulator..." << endl
				 << "\nEnter the cone's height and base radius: ";
			cin >> height >> radius;
			if (height > 0 && radius > 0)
			{
				volume = (PI * height * pow(radius, 2.0)) / 3.0;
				cout << "\nThe volume is: " << volume << endl;
			}
				else
				{
					cout << "\nPlease enter non-negative dimensions.";
				}
			break;

		case 6: // quit
			cout << "\nGoodbye..." << endl << endl;
			break;

	default: // bad user!! >:C
		cout << "ERROR: Option is outside valid parameters! Please try again." << endl;
		break;
	}


	return 0;
}
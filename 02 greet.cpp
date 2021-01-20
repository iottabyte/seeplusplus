/*
	Kim Claros

	greet.cpp

	Prompt the user for their name and display a greeting message

*/

//Header Files
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//variable declaration
	string name;

	//prompt user for their name
	cout << "please enter ya name (no spaces!): ";
	cin >> name;

	//display greeting message
	cout << "Hello " << name << "!!!" << endl;

	return 0;
}
/*
	Kim Claros

	numArray.cpp

	a number analysis program that prompts user for the name of a file
	and reads the values in the file into an array and display in a report

	i:	name of file containing numbers (numbers.txt)

	p:	1 - read values from a file into array
		2 - list content of the arry
		3 - determine and display
				lowest value, highest value
		4 - calculate and display the average of all values

	o:	list of values, highest and lowest numbers, average
*/

// header files
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// function prototypes
void readValues(int[], int&);
void dispValues(int[], int);
int getLow(int[], int);
int getHigh(int[], int);
double calcAvg(int[], int);

int main()
{
	// constants and variables
	const int SIZE = 50;		// max num of values array can hold
	int values[SIZE];			// the array
	int size;					// effective size: actual #'s read

	// intro
	cout << "\nNumber Analysis App" << endl;

	// read values into array
	readValues(values, size);

	// display content of array
	dispValues(values, size);	// list

	cout << "\nThe lowest value is: " << getLow(values, size) << endl;	// lowest value
	cout << "The highest value is: " << getHigh(values, size) << endl;	// highest value

	cout << "\nThe average of all the values is: " << fixed << showpoint << setprecision(1)
		 << calcAvg(values, size) << endl;								// average

	return 0;
}

/*
	void readValues(int arr[], int size)

	prompts user for file name and reads values from file
	into an array

	return val: none, but returns thru ref parameter size
*/
void readValues(int arr[], int& size)
{
	string filename;
	ifstream inFile;

	cout << "\nEnter name of file: ";
	getline(cin, filename);

	inFile.open(filename);		// open file

	if (!inFile)
	{
		cout << "\nFatal Error! Could not open " << filename << endl;
		exit(EXIT_FAILURE);
	}

	size = 0;
	while (inFile >> arr[size])
		size++;

	inFile.close();				// close file
}

/*
	void dispValues(int arr[], int siza)

	reads and displays values found in document
	array arr[]

	return val: none
*/
void dispValues(int arr[], int size)
{
	cout << "\nList of Values:" << endl;	// heading

	// display array content - one item at a time
	for (int i = 0; i < size; i++)
		cout << "\t" << arr[i] << endl;

	return;
}

/*
	int getLow(int arr[], int size)

	determine the lowest value in the array arr[], considering
	the first "size" elements

	return val: lowest of values
*/
int getLow(int arr[], int size)
{
	int low = INT_MAX;

	for (int i = 0; i < size; i++)
		if (arr[i] < low)
			low = arr[i];

	return low;
}

/*
	int getHigh(int arr[], int size)

	determine the lowest value in the array arr[], considering
	the first "size" elements

	return val: highest of values
*/
int getHigh(int arr[], int size)
{
	int high = INT_MIN;

	for (int i = 0; i < size; i++)
		if (arr[i] > high)
			high = arr[i];

	return high;
}

/*
	double calcAvg(int arr[], int size)

	calcualte the average of the first "size" values in the
	array arr[]

	return val: average of values
*/
double calcAvg(int arr[], int size)
{
	double average;
	int sum = 0;

	for (int i = 0; i < size; i++)
		sum += arr[i];
	
	average = static_cast <double> (sum) / size;

	return average;
}
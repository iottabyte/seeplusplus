/*
	Kim Claros

	LoShuSquare.cpp

	A program that determines whether an array made of user input values
	makes a Lo Shu magic square.

	i:	numbers (1 - 9) in any order

	p:	1 - prompt user for values 1 thru 9 in any order
		2 - check whether all sums meet requirements
				sum of each row == 15
				sum of each column == 15
				sum of each diagonal (there's 2) == 15
		3 - display user's square
		4 - print message
				numbers DO make Lo Shu magic square
				numbers do NOT make Lo Shu magic square

	o:	square made of user's numbers and determination of meeting
		Lo Shu magic square requirements
*/

// header files
#include <iostream>
using namespace std;

// global constants
const int LOSHU = 3;

// function protos
int count(int[][LOSHU], int);
bool noRepeats(int[][LOSHU]);
int checkRow(int[][LOSHU]);
int checkCol(int[][LOSHU]);
bool checkDiag(int[][LOSHU]);
void dispSquare(int[][LOSHU]);
bool judgement(int, int, int);

int main()
{
	// variables and constants
	int square[LOSHU][LOSHU];
	int colSum, rowSum, diag;
	bool unique;

	cout << "\nLo Shu Magic Square Creator" << endl;	// intro

	// collect numbers from user
	cout << "\nEnter numbers 1-9 in a random order:" << endl
		<< "(Either separate each value with a space or an enter)\n" << endl;
	
	do
	{
		for (int row = 0; row < LOSHU; row++)
		{
			for (int col = 0; col < LOSHU; col++)
			{
				cin >> square[row][col];
			}
		}
		// validate input is within range
		for (int row = 0; row < LOSHU; row++) {
			for (int col = 0; col < LOSHU; col++) {
				if (square[row][col] < 1 || square[row][col] > 9)
					cout << "\nERROR: Please only enter values from 1 - 9.\nTry again." << endl;
			}
		}
		// validate input has no repeats
		unique = noRepeats(square);
		if (unique != true)
		{
			cout << "\nError: Please use each value only ONCE.\nTry again: " << endl;
		}
		else
			break;

	} while (unique != true);

	cout << endl;			// move to next line so it's **pretty**
	dispSquare(square);		// display the square

	// get sums for judgement
	colSum = checkCol(square);
	rowSum = checkRow(square);
	checkDiag(square);		
	if (checkDiag)
		diag = 0;
	else
		diag = 1;

	judgement(colSum, rowSum, diag);		// determine if it's Magic or not

	// display final determination
	if (judgement(colSum, rowSum, diag))
		cout << "\nThis a Lo Shu magic square!" << endl;
	else 
		cout << "\nYour square is NOT magical..." << endl;

	return 0;
}

/*
	int count(arr[][LOSHU], int n)

	needed for bool noRepeats!
	i THINK i could have done this all in one void
	function with a boolean variable instead of a
	boolean function...but i couldn't get it to work...
	 
	return val: result
*/
int count(int arr[][LOSHU], int n) 
{
	int index = 0;

	for (int row = 0; row < LOSHU; row++) {
		for (int col = 0; col < LOSHU; col++) {
			if (arr[row][col] == n)
				index++;
		}
	}
	return index;
}

/*
	bool noRepeats(int arr[][LOSHU])

	checks the array for repeating numbers
	after sorting from int count()

	return val: true if all numbers are unique
				false if any number repeats
*/
bool noRepeats(int arr[][LOSHU])
{
	for (int row = 0; row < LOSHU; row++) {
		for (int col = 0; col < LOSHU; col++) 
		{
			if (count(arr, arr[row][col]) > 1)
				return false;
		}
	}
	return true;
}

/*
	int checkRow(int arr[][LOSHU])

	return val: sum of each row
*/
int checkRow(int arr[][LOSHU])
{
	int sum;

	for (int row = 0; row < LOSHU; row++)
	{
		sum = 0;

		for (int col = 0; col < LOSHU; col++)
			sum += arr[row][col];

		// cout << "sum for row " << (row + 1) << " = " << sum << endl;
	}
	return sum;
}

/*
	int checkCol(int arr[][LOSHU])

	return val: sum of each column
*/
int checkCol(int arr[][LOSHU])
{
	int sum;

	for (int col = 0; col < LOSHU; col++)
	{
		sum = 0;

		for (int row = 0; row < LOSHU; row++)
			sum += arr[row][col];

		// cout << "sum for col " << (col + 1) << " = " << sum << endl;
	}
	return sum;
}

/*
	bool checkDiag(int arr[][LOSHU])

	checks if the sum of the numbers in the two
	diagonal lines of the square are equal to 15

	return val: true if both diagonals equal 15,
				or false if one or both do not
*/
bool checkDiag(int arr[][LOSHU])
{
	int sumBottom = 0, sumUpper = 0;
	int k = LOSHU - 1;

	// sum in downward diagonal (towards right)
	for (int b = 0; b < LOSHU; b++)
		sumBottom += arr[b][b];
	
	// sum in upwards diagonal (towards right)
	for (int i = 0; i < LOSHU; i++, k--)
		sumUpper += arr[k][i];

	if (sumBottom == sumUpper && sumBottom == 15)
		return true;
	else
		return false;
}

/*
	bool judgement(int col, int row, int diag)

	compares all Lo Shu determinations

	return val: true if values meet all requisites
				false is any value does not
*/
bool judgement(int col, int row, int diag)
{ 
	if (col == 15 && row == 15 && diag == 0)
		return true;
	else
		return false;
}	

/*
	void dispSquare(int arr[][LOSHU]

	displays the square array made of user input
*/
void dispSquare(int arr[][LOSHU])
{
	for (int row = 0; row < LOSHU; row++)
	{
		for (int col = 0; col < LOSHU; col++) 
			cout << arr[row][col] << " ";		// show 1 row
		
		cout << endl;							// show next row
	}
	return;
}

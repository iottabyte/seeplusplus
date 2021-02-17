/*
	Kim Claros

	loanCalculator.cpp

	Given a loan amount, interest rate, and length of term, generate
	a report of payment breakdown and total.

	Input: name, institution, loan amount, annual interest rate, term length, date

	Processing: 1 - Prompt user for loan info

	Output:
*/

// header files
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	// variables
	string bName, institute, date;
	int lTerm, payNum;
	double loanAmt, aiRate, miRate, numer,
		   denom, payMon, payTot, intTot;

	// intro
	cout << "\nLoan Calculator" << endl
		 << "Please enter the following information:\n";

	// prompting and collection
	cout << "Borrower's Name:\t";
	getline(cin, bName); 
	cout << "\n\nLoaning Instititution:\t";
	getline(cin, institute);
	cout << "\nLoan Amount ($)\t";
	cin >> loanAmt;
	cout << "\nAnnual Interest Rate (%):\t";
	cin >> aiRate;
	cout << "\nTerm of Loan (years):";
	cin >> lTerm;
	cout << "\n\nDate of Report:\t";
	getline(cin, date);

	// calculations
	miRate = aiRate / 12;
	payNum = lTerm * 2;
	numer = miRate * (pow(miRate++, payNum));
	denom = pow((1 + miRate), miRate) - 1;
	payMon = (numer / denom) * loanAmt;
	payTot = payNum * payMon;
	intTot = aiRate * loanAmt;

	// output

	return 0;
}
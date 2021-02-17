/*
	Kim Claros

	loanCalculator.cpp

	Given a loan amount, interest rate, and length of term, generate
	a report of payment breakdown and total.

	Input:		name, institution, loan amount, annual interest rate, term length, date
				(bName, institute) (lTerm, payNum) (loanAmt, ann, mon, payMon, payTot, intTot)

	Processing: 1 - prompt user for loan info
				2 - calculate data for final report
					payNum = lTerm * 12
					payMon = monf * pow((1 + monf), payNum) / (pow((1 + monf), payNum) - 1) * loanAmt
					payTot = payNum * payMon
					intTot = payTot - loanAmt
				3 - display all information in a formatted report	
	
	Output:		loan payment summary report	
*/

// header files
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	// constants and variables
	string bName, institute, date;
	int lTerm, payNum;
	double loanAmt, ann, mon, monf,
		   payMon, payTot, intTot;
	const short int FML = 40, FM = 37, RW = 10;

	// intro
	cout << "\nLoan Calculator\n" << endl;
	
	// prompting and collection
	cout << "\nPlease enter the following information:" << endl << endl;
	cout << setw(FML) << left << "Borrower's Name:";
	getline(cin, bName); 
	cout << setw(FML) << left << "Loaning Institution:";
	getline(cin, institute);
	cout << setw(41) << left << "\nLoan Amount ($):";
	cin >> loanAmt;
	cout << setw(FML) << left << "Annual Interest Rate (%):";
	cin >> ann;
	cout << setw(FML) << left << "Term of Loan (years):";
	cin >> lTerm;
	cout << setw(41) << left << "\nDate of Report:";
	cin.ignore(); // flush buffer
	getline(cin, date);

	// calculations
	mon = ann / 12.0;
	monf = mon / 100;
	payNum = lTerm * 12;
	payMon = monf * pow((1 + monf), payNum) / (pow((1 + monf), payNum) - 1) * loanAmt;
	payTot = payNum * payMon;
	intTot = payTot - loanAmt;

	// output part i: the recap
	cout << "-----------------------------------------------------\n"
		 << "\nLoan Payment Summary Report" << endl << endl;
	cout << setw(FM) << left << institute 
		 << setw(RW) << right << bName << endl << endl
		 << setw(FM) << left << "Annual Interest Rate:" 
		 << setw(9) << right << ann << " %" << endl;

	// output part ii: the numbers
	cout << fixed << showpoint << setprecision(2);

	cout << setw(FM) << left << "Loan Amount:" << "$" 
		 << setw(RW) << right <<loanAmt << endl
		 << setw(FM) << left << "Monthly Interest Rate:" 
		 << setw(9) << right << mon << " %" << endl
		 << setw(FM) << left << "Number of Payments:"
		 << setw(11) << right << payNum << endl
		 << setw(FM) << left << "Monthly Payment:" << "$" 
		 << setw(RW) << right << payMon << endl << endl;

	cout << setw(FM) << left << "Total Amount to Pay:" << "$"
		 << setw(RW) << right << payTot << endl
		 << setw(FM) << left << "Total Interest:" << "$"
		 << setw(RW) << right << intTot << endl;

	return 0;
}
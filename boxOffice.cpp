/*
    Kim Claros

    boxOffice.cpp

    input:
    processing:
    output:

*/

// header files
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{

    // constants and variables
    const double AD_PRICE = 14.0, CH_PRICE = 10.0, BOX_PERC = 0.2;
    string film, company;
    int a_tick, c_tick;
    double gProfit, nProfit, distAmt;

    // intro
    cout << "\nBox Office Earnings Calculator!" << endl;

    // extract data
    cout << "\nPlease enter the following data..." << endl
         << "\tName of film: ";
    getline(cin, film); // because the title could have spaces, can't use cin
    cout << "\tAdult tickets sold: ";
    cin >> a_tick;
    cout << "\tChild tickets sold: ";
    cin >> c_tick;
    cout < "\tProduction Company: ";
    cin.ignore(); // flushing cin stream to extract strings again
    getline(cin, company);

    // calculations
    gProfit = (AD_PRICE * a_tick) + (CH_PRICE = c_tick); 
    nProfit = gProfit * BOX_PERC / 100.0;
    distAmt = gProfit - nProfit;
    
    // display result
    cout << endl << setw(30) << left << "Film Name: " << "\"" << film << "\"" << endl
        << setw(30) << left << "Production Company: " << company << endl
        << setw(30) << left << "Adult Tickets Sold: " << a_tick << endl
        << setw(30) << left << "Child Tickets Sold: " << c_tick << endl
        << fixed << showpoint << setprecision(2)
        << setw(30) << left << "Gross Box Office Profit: " << "$ " << gProfit << endl
        << setw(30) << left << "Net Box Office Profit: " << "$ " << nProfit << endl
        << setw(30) << left << "Amount Paid to Distributor: " << "$ " << distAmt << endl;

    return 0;
}
/*
    Kim Claros

    boxOffice.cpp

    input:
    processing:
    output:

*/

// header files
#include <iostream>
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
    


    return 0;
}
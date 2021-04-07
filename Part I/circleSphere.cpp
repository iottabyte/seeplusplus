/*
    Kim Claros

    circleSphere.cpp

    given the diameter of a figure, calculate the circumference,
    area, volume, and surface area of a sphere

    input: diameter of figure, PI = 3.141592

    processing: 1 - prompt user for diameter
                2 - calculate radius
                3 - calculate circumference and area
                4 - calculate volume and surface area
                5 - display results to 4 decimal places

    output: circumference and area of the corresponding circle,
            volume and surface area of the corresponding sphere
*/

// header files
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    // constants and variables
    const double PI = 3.141592
    double radius, diam, circum, area, volume, surfArea;
    
    // intro and data collection
    cout << "\nGeometry Calculator" << endl;
    cout << "\nPlease enter the diameter of the figure: ";
    cin >> diam; 

    // calculations
    radius = diam / 2.0;
    circum = 2.0 * PI * radius;
    area = PI * pow(radius, 2.0);
    volume = (4/3) * PI * pow(radius, 3.0);
    surfArea = 4 * PI * pow(radius, 2.0);

    // formatting constants
    const int LW = 30, RW = 10;     // left & right field widths

    // display results
    cout << fixed << showpoint << setprecision(4)

    cout << setw(LW) << left << "Circumference of circle:"
         << setw(RW) << right << circum << endl
         << setw(LW) << left << "Area of circle:"
         << setw(RW) << right << area << endl
         << setw(LW) << left << "Volume of Sphere:"
         << setw(RW) << right << volume << endl
         << setw(LW) << left << "Surface Area of Sphere:"
         << setw(RW) << right << surfArea << endl << endl;

    return 0;
}

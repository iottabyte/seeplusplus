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
    double diam, radius, circum, area, volume, surfArea;
    
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

    // display results
    

    return 0;
}

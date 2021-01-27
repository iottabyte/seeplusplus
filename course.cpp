/*
    Kim Claros

    course.cpp

    produce a performance report of student grades using inputted user data

    input: course id, instructor name, number of students per each letter grade
    
    processing: 1 - prompt usser for course id and instructor name
                2 - create faculty id - first initial + last (both in lowercase)
                3 - prompt user for number of students per letter grade
                    (aStu, bStu, cStu, dStu, fStu)
                4 - calculate percent of student passing, in trouble, & failing
                    totalStu = aStu + bStu + cStu + dStu + fStu;
                    passingPerc = (aStu + bStu + cStu) / totalStu * 100.0;
                    probPerc = dStu / totalStu * 100.0;
                    failPerc = fStu / totalStu * 100.0;
                5 - display performance report

    output: course performance report

*/

// header files
#include <iostream>
#inlcude <string>
using namespace std;

int main()
{
    // variables
    string courseId, fname, lname, facId;
    int aStu, bStu, cStu, dStu, fStu, totalStu;
    double passPerc, probPerc, failPerc;
    string str;

    // intro
    cout << "\nCourse Analysis App" << endl;

    // user input: course id and instructor
    cout << "\nPlease enter the following data:" << endl;
        << "\tCourse ID: ";
    cin >> courseId;
    cout << "\tInstructor's first and last name (no spaces): ";
    cin >> fname >> lname;

    // create faculty id
    fname[0] = tolower(fname[0]);    // [0] : selecting first char of string
    lname[0] = tolower(lname[0]);   // tolower : converting to lowercase
    facId = fname[0] + lname;   // concatenate !!

    // prompt user for number of students per letter grade
    cout << "\n\tNumber of A Students: ";
    cin >> aStu;
    cout << "\t   \"    \" B students: ";
    cin >> bStu;
    cout << "\t   \"    \" C students: ";
    cin >> cStu;
    cout << "\t   \"    \" D students: ";
    cin >> dStu;
    cout << "\t   \"    \" F students: ";
    cin >> fStu;

    // calculate percentage of passing, probationary, and failing students
    totalStu = aStu + bStu + cStu + dStu + fStu;
    passPerc = (aStu + bStu + cStu) / static_cast <double> (totalStu) * 100.0;
    probPerc = dStu / static_cast <double> (totalStu) * 100.0;
    failPerc = fStu / static_cast <double> (totalStu) * 100.0;

    // display course performance report
    str.assign("----------------------------------------------------------------");
    cout << "\n" << str << endl
        << "Student Performance Report" << endl
        << "Course ID: " << courseId << "\t\tFaculty ID: " << endl << endl
        << "Percentage of students passing: " << "\t\t" << passPerc << "%" << endl
        << "                       in trouble: " << "\t\t" << probPerc << "%" << endl
        << "                       failing: " << "\t\t" << failPerc << "%" << endl

    return 0;
}

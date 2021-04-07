/*
    Bunthy Mak
    courseSummary.cpp
    Menu-driven interface program with two options:
        1. Process grades showing class score with highest scoring student, lowest scoring student, and class score average.
        2. Quit

    Input:  int userChoice will select option from menu.
            1. string fileName will read and display the data if it exists
            2. quit the program
    Processing:
        Option 1: Prompt the user for the name of file to store data.
            i.   <Course Number & Description>
            ii.  <Instructor Name>
            iii. <Term>
            iv.  Information for each student stored in two separate lines
                a. First line indicates the name of student
                b. Second line shows the student's grade
            v.   Program will read the data stored in the file and display:
                a. List of students with their grade
                b. Student name with highest grade and score
                c. Student name with lowest grade and score
                d. Average grade in the class
        Option 2: Display an exit message and stop the program.
    Output: fstream studentList will output:
            1. string header will display class name
            2. string professor will display name of professor
            3. string term will display the class term
            4. string studentName will display student's name
            5. string studentScore will display previous student's score
            6. string bestStudent will assign name of first student with highest score
            7. int maxScore will display the highest score of class
            8. string worstStudent will assign name of first student with lowest score
            9. int minScore will display the lowest score of class
            10. double avgGrade will display the average grade of entire class
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    string title = "Course Summary App ...";
    string menuOptions = "Choose one of the following options\n\t1. Process Grades Summary Report.\n\t2. Quit.";
    string userOptionPrompt = "Option: ";
    string option1 = "Grades Summary Report ...";
    string option2 = "Good Bye ...";
    string optionDefault = "Please enter 1 or 2.";
    string promptFileName = "Enter name of file: ";
    string fileError = "File does not exist.";
    string demarcation = "--------------------------------------------------";
    string fileName, studentData, name, header, professor, term, bestStudent, worstStudent, studentName, grade;
    fstream studentList;
    int userChoice, maxScore = 0, minScore = 100, totalStudents = 0;
    double avgGrade, totalPoints = 0;
    bool quit = false;

    cout << '\n' << title << endl;

    do {
        cout << '\n' << menuOptions << endl;
        cout << userOptionPrompt;
        cin >> userChoice;

        switch(userChoice) {
            case 1:
                cout << '\n' << option1 << '\n' << endl;
                cout << promptFileName;
                cin >> fileName;
                studentList.open(fileName);
                
                if(studentList) {
                    cout << '\n' << demarcation << '\n' << endl;
                    getline(studentList, header);
                    cout << header << '\n' << endl;
                    getline(studentList, professor);
                    cout << setw(33) << left << professor;
                    getline(studentList, term);
                    cout << "Term: " << term << '\n' << endl;
                    cout << "\nList of Students" << endl;
                    cout << demarcation << endl;

                    while(getline(studentList, studentName)) {
                        cout << setw(30) << left<< studentName;
                        getline(studentList, grade);
                        int value = stod(grade);
                        cout << grade << '\n';
                        totalPoints += value;
                        totalStudents++;
                        if(value > maxScore) {
                            maxScore = value;
                            bestStudent = studentName;
                        }
                        if(value < minScore) {
                            minScore = value;
                            worstStudent = studentName;
                        }
                    }
                    cout << '\n' << "Highest Grade: " << bestStudent << " - " << maxScore << endl;
                    cout << "Lowest  Grade: " << worstStudent << " - " << minScore << endl;
                    avgGrade = totalPoints / totalStudents;
                    cout << "Average Grade: " << fixed << showpoint << setprecision(1) << avgGrade << endl;
                    cout << '\n' << demarcation << endl;

                } else {
                    cout << fileError << endl;
                }
                break;
            case 2:
                cout << '\n' << option2 << endl;
                quit = true;
                break;
            default:
                cout << '\n' << optionDefault << endl;
                cin.ignore();
                break;
        }
        studentList.close();
    } while (!quit);

    return 0;
}
/*
	Kim Claros

	assignmentGrade.cpp

	A menu-driven program that computes the grade of an assignment as a percentage of
	student score and total assignment points, writes that data to a file, and allows user
	to display said data.

	I:	student name (stuName), student score (stuPts), total assignment points (assPts)

	P:	1 - Display menu
		2 - Prompt user for option
		3 - Drive switch menu
			case 1: calcualte assignment grade
				open "assignment.txt"
				grade = (stuPts / assPts) * 100.0
				display assignment grade ceil(grade)
				close file
			case 2: display assignment grades
				open "assignment.txt" for input
				while there is data in file: display contents
				close file
			case 3: quit program

	O:	student name, assignment grade, and corresponding message
*/

// header files
#include <iostream>
#include <string>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	// variables
	int choice;
	fstream archivio;
	string stuName, peptalk;
	double stuPts, assPts, grade{};

	// intro
	cout << "\nAssignment Grade Calculator" << endl;

	// the meat
	do
	{
		// display menu and prompt user
		cout << "\nPlease select one of the following options:" << endl
			<< "\t1 - Calculate the assignment grade of one student." << endl
			<< "\t2 - Display assignment grades." << endl
			<< "\t3 - Quit program." << endl
			<< "Option: ";
		cin >> choice;

		// drive menu
		switch (choice)
		{
		case 1:		// calculate grade and write to file
			cout << "\nCalculate grade for one student" << endl;

			archivio.open("assignment.txt", ios::app);	// open file for appending

			if (archivio)
			{
				// collect student data
				cout << "\nEnter the following assignment information..." << endl << endl
					<< "\t" << setw(10) << left << "Student Name: ";
				cin.ignore();
				getline(cin, stuName);

				do
				{
					cout << "\t" << setw(10) << left << "Student score: ";
					cin >> stuPts;

					cout << "\t" << setw(10) << left << "Highest possible assignment score: ";
					cin >> assPts;

					grade = (stuPts / assPts) * 100.0;		// calculation

					// selecting the message!!
					if (grade >= 90)
						peptalk = "Excellent!";
					else if (grade < 90 && grade >= 80)
						peptalk = "Well Done!";
					else if (grade < 80 && grade >= 70)
						peptalk = "Good!";
					else if (grade < 70 && grade >= 60)
						peptalk = "Needs improvement...";
					else if (grade < 60)
						peptalk = "FAIL";

					for (int i = 1; i <= 40; i++)
						cout << '-';
					cout << endl;

					if (stuPts < 0.0 && assPts < 0.0)
						cout << "ERROR: Assignment scores cannot be negative. Please try again." << endl;
				} while (stuPts < 0.0 && assPts < 0.0);

				// display grade and pep
				cout << stuName << "\t" << ceil(grade) << "%" << "\t" << peptalk << endl;

				archivio << stuName << endl << grade << endl << endl;		// write to file
				archivio.close();		// close file

			}
			else
				cout << "ERROR: Could not locate necessary file." << endl;

			break;

		case 2:		// display data
			cout << "\nDisplaying assignment grades..." << endl;
			for (int i = 1; i <= 32; i++)
				cout << '-';
			cout << endl;

			archivio.open("assignment.txt", ios::in);

			// display records if they exist
			while (archivio >> stuName)
			{
				archivio.ignore();
				getline(archivio, stuName);		// figure out why console only display last name??
				archivio >> grade;

				cout << stuName << "\t" << ceil(grade) << "%" << endl;
			}

			archivio.close();		// close file

			break;

		case 3:		// quitter
			cout << "\nGoodbye..." << endl << endl;
			break;

		default:	// error
			cout << "ERROR: Invalid option. Please try again." << endl;
			
		}

	} while (choice != 3);

	return 0;
}
/*
	Mary Taboada

	students.cpp

	Menu-Driven interface program that allows the user tö:
		1. Create a new student file.
		2. Add a student to file.
		3. Display student file.
		4. Quit

	Input: Student data <Student Id / Student Name / Student GPA>

	Processing:	1. Display Menu
				2. Prompt user for choice
				3. Drive menu options:
				   Case 1 - Create file
						Open "student.txt" file for output (writing)
						Close file
				   Case 2 - Add a student
						Open file for appending
						Prompt user for student data (id, name & gpa)
						Write student record to file
						Close file
				  Case 3 - Display file
						Open file for input (reading)
						While there are student records in the file
							Read student record
							Display student record
						Close file
				  Case 4 - Quit

	Output: "student.txt" file containing student records
*/

// Header files
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
	// Constants & Variables
	int choice;
	fstream myFile;
	string stdId, stdName;
	double stdGPA;

	// Intro
	cout << "\nStudent File Management System ..." << endl;

	// Menu-Driven Interface
	do
	{
		// Display menu & prompt user for choice
		cout << "\nChoose one of the following options" << endl
			<< "\t1. Create a new students file." << endl
			<< "\t2. Add a student to file." << endl
			<< "\t3. Display students file." << endl
			<< "\t4. Quit." << endl
			<< "Option: ";
		cin >> choice;

		// Drive menu options
		switch (choice)
		{
		case 1: // Create new file
			cout << "\nCreating new \"students.txt\" file ..." << endl;

			// Open file for output
			myFile.open("students.txt", ios::out);

			if (myFile)
			{
				cout << "New \"students.txt\" file successfully created." << endl;
				// Close file
				myFile.close();
			}
			else
				cout << "Fatal Error ... Could not create \"students.txt\" file." << endl;

			break;
		case 2: // Add a student
			cout << "\nAdding a student to \"students.txt\" ..." << endl;

			// Open file for appending
			myFile.open("students.txt", ios::app);

			if (myFile)
			{
				// Prompt user for student data
				cout << "\nEnter the following student data" << endl
					<< "\t" << setw(10) << left << "Id:";
				cin >> stdId;

				cout << "\t" << setw(10) << left << "Name:";
				cin.ignore();	// Flush \n from buffer
				getline(cin, stdName);

				do
				{
					cout << "\t" << setw(10) << left << "GPA:";
					cin >> stdGPA;

					if (stdGPA < 0.0 || stdGPA > 4.0)
						cout << "Error ... Invalid GPA. Try Again." << endl;
				} while (stdGPA < 0.0 || stdGPA > 4.0);

				// Write student record to file
				myFile << stdId << endl
					<< stdName << endl
					<< stdGPA << endl;

				// Close file
				myFile.close();
			}
			else
				cout << "Error ... Could not open \"students.txt\" file." << endl;
			break;
		case 3: // Display file
			cout << "\nDisplaying \"students.txt\" ..." << endl;

			// Open File for input
			myFile.open("students.txt", ios::in);

			if (myFile)
			{
				// Display header
				cout << "\nList of Students" << endl;
				for (int i=1; i<=33; i++)
					cout << '-';
				cout << endl;

				// Read student records & display 
				while (myFile >> stdId)
				{
					myFile.ignore();	// Flush \n from buffer
					getline(myFile, stdName);
					myFile >> stdGPA;

					// Display student record
					cout << setw(10) << left << stdId
						<< setw(20) << left << stdName
						<< fixed << showpoint << setprecision(1)
						<< stdGPA << endl;
				}

				// Close file
				myFile.close();
			}
			else
				cout << "Error ... Could not open \"students.txt\" file." << endl;

			break;
		case 4:	// Quit
			cout << "\nGood Bye ..." << endl << endl;
			break;
		default: // Error
			cout << "Error ... Invalid option. Try Again." << endl;
		}

	} while (choice != 4);


	return 0;
}
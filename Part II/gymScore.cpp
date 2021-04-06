/*
	Mary Taboada

	gymScore.cpp

	Prompt user for five judges scores (1-10), calculate & display the
	athlete's score as the average of the scores after dropping the
	highest and the lowest ones.

	Input: Scores (1-10) from five judges

	Processing:	1. Prompt user for judges scores (1-10) => s1, s2, ... , s5
				2. Calculate athlete's score
					Determine highest
					Determine lowest
					Calculate average
						average = (s1 + s2 + s3 + s4 + s5 - highest - lowest) / 3.0;
					Display result

	Output: Athlete's score
*/

// Header Files
#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototypes
int getScore(int);
void calcScore(int, int, int, int, int, double& );
int getHighest(int, int, int, int, int);
int getLowest(int, int, int, int, int);
void displayScore(double);

int main()
{
	// Variables
	int s1, s2, s3, s4, s5; // Scores from each of the five judges
	double average;			// Athlete's score
	int score;				// Judge score

	// Intro
	cout << "\nGymnastic Score Calculator ..." << endl << endl;

	// Prompt user for judges scores
	for (int judge = 1; judge <= 5; judge++)
	{
		score = getScore(judge);

		switch (judge)
		{
			case 1:
				s1 = score;
				break;
			case 2:
				s2 = score;
				break;
			case 3:
				s3 = score;
				break;
			case 4:
				s4 = score;
				break;
			case 5:
				s5 = score;
		}
	}

	// Calculate athlete's score
	calcScore(s1, s2, s3, s4, s5, average);

	// Display result
	displayScore(average);

	return 0;
}

/*
	int getScore(int judgeId)

	Prompt user for judgeId score (1-10) and return it 
	back to the caller.

	Return Value: Judge's score
*/
int getScore(int judgeId)
{
	int score;

	// Prompt user for score (1-10)
	do
	{
		cout << "Enter judge " << judgeId << " score (1-10): ";
		cin >> score;

		if (score < 1 || score > 10)
			cout << "Error ... Invalid score. Try again." << endl;
	} while (score < 1 || score > 10);

	return score;
}

/*
	void calcScore(int s1, int s2, int s3, int s4, int s5, double& atlScore)

	Calculates an athlete's score as the average of five scores (s1-s5), after
	dropping the highest & lowest ones. Returns the result through the reference
	parameter atlScore.

	Return Value: None
*/
void calcScore(int s1, int s2, int s3, int s4, int s5, double& atlScore)
{
	// Calculate athlete's score
	atlScore = (s1 + s2 + s3 + s4 + s5 - getHighest(s1, s2, s3, s4, s5) - getLowest(s1, s2, s3, s4, s5)) / 3.0;

	return;
}

/*
	int getHighest(int s1, int s2, int s3, int s4, int s5)
	
	Determines the highest of five scores (s1 - s5), and returns it 
	back to the caller

	Return Value: Highest score
*/
int getHighest(int s1, int s2, int s3, int s4, int s5)
{
	int highest;

	// Determine highest
	highest = s1;
	if (s2 > highest)
		highest = s2;
	if (s3 > highest)
		highest = s3;
	if (s4 > highest)
		highest = s4;
	if (s5 > highest)
		highest = s5;

	return highest;
}

/*
	int getLowest(int s1, int s2, int s3, int s4, int s5)

	Determines the lowest of five scores (s1 - s5), and returns it
	back to the caller

	Return Value: Lowest score
*/
int getLowest(int s1, int s2, int s3, int s4, int s5)
{
	int lowest;

	// Determine highest
	lowest = s1;
	if (s2 < lowest)
		lowest = s2;
	if (s3 < lowest)
		lowest = s3;
	if (s4 < lowest)
		lowest = s4;
	if (s5 < lowest)
		lowest = s5;

	return lowest;
}

/*
	void displayScore(double atlScore)

	Displays the athlete's score (atlScore) with a precision of 
	1 decimal place.

	Return Value: None
*/
void displayScore(double atlScore)
{
	// Display athlete's score
	cout << "\nThe athlete's score is "
		<< fixed << showpoint << setprecision(1)
		<< atlScore << endl;

	return;
}

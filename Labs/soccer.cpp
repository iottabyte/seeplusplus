/*
	Kim Claros

	soccer.cpp

	A program that reads team information from a file and displays the user's
	desired selection from a menu: roster, total goals, & team star.

	i:	menu choice, file name

	p:	1 - display menu and prompt user for choice
		2 - drive menu options
			1. Load team information
				prompt user for file name and read data into array
			2. Display team roster
			3. Display team goals
				calculate total goals
				 sum of all 'goals' members in struct array
			4. Display team star(s)
				determine highest 'goals' member and display player name
			5. Quit

	o:	team roster, goals, stars
*/

// header files
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 15;	// global constant:  max size of team

// user defined variables
struct Player
{
	string name;		// player name
	int jersey;			// player team number
	int goals;			// goals scored by player
};

// function prototypes
void getData(Player[], int&);
void dispRoster(Player[], int);
int calcGoals(Player[], int);
void dispStar(Player[], int);

int main()
{
	// variables
	const int QUIT = 5;
	int menu, teamGoals, atlUn;						// atlUn: size of Atlanta United	
	Player team[SIZE];	

	cout << "\nSoccer Team Stats Manager" << endl;	// intro
		
	// menu
	do
	{
		cout << "\nSelect one of the following options:" << endl
			<< "\n\t1 - Load team information from file" << endl
			<< "\t2 - Display team roster" << endl
			<< "\t3 - Display total goals scored" << endl
			<< "\t4 - Reveal top player" << endl
			<< "\t5 - Quit\n\nOption: ";
		cin >> menu;

		switch (menu)
		{
		case 1:		// read file

			// read data into array
			getData(team, atlUn);	

			break;
		case 2:		// roster

			// chart header
			cout << "\nTeam Roster\n" << endl
				<< setw(15) << left << "\nPlayer" << "Number" << "\tGoals Scored\n" << endl;
			// loop function call for each player
			for (int p = 0; p < atlUn; p++)
			{
				dispRoster(team, p);
			}
			for (int i = 0; i < 36; i++)
				cout << '-';
			cout << endl;

			break;
		case 3:		// goals

			teamGoals = calcGoals(team, atlUn);

			cout << "\nThe total goals scored by this team is " << teamGoals << "." << endl;

			break;
		case 4:		// team star

			dispStar(team, atlUn);

			break;
		case 5:		// quit

			cout << "\nGoodbye..." << endl;

			break;
		default:

			cout << "\nERROR: Invalid option. Please try again." << endl;
		}
	} while (menu != QUIT);
	
	return 0;
}

/*
	void getData(Player arr[])

	prompts user for file name and then opens the file and
	reads data into structure array
*/
void getData(Player arr[], int& atl)
{
	string filename;
	fstream team;

	// prompt user
	cout << "\nEnter name of file: ";
	cin >> filename;

	// open file
	team.open(filename);

	if (!team)
	{
		cout << "\nFatal Error!! Could not open " << filename << endl;
		exit(EXIT_FAILURE);
	}

	atl = 0;
	while (team >> arr[atl].jersey)
	{
		getline(team, arr[atl].name);
		team >> arr[atl].jersey;
		team >> arr[atl].goals;
		atl++;
	} 

	// close file
	team.close();

	// confirmation message
	cout << "\nThank you. Data read successfully." << endl;
	for (int i = 0; i < 34; i++)
		cout << '-';
	cout << endl;

	return;
}

/*
	void dispRoster(Player team)

	displays the team player and their information corresponding
	to index when called
*/
void dispRoster(Player team[], int p)
{
	cout << setw(15) << left << team[p].name << team[p].jersey << "\t"
		<< team[p].goals << endl;

	return;
}

/*
	int calcGoals(Player pt[])

	calculates the sum of all player goals
	and returns it to the caller

	return val: goals
*/
int calcGoals(Player pt[], int size)
{
	int goals = 0;

	for (int i = 0; i < size; i++)
		goals += pt[i].goals;

	return goals;
}

/*
	void dispStar()

	determines the player(s) with the greatest number of goals
	and displays them to the user
*/
void dispStar(Player st[], int atl)
{
	int goat = INT_MIN;

	for (int i = 0; i < atl; i++)
	{
		if (st[i].goals > goat)
			goat = st[i].goals;
	}

	cout << "\nThe star player who has scored the most is "
		<< st[goat].name << " with " << st[goat].goals << " goals!" << endl;

	return;
}

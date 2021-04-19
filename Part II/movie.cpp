/*
	Kim Claros

	movie.cpp

	Program that maintains information about movies.

	i:	data about movies
		- title
		- director
		- genre
		- running time (in minutes)
	p:	1 - prompt user for information about some movies
		2 - display movie's report
	o:	report showing information about movies
*/

// header files
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// user defined structures
struct movieData
{
	string movTitle;
	string movDirect;
	string movGenre;
	int year;
	int runtime;
};

// function protos
movieData getMovie();
void dispMovie(movieData);

int main()
{
	// variables
	movieData movie1, movie2;

	cout << "\nLet's Go to the Movies" << endl;

	// collect data
	cout << "\n\tFilm #1" << endl;
	movie1 = getMovie();
	cout << "\n\tFilm #2" << endl;
	movie2 = getMovie();

	// display data
	cout << "\nList of Movies:" << endl;
	dispMovie(movie1);
	cout << endl;
	dispMovie(movie1);

	return 0;
}

/*
	movieData getMovie()

	prompts user for film information and
	returns data to caller

	return val: movie
*/
movieData getMovie()
{
	movieData movie;
	const int WID = 25;

	// prompt & collect
	cout << "\nEnter the following data..." << endl
		<< setw(WID) << left << "\nTitle: ";
	getline(cin, movie.movTitle);
	cout << setw(WID) << left << "Director(s): ";
	getline(cin, movie.movDirect);
	cout << setw(WID) << left << "Genre: ";
	getline(cin, movie.movGenre);
	do
	{
		cout << setw(WID) << left << "Release Year: ";
		cin >> movie.year;

		if (movie.year < 0)
			cout << "\nERROR: Invalid year. Try again." << endl;
	} while (movie.year < 0);
	do
	{
		cout << setw(WID) << left << "Film Runtime (minutes): ";
		cin >> movie.runtime;

		if (movie.runtime < 0)
			cout << "\nERROR: Invalid time. Try again." << endl;
	} while (movie.runtime < 0);
	
	cin.ignore();		// flush input buffer

	return movie;
}

/*
	void dispMovie(movieData film)

	display data received about movieData item
*/
void dispMovie(movieData film)
{
	const int WID = 20;
	
	// display movie info
	cout << setw(WID) << left << "\nTitle: " << film.movTitle << endl
		<< setw(WID) << left << "Director(s): " << film.movDirect << endl
		<< setw(WID) << left << "Genre: " << film.movGenre << endl
		<< setw(WID) << left << "Release Year: " << film.year << endl
		<< setw(WID) << left << "Running Time: " << film.runtime << " mins." << endl;

	return;
}
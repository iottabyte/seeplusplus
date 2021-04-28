/*
	Kim Claros

	schoolStore.cpp

	a menu-driven interface program that allows a user to manage an
	inventory and calculate total cost of items in inventory
	
	menu options:
		1 - Add new item to inventory
		2 - List inventory items
		3 - Calculate total cost of items in inventory
		4 - Quit
*/

// header files
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

// fantasy data types
struct Inventory
{
	string number;
	string name;
	int quantity;
	double price;
};

// global constant
const int SIZE = 50;

// function protos
void readInData(Inventory[], int&);
Inventory getItem();
void addItem(Inventory);
double calcTotal(Inventory[], int);
void dispList(Inventory[], int);

int main()
{
	// variables
	Inventory myInventory[SIZE];
	Inventory newItem;
	double total;
	int size, choice;
	const int QUIT = 4;

	cout << "\nBack to School Inventory Managment System" << endl;

	// read file contents into array
	readInData(myInventory, size);

	// menu
	do
	{
		cout << "\nSelect of the following options..." << endl
			<< "\n\t1 - Add new item to inventory" << endl
			<< "\t2 - List items in inventory" << endl
			<< "\t3 - Calculate total cost of items in inventory" << endl
			<< "\t" << QUIT << " - Quit" << endl << "\nYour choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:		// add new item
			
			newItem = getItem();			// prompt user for new item

			addItem(newItem);				// append record
			cout << "\nNow writing item to file..." << endl;

			readInData(myInventory, size);	// update array
			cout << "Done." << endl;

			break;
		case 2:		// list items
			
			// table header
			cout << "\nInventory List\n" << endl
				<< "Number" << setw(2) << " " << left << "Item Name" << setw(10) << right
				<< "Price" << setw(5) << " " << "Quantity\n" << endl;

			// loop function call
			for (int i = 0; i < size; i++)
			{
				dispList(myInventory, i);
			}

			break;
		case 3:		// total

			total = calcTotal(myInventory, size);

			cout << "\nThe total cost of all items currently in inventory is $" 
				<< fixed << showpoint << setprecision(2) << total << "." << endl;

			break;
		case 4:		// quit

			cout << "\nGoodbye..." << endl;

			break;
		default:
			cout << "\nERROR: Invalid menu choice. Please try again." << endl;
		}

	} while (choice != QUIT);

	return 0;
}

/*
	void readInData(Inventory arr[], int& size)

	reads data from file into array of structure data
*/
void readInData(Inventory arr[], int& size)
{
	ifstream inv;

	inv.open("inventory.txt");		// open file

	if (!inv)
	{
		cout << "\nFatal Error! Could not open inventory.txt..." << endl;
		exit(EXIT_FAILURE);
	}

	size = 0;
	while (inv >> arr[size].number)
	{
		inv >> arr[size].number;
		inv >> arr[size].name;
		inv >> arr[size].quantity;
		inv >> arr[size].price;
		size++;
	}

	inv.close();		// close file

	return;
}

/*
	Inventory getItem()

	prompts user for information on new item and returns the data to the caller

	return val: struct variable nuevo
*/
Inventory getItem()
{
	Inventory nuevo;
	const int WID = 25;

	// prompt & collect
	cout << "\nEnter new item information..." << endl
		<< setw(WID) << left << "\nProduct number: ";
	cin >> nuevo.number;
	cout << setw(WID) << left << "Item name: ";
	getline(cin, nuevo.name);
	do
	{
		cout << setw(WID) << left << "Quantity of items: ";
		cin >> nuevo.quantity;

		if (nuevo.quantity < 1)
			cout << "\nERROR: Invalid amount. Try again." << endl;
	} while (nuevo.quantity < 1);
	do
	{
		cout << setw(WID) << left << "Item price: ";
		cin >> nuevo.price;

		if (nuevo.price < 1.0)
			cout << "\nERROR: Invalid price. Try again." << endl;
	} while (nuevo.price < 1.0);

	cin.ignore();		// flush input buffer

	return nuevo;
}

/*
	void addItem(Inventory newItem)

	opens file and adds new item(s) from structure array to
	the file
*/
void addItem(Inventory newItem)
{	
	ofstream add;

	add.open("inventory.txt");		// open file

	add << newItem.number << "\t";
	add << newItem.name << "\t";
	add << newItem.quantity << "\t";
	add << newItem.price << endl;

	add.close();					// close file

	return;
}

/*
	double calcTotal(Inventory arr[], int size)

	calculates the total cost of all items in inventory
	and returns the amount to the caller

	return val: sum of all costs per item
*/
double calcTotal(Inventory arr[], int size)
{
	double sum = 0;

	for (int i = 0; i < size; i++)
		sum += (arr[i].price * arr[i].quantity);

	return sum;
}

/*
	void dispList(Inventory)

	displays 1 item and its members
*/
void dispList(Inventory inv[], int i)
{
	cout << inv[i].number << setw(2) << " " << left << inv[i].name 
		<< setw(10) << right << "$" << inv[i].price << setw(5) << " " 
		<< inv[i].quantity << endl;

	return;
}
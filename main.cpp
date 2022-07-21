// CH7PC20.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;
const int ROWS = 5;
const int COLUMNS = 30;

double OverallTicketSales = 0;
int OverallSeatsSold = 0;

void enterSeatPrices(double[]);
void viewSeatPrices(double[]);
void ticketsBeingSold(char[][COLUMNS], double[]);
void viewSeatingChart(char[][COLUMNS]);
void rowSeatsAvailable(char[][COLUMNS]);
void auditoriumSeatsAvailable();

int main()
{
	//arrays and var
	double seatPrices[ROWS];
	char seatingChart[ROWS][COLUMNS];
	bool determinent = true;

	enterSeatPrices(seatPrices);

	//original set for seating ws
	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLUMNS; y++)
		{
			seatingChart[x][y] = '#';
		}
	}

	
	while (determinent == true)
	{
		int choice;
		cout << "\n What would you like to do?\n";
		cout << "1. Purchase tickets\n2. View the number of seats available by row\n3. View the total number of seats left in the auditorium\n";
		cout << "4. View the total amount of ticket Sales\n5. View how many tickets have been sold\n6. View seat Prices\n7. View a map of the seating chart.\n8. End the Program  \n Please enter your selection. ";
		cin >> choice;
		while (choice < 1 || choice > 8)
		{
			cout << "Your choice must be between 1 and 8. Please reenter your selection";
			cin >> choice;
		}
		switch (choice)
		{
		case 1: ticketsBeingSold(seatingChart, seatPrices);
			break;
		case 2: rowSeatsAvailable(seatingChart);
			break;
		case 3: auditoriumSeatsAvailable();
			break;
		case 4: cout << "\nThe overall ticket sales are $" << OverallTicketSales << endl;	
			break;
		case 5: cout << "\n" << OverallSeatsSold << " tickets have been sold\n\n";
			break;
		case 6: viewSeatPrices(seatPrices);
			break;
		case 7: viewSeatingChart(seatingChart);
			break;
		case 8: determinent = false;
		}
	
	}
	return 0;
}
\
void enterSeatPrices(double seatPrices[])
{
	cout << "This program reprensents a simulation for a small theater.\n";
	cout << "Please enter the seat prices for each row in your theater\n";
		for (int count = 0; count< ROWS; count++)
		{
			cout << "Price of Row " << count + 1 << endl << "$";
			cin >> seatPrices[count];
			while( seatPrices[count] < 0)
				{
				cout << "All seat prices must be greater than zero. Please reenter your price\n";
				cin >> seatPrices[count];
				}
		}
}

void viewSeatPrices(double seatPrices[])
{
	for (int count = 0; count < ROWS; count++)
	{
		cout << fixed << setprecision(2);
		cout << "\nPrice of Row " << count + 1 << " is $" << seatPrices[count] << endl;
	}
}

void ticketsBeingSold(char seatingChart[][COLUMNS], double seatPrices[] )
{
	int tickets;
	int row;
	int column;
	double seatPrice;
	double totalSeatPrices = 0;

	cout << "\nHow many tickets would you like to purchase\n";
	cin >> tickets;
	for (int count = 0; count < tickets; count++)
	{
		cout << "where would like to sit. please enter row and seat number\n Row:";
		cin >> row;
		while (row < 1 || row > ROWS)
		{
			cout << "You entered an invalid number for your row. Rows are 1-15. Please Reenter\n";
			cin >> row;
		}
		cout << "Seat number:";
		cin >> column;
		while (column < 1 || column > COLUMNS)
		{
			cout << "You entered an invalid number for your seat number. The seats are numbered 1-30. Please Reenter\n";
			cin >> column;
		}
		while (seatingChart[row - 1][column - 1] == '@')
		{
			cout << "this seat is already taken. Please select another\n Row:";
			cin >> row;
			while (row < 1 || row > ROWS)
			{
				cout << "You entered an invalid number for your row. Rows are 1-15. Please Reenter\n";
				cin >> row;
			}
			cout << "Seat Number:";
			cin >> column;
			while (column < 1 || column > COLUMNS)
			{
				cout << "You entered an invalid number for your seat number. The seats are numbered 1-30. Please Reenter\n";
				cin >> column;
			}
		}
		seatingChart[row - 1][column - 1] = '@';
		viewSeatingChart(seatingChart);
		
		seatPrice = seatPrices[row - 1];
		totalSeatPrices += seatPrice;
		
	}
	cout << fixed << setprecision(2);
	cout << " The total price of your tickets is $" << totalSeatPrices << endl;
	OverallTicketSales += totalSeatPrices;
	OverallSeatsSold += tickets;

}

void viewSeatingChart(char seatingChart[][COLUMNS])
{
	cout << "\nThe # sign represents open seats and the @ represents seats that have already been taken\n";
	for (int x = 0; x < ROWS; x++)
	{
		for (int y = 0; y < COLUMNS; y++)
		{
			cout << seatingChart[x][y] << " ";
		}
		cout << endl;
	}
}

void rowSeatsAvailable(char seatingChart[][COLUMNS])
{
	int rowChoice;
	int seatsAvailable = 0;
	cout << "\nWhich Row would like to view the number of seats left in.\n";
	cout << "The rows are numbered 1-15. Please enter your selection\n";
	cin >> rowChoice;
	while (rowChoice<1 || rowChoice>ROWS)
	{
		cout << "Your selection must be between 1 and 15. Please Reenter a new number.\n";
		cin >> rowChoice;
	}
	for (int count = 0; count < COLUMNS; count++)
	{
		if (seatingChart[rowChoice-1][count]== '#')
		{
			seatsAvailable++;
		}
	}
	cout << "The number of seats availabe in row " << rowChoice << " is " << seatsAvailable << endl;
}

void auditoriumSeatsAvailable()
{
	int seatsAvailable;
	seatsAvailable = ROWS * COLUMNS - OverallSeatsSold;
	cout << "\nThe total number of seats left in the auditorium is " << seatsAvailable << endl;

}


#include "stdafx.h"
#include "Ticket.h"
#include <iostream>
using namespace std;


Ticket::Ticket()
{
}


Ticket::~Ticket()
{
}

void Ticket::Display()
{
	cout << "Passenger Email: " << PassengerEmail << endl;
	cout << "Flight Name: " << FlightName << endl;
	cout << "Time of Departure: " << DepTime << endl;
	cout << "Date of Departure: " << DepDate << endl;
}
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
	cout << "Ticket no.: " << TicketId << endl;
	cout << "Flight Name: " << FlightName << endl;
	cout << "Time of Departure: " << DepTime << endl;
	cout << "Date of Departure: " << DepDate << endl;
	cout << "Passenger Email: " << PassengerEmail << endl;
}
// AirlineReservationAssignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Passenger.h"
#include "Flight.h"
#include "Ticket.h"
#include <list>
#include <iostream>
#include <memory>




using namespace std;

std::list<shared_ptr<Flight>> Flights;
std::list<Passenger> Passengers;
std::list<Ticket> Tickets;

void PopulateFlights()
{
	Flight f1 = { "AA001","Denver","06/07/2018","0700","Seattle","06/07/2018","0900", 100,100 };
	Flights.push_back(make_shared<Flight>(f1));
	Flight f2 = { "AA002","New York","08/08/2018","1000","Denver","08/08/2018","1400", 100,100 };
	Flights.push_back(make_shared<Flight>(f2));
	Flight f3 = { "AA003","Newark","10/07/2018","0900","Seattle","10/07/2018","1300", 100,100 };
	Flights.push_back(make_shared<Flight>(f3));
	Flight f4 = { "AA004","Orlando","16/10/2018","1700","San Francisco","16/10/2018","2100", 100,100 };
	Flights.push_back(make_shared<Flight>(f4));
	Flight f5 = { "AA005","Los Angeles","26/11/2018","2100","Seattle","27/11/2018","0100", 1,1 };
	Flights.push_back(make_shared<Flight>(f5));
}



shared_ptr<Flight> GetFlight(string flightName)		
{
	for (auto flight:Flights)
	{
		
		if (flightName.compare(flight->FlightName) == 0)
			return flight;
	}
	throw exception("Flight not found.");
}

Passenger GetPassenger(string PassengerEmail)		
{
	for (auto pass : Passengers)
	{

		if (PassengerEmail.compare(pass.mEmail) == 0)
			return pass;
	}
	throw exception("Passenger not found.");
}

Ticket GetTicket(int ticketNum)		
{
	for (auto ticket : Tickets)
	{

		if (ticketNum == ticket.TicketId)
			return ticket;
	}
	throw exception("Ticket not found.");
}
int main()
{
	PopulateFlights();
	
	int response = -1;	//this will be used for making selections from menu
	cout << "Welcome to Kalacademy Airlines." << endl;
	while (response != 0)
	{
		string passengerEmail;		//used for holding passenger email and Flight numbers
		string flightName;
		cout << "=================================================" << endl;
		cout << "Main Menu:" << endl;
		cout << "Press 1 to Reserve a seat on a flight." << endl;						//very simple GUI
		cout << "Press 2 to Display flight schedules." << endl;
		cout << "Press 3 to See details of a single Flight" << endl;
		cout << "Press 4 to Display passenger information." << endl;
		cout << "Press 5 to Display user ticket information." << endl;
		cout << "Press 6 to Enter passenger information." << endl;
		//cout << "Press 7 to cancel a Passenger's Reservation." << endl;
		cout << "Press 0 to exit." << endl;
		cout << "=================================================" << endl;
		char input;
		cin >> input;
		if (isdigit(input))
		{
			response = input - '0';
		}
		else
		{
			response = -1;
		}
		switch (response)
		{
		case 1:

		{

			//Book a seat on a flight
			cout << "Available flights to choose from:" << endl;

			Flight::DisplayFlights(Flights);
			
			cout << "Please enter the name of the flight you want to book a seat on" << endl;
			cin >> flightName;
			shared_ptr<Flight> flight;
			try
			{
				flight = GetFlight(flightName);
			}
			catch (exception)
			{
				cout << "No such flight exists" << endl;
				break;
			}

			if (flight->numOfSeatsLeft >= 1)
			{


				cout << "Please enter your Email ID:" << endl;
				string passengerEmail;
				cin >> passengerEmail;

				Passenger p;
				try
				{
					p = GetPassenger(passengerEmail);
				}
				catch (exception)
				{
					cout << "Oops! Looks like we don't have the passenger records for this emailID. " << endl;

					cout << "Please enter your First Name" << endl;
					string firstName;
					cin >> firstName;
					cout << "Please enter your Last Name" << endl;
					string lastName;
					cin >> lastName;

					p.mFirstName = firstName;
					p.mLastName = lastName;
					p.mEmail = passengerEmail;

					Passengers.push_back(p);
				}


				Ticket t;
				t.TicketId = Tickets.size() + 1;
				t.PassengerEmail = p.mEmail;
				t.FlightName = flight->FlightName;
				t.DepDate = flight->DepDate;
				t.DepTime = flight->DepTime;

				Tickets.push_back(t);
				flight->numOfSeatsLeft--;


				cout << "Your booking is confirmed. Your ticket number is " << t.TicketId << endl;
				cout << "The number of seats left on this flight is " << flight->numOfSeatsLeft << endl;
					

			}

			else
			{
				cout << "Sorry! This flight is full." << endl;
			}

			break; 
		}

		case 2:
		{
			Flight::DisplayFlights(Flights);
			break;
			
		}

		case 3:
		{

			cout << "Enter Flight Number(eg: AB001):";		
			cin >> flightName;

			try
			{
				auto flight = GetFlight(flightName);
				flight->Display();
			}
			catch (exception)
			{
				cout << "Flight " << flightName << " not found." << endl;
			}
			break; 
		}
		case 4:

		{
			cout << "Enter Passenger's Email:";

			cin >> passengerEmail;
			try
			{
				auto passenger = GetPassenger(passengerEmail);
				passenger.display();
				for (auto tick : Tickets)
				{
					if (passengerEmail.compare(tick.PassengerEmail) == 0)
					{
						tick.Display();
					}
				}
			}
			catch (exception)
			{
				cout << "Passenger " << passengerEmail << " not found." << endl;
			}

		
			break; 
		}
		case 5:
		{
			cout << "Please provide your ticket number." << endl;
			int ticketnum;
			cin >> ticketnum;
			try
			{
				Ticket passengerTicket = GetTicket(ticketnum);
				passengerTicket.Display();
			}
			catch (const std::exception&)
			{
				cout << "Sorry! This ticket does not exist." << endl;
			}


			
			break; 
		}

		case 6: 
		{
			Passenger p;
			cout << "Please enter your Email ID: " << endl;
			string passengerEmail;
			cin >> passengerEmail;
			cout << "Please enter your First Name: " << endl;
			string firstName;
			cin >> firstName;
			cout << "Please enter your Last Name: " << endl;
			string lastName;
			cin >> lastName;

			p.mFirstName = firstName;
			p.mLastName = lastName;
			p.mEmail = passengerEmail;

			Passengers.push_back(p);
			
			break; 
		}

		/*case 7: {
			
			break;
		}*/ 
		default:

			cout << "Please provide a valid response." << endl;
			break;
		}


		}
		return 0;
	}

	
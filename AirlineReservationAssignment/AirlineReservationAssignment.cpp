// AirlineReservationAssignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Passenger.h"
#include "Flight.h"
#include "Ticket.h"
#include <list>
#include <iostream>

using namespace std;

std::list<Flight> Flights;
std::list<Passenger> Passengers;
std::list<Ticket> Tickets;

void PopulateFlights()
{
	Flight f1 = { "AB001","Denver","06/07/2018","0700","Seattle","06/07/2018","0900", 100,100 };
	Flights.push_back(f1);
}

Flight GetFlight(string flightName)		//This method will be used to query our lists to see if a certain flight is contained in them.
{
	for (auto flight:Flights)
	{
		
		if (flightName.compare(flight.FlightName) == 0)
			return flight;
	}
	throw exception("Flight not found.");
}

Passenger GetPassenger(string PassengerEmail)		//This method will be used to query our lists to see if a certain flight is contained in them.
{
	for (auto pass : Passengers)
	{

		if (PassengerEmail.compare(pass.mEmail) == 0)
			return pass;
	}
	throw exception("Passenger not found.");
}

Ticket GetTicket(int ticketNum)		//This method will be used to query our lists to see if a certain flight is contained in them.
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
		cout << "Press 1 to Reserve a seat." << endl;						//very simple GUI
		cout << "Press 2 to Display flight schedules." << endl;
		cout << "Press 3 to See details of a Flight" << endl;
		cout << "Press 4 to Display passenger information." << endl;
		cout << "Press 5 to Display user ticket information." << endl;
		//cout << "Press 6 to show all Reservations for a passenger." << endl;
		//cout << "Press 7 to cancel a Passenger's Reservation." << endl;
		cout << "Press 0 to exit." << endl;
		cout << "=================================================" << endl;

		cin >> response;
		switch (response)
		{
		case 1: 
		
		{		
			
			//Book a seat on a flight
			cout << "Available flights to choose from:" << endl;
				
			for (auto flight : Flights)
			{
				flight.Display();
			}

			cout << "Please enter the name of the flight you want to book a seat on" << endl;
			cin >> flightName;
			Flight flight;
			try
			{
				flight = GetFlight(flightName);
			}
			catch (exception) 
			{
				cout << "No such flight exists" << endl;
				break;
			}

			if (flight.numOfSeatsLeft > 1)
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
				t.FlightName = flight.FlightName;
				t.DepDate = flight.DepDate;
				t.DepTime = flight.DepTime;

				Tickets.push_back(t);
				flight.numOfSeatsLeft--;


				cout << "Your booking is confirmed. Your ticket number is " << t.TicketId << endl;

			}

			else
			{
				cout << "Sorry! This flight is full." << endl;
			}


			

			///calls our create flight method from Flight class and stores the new flight in list
			///Flight f;
			///f.createFlight();
			///flights.push_back(f);
			///break; 
		}

		case 2: 
		{
			/*cout << "Enter Flight Num(AB123):";	//used to cancel a flight by removing it from our list.
			cin >> flightNum;
			if (flightExist(flightNum))
			{
				j = flights.erase(j);
				cout << "Flight " << flightNum << " has been removed." << endl;
			}
			else
				cout << "Flight " << flightNum << " not found." << endl;
			break;*/
		}

		case 3: 
		{
			
			cout << "Enter Flight Number(eg: AB001):";		//Used for looking up flight details given a flight number.
			cin >> flightName;
			
			try
			{
				auto flight = GetFlight(flightName);
				flight.Display();
			}
			catch(exception)
			{
				cout << "Flight " << flightName << " not found." << endl;
			}
			break; }
		case 4: 
		
		{
			cout << "Enter Passenger's Email:";

			cin >> passengerEmail;
			try
			{
				auto passenger = GetPassenger(passengerEmail);
			}
			catch(exception)
			{
				cout << "Passenger " << passengerEmail << " not found." << endl;
			}

			/*Passenger p;	//takes information for a new passenger and saves it to list
			p.getInfo();
			passengers.push_back(p);*/
			break; }
		/*case 5: {
			cout << "Enter Passenger Number(A123):";	//this is used to book a passenger onto a flight
			cin >> passNum;
			cout << "Enter Flight Number(AB123):";
			cin >> flightNum;
			if (passengerExist(passNum))	//check if passenger exits
			{
				if (flightExist(flightNum))		//check if flight exists
				{
					Passenger p = *i;
					Flight f = *j;
					if (f.longHaul&&f.seatsLeft>0)	//adds passenger to flight if requirments are met
					{
						p.makeReservation(flightNum, f.longHaul, f.basePrice);
						f.seatsLeft--;
						*i = p;
						*j = f;
					}
					else if (f.seatsLeft>0)
					{
						p.makeReservation(flightNum, f.longHaul, f.basePrice);
						f.seatsLeft--;
						*i = p;
						*j = f;
					}
					else
						cout << "Flight is Full" << endl;	//error messages
				}
				else
					cout << "Flight " << flightNum << " not found." << endl;
			}
			else
				cout << "Passenger Number not found" << endl;
			break; }

		case 6: {
			cout << "Enter Passenger Number(A123):";	//checks to see what flights a passenger is booked onto
			cin >> passNum;
			if (passengerExist(passNum))
			{
				Passenger p = *i;
				p.printInfo();
			}
			else
				cout << "Passenger Number not found" << endl;
			break; }

		case 7: {
			cout << "Enter Passenger Number(A123):";		//used for removing a passenger from a flight
			cin >> passNum;
			cout << "Enter Flight Number(AB123):";
			cin >> flightNum;
			if (passengerExist(passNum))
			{
				if (flightExist(flightNum))
				{
					Passenger p = *i;
					Flight f = *j;
					p.cancelReservation(flightNum);
					f.seatsLeft++;		//increments seats available
				}
				else
					cout << "Flight " << flightNum << " not found. Flight may have been cancelled!" << endl;
			}
			else
				cout << "Passenger Number not found" << endl;
			break; }*/

		}
	}


return 0;
}


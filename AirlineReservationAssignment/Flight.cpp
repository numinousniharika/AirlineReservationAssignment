#include "stdafx.h"
#include "Flight.h"
#include <iostream>
#include "TextTable.h"
#include <list>
using namespace std;



void Flight::Display()
{
	TextTable t('-', '|', '+');

	t.add("");
	t.add("Flight Name");
	t.add("City of Departure");
	t.add("Date of Departure");
	t.add("Time of Departure");
	t.add("City of Arrival");
	t.add("Date of Arrival");
	t.add("Time of Arrival");
	t.endOfRow();

	t.add("");
	t.add(FlightName);
	t.add(DepCity);
	t.add(DepDate);
	t.add(DepTime);
	t.add(ArrCity);
	t.add(ArrDate);
	t.add(ArrTime);
	t.endOfRow();

	cout << t;
	
	/*cout << "Flight name:" << FlightName << endl;
	cout << "City of Departure:" << DepCity << endl;
	cout << "Date of Departure:" << DepDate << endl;
	cout << "Time of Departure:" << DepTime << endl;
	cout << "City of Arrival:" << ArrCity << endl;
	cout << "Date of Arrival:" << ArrDate << endl;
	cout << "Time of Arrival:" << ArrTime << endl;*/

		
}

void Flight::DisplayFlights(const std::list<shared_ptr<Flight>>& flights)
{
	TextTable t('-', '|', '+');

	t.add("");
	t.add("Flight Name");
	t.add("City of Departure");
	t.add("Date of Departure");
	t.add("Time of Departure");
	t.add("City of Arrival");
	t.add("Date of Arrival");
	t.add("Time of Arrival");
	t.endOfRow();

	for (auto flight : flights)
	{
		t.add("");
		t.add(flight->FlightName);
		t.add(flight->DepCity);
		t.add(flight->DepDate);
		t.add(flight->DepTime);
		t.add(flight->ArrCity);
		t.add(flight->ArrDate);
		t.add(flight->ArrTime);
		t.endOfRow();
	}



	cout << t;
}
#pragma once
#include<string>
#include <list>
class Flight
{
public:
	Flight() = default;
	~Flight() = default;

	void Display();
	static void DisplayFlights(const std::list<Flight>& flights);

	std::string FlightName;
	std::string DepCity;
	std::string DepDate;
	std::string DepTime;
	std::string ArrCity;
	std::string ArrDate;
	std::string ArrTime;
	
	int capacity;
	int numOfSeatsLeft;
};


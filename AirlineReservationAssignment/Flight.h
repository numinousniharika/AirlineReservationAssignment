#pragma once
#include<string>
#include <list>
#include <memory>

using namespace std;

class Flight
{
public:
	Flight() = default;
	~Flight() = default;

	void Display();
	static void DisplayFlights(const std::list<shared_ptr<Flight>>& flights);

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


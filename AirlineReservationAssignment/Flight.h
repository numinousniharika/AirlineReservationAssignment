#pragma once
#include<string>
class Flight
{
public:
	Flight() = default;
	~Flight() = default;

	void Display();

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


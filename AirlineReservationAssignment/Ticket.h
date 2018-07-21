#pragma once
#include <string>
class Ticket
{
public:
	Ticket();
	~Ticket();

	void Display();

	int TicketId;
	std::string PassengerEmail;
	std::string FlightName;
	std::string DepTime;
	std::string DepDate;

};


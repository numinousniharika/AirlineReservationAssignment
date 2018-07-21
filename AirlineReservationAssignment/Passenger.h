#pragma once
#include <string>

class Passenger
{
public:
	Passenger();
	~Passenger();

	/*std::string GetFirstName() const;
	void SetFirstName(std::string FirstName);

	std::string GetLastName() const;
	void SetLastName(std::string LastName);*/

	void display();


///private:

	std::string mFirstName;
	std::string mLastName;
	std::string mEmail;
	
};


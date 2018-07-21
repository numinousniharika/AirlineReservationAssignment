#include "stdafx.h"
#include "Passenger.h"
#include <iostream>
using namespace std;



Passenger::Passenger()
{
}


Passenger::~Passenger()
{
}

void Passenger::display()
{
	cout << "First Name: " << mFirstName << endl;
	cout << "Last Name: " << mLastName << endl;
	cout << "Email ID: " << mEmail << endl;
	
}
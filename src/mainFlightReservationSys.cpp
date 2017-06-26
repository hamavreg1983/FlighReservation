//============================================================================
// Name        : FlightReservationSys.cpp
// Author      : Yuval Hamberg
// Version     :
// Copyright   : MIT
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "PassengerManagert.h"
#include "Tier_t.h"

using namespace std;

int main() {
	cout << "---START--" << endl;

	{
		PassengerManager_t aPassMan;
		aPassMan.addPassenger(77, "Yuval", "telAviv", "123987", "next to window");
		cout << "size " << aPassMan.count() << endl ;
	}

	{
		PassengerManager_t aPassMan;
		cout << "isEmpty " << aPassMan.isEmpty() << endl ;
		cout << "size " << aPassMan.count() << endl ;
		aPassMan.addPassenger(69);

		cout << "add new resulted in " << aPassMan.addPassenger(42) << endl ;
		cout << "add exist resulted in " << aPassMan.addPassenger(53) << endl ;
		cout << "isEmpty " << aPassMan.isEmpty() << endl ;
		cout << "size " << aPassMan.count() << endl ;
	}

	{
		Tier_t tierA("first Class", 30, 10, 999);
		cout << tierA.getTierId() << endl;
		cout << tierA.getSeatName(39) << endl;
	}

	cout << "---END--" << endl;
	return 0;
}

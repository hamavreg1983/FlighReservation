//============================================================================
// Name        : FlightReservationSys.cpp
// Author      : Yuval Hamberg
// Version     :
// Copyright   : MIT
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "FRS.h"
#include "I_UI_t.h"
#include "UI_supervisor_t.h"
#include "Manager_t.h"

using namespace std;

int main() {
	cout << "---START--" << endl;

	FRS frsServer;

	I_UI_t* ui = frsServer.UI_start();

	frsServer.UI_stop(ui);

	cout << "---END--" << endl;
	return 0;
}



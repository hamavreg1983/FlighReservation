//============================================================================
// Name        : FlightReservationSys.cpp
// Author      : Yuval Hamberg
// Version     :
// Copyright   : MIT
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "I_UI_t.h"
#include "UI_supervisor_t.h"
#include "Manager_t.h"

using namespace std;

I_UI_t* chooseUI();

int main() {
	cout << "---START--" << endl;

	Manager_t* frsSys = new Manager_t;

	I_UI_t* ui = 0;
	ui = chooseUI();

	ui->connect(frsSys); // todo. change to comm when its done
	ui->UI_do();
	ui->disconnct();

	delete ui;
	delete frsSys;

	cout << "---END--" << endl;
	return 0;
}

I_UI_t* chooseUI()
{
	I_UI_t* ui = 0;
	int choosenUI;

	while (ui == 0)
	{
		cout << "Welcome to ElAl Flight Reservation System (FRS).\n---------------------------------------\n which kind of user are you?\n";
		cout << "\t1 - user\n\t2 - supervisor\n";
		cin >> choosenUI;

		if (choosenUI == 1)
		{
			ui = new UI_supervisor_t; // TODO change to user when i do it
		}
		else if (choosenUI == 2)
		{
			ui = new UI_supervisor_t;
		}
		else
		{
			cout << "ERORR! try again\n";
		}
	}
	return ui;
}

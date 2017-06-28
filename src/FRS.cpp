/*
 * FRS.cpp
 *
 *  Created on: Jun 28, 2017
 *      Author: uv
 */

#include "FRS.h"
#include "Manager_t.h"
#include "I_UI_t.h"
#include "UI_supervisor_t.h"

FRS::FRS() : m_mngr(0)
{
	m_mngr = new Manager_t;
}

FRS::~FRS()
{
	delete m_mngr;
}

I_UI_t* FRS:: chooseUI() const
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

I_UI_t* FRS::UI_start()
{
	I_UI_t* ui = 0;
	ui = chooseUI();

	ui->connect(m_mngr); // todo. change to comm when its done
	ui->UI_do();

	return ui;

}

void FRS::UI_stop(I_UI_t* _ui)
{
	_ui->disconnct();

	delete _ui;
}


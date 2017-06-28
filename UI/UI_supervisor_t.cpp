/*
 * UI_supervisor_t.cpp
 *
 *  Created on: Jun 26, 2017
 *      Author: yuval
 */

#include <string>
#include "UI_supervisor_t.h"

// TODO move const char* to const string define in ine place.

UI_supervisor_t::UI_supervisor_t()
{
	// TODO Auto-generated constructor stub
	m_mangerPtr = 0;

}

UI_supervisor_t::~UI_supervisor_t()
{
	// TODO Auto-generated destructor stub
}

void UI_supervisor_t:: connect(const Manager_t* _comm)
{
	m_mangerPtr = (Manager_t*) _comm;
	return;
}

void UI_supervisor_t:: UI_do()
{
	cout << "Welcome to ElAl Flight Reservation System (FRS).\n---------------------------------------\n are you a supervisor? please enter your password: ";
	string password;
	cin >> password;
	// TODO check password
	cout << "\nEntering FRS.\n";

	bool toExit = false;
	while (!toExit)
	{
		try
		{
			toExit = level1();
		}
		catch (const char* ex)
		{
			cout << "\n*** Got a problem (exception). ***\n";
			cout << ex << "\nback to main menu...\n\n";
		}
	}
}

bool UI_supervisor_t:: level1() const
{
	int counter;
	int option;

	while (true)
	{
		counter = 0;

		cout << "\n===========================================\nMain menu. \n\tChoose your action:\n";
		cout << counter   << " - exit \n";
		cout << ++counter << " - add flight \n";
		cout << ++counter << " - cancel flight \n";
		cout << ++counter << " - update flight \n";
		cout << ++counter << " - show flight info\n";
		cout << ++counter << " - show all flights info\n";
		cout << ++counter << " - add passenger \n";
		cout << ++counter << " - remove passenger \n";
		cout << ++counter << " - show passenger info \n";
		cout << ++counter << " - Order Ticket \n";
		cout << ++counter << " - Cancel Ticket \n";
		cout << ++counter << " - show Ticket info \n";
		cout << ++counter << " - show all Tickets info of passenger \n";

		cout << "\n===========================================\n";

// TODO this:
// update person
// choose seat
// find flight according to
// follow instraction on demand papers

		cin >> option;

		counter = 0;
		switch (option) {
			case 0: //exit
				return true;
				break;
			case 1: //add flight
				addFlight();
				break;
			case 2: //cancel flight
				removeFlight();
				break;
			case 3: //update flight
										cout << "\n not implemented \n";
				break;
			case 4: //show flight info
				showFlight();
				break;
			case 5: //show all flight info
				showFlights();
				break;
			case 6: //add passenger
				addPassenger();
				break;
			case 7: //remove passenger
				removePassenger();
				break;
			case 8: //show passenger info
				showPassenger();
				break;
			case 9: //Order Ticket
				orderTicket();
				break;
			case 10: //Cancel Ticket
				cancelTicket();
				break;
			case 11: //show Ticket info
				showTicket();
				break;
			case 12: //show all Tickets info
				showTickets();
				break;

			default:
				cout << "\nBad input. Try again\n";
				break;
		}
	}
	return false;
}

void UI_supervisor_t:: addPassenger() const
{
	string name;
	string idString;
	uint id = 0;
	string address;
	string phone;
	string preferanceSeating;

	cout << "in order to add a new passenger information you would need to answer a few questions\n";
	while (name.empty() )
	{
		cout << "Passenger full name: ";
		cin >> name;
	}
	while (! id )
	{
		cout << "Passenger ID (number only): ";
		cin >> idString;
		if ( is_digitsOnly(idString) )
		{
			istringstream ( idString ) >> id;
		}
	}
	while (phone.empty() )
	{
		cout << "Passenger phone: ";
		cin >> phone;
	}
	while (address.empty() )
	{
		cout << "Passenger address: ";
		cin >> address;
	}
	while (preferanceSeating.empty() )
	{
		cout << "Passenger Seat preference: ";
		cin >> preferanceSeating;
	}

	m_mangerPtr->passenger(id, name, address, phone, preferanceSeating);

	cout << "\nDone.\n";
	return;
}

uint UI_supervisor_t::showPassenger() const
{
	uint idPassnger = chooseUniqeID();

	const vector<string> info = m_mangerPtr->getPassengerInfo(idPassnger);

	printOut(info);

	return idPassnger;
}

uint UI_supervisor_t::chooseUniqeID() const
{
	// this function uses passnger name but is valid for all type of uniqe id

	uint idPassnger = 0;
	string idStringPassnger;
	while (! idPassnger)
	{
		cout << "Enter ID: ";
		cin >> idStringPassnger;
		if ( is_digitsOnly(idStringPassnger) )
		{
			istringstream ( idStringPassnger ) >> idPassnger;
		}
	}
	return idPassnger;
}

void UI_supervisor_t::removePassenger() const
{
	uint idPassnger = showPassenger();

	cout << "Remove this Pasenger? confirme. \n1 - yes\n0 - no ";
	bool isAction = false;
	cin >> isAction;
	if (isAction)
	{
		if ( m_mangerPtr->removePassenger(idPassnger) )
		{
			cout << "\nSuccess!\n";
		}
		else
		{
			cout << "\nFailed!\n";
		}
	}
	return;
}

void UI_supervisor_t::printOut(const vector<string> _info) const
{
	for (uint i = 0; i < _info.size() ; ++i)
	{
		cout << _info[i] << "\t";
	}
	cout << "\n";
}

uint UI_supervisor_t::addFlight(void) const
{
	string flightNum;
	string departure;
	string destination;
	string timeDeparture;
	string plane;
	uint id = 0;

	cout << "in order to add a new flight you would need to answer a few questions\n";
	while (flightNum.empty() )
	{
		cout << "Flight Number: ";
		cin >> flightNum;
	}
	while (departure.empty() )
	{
		cout << "Departure Airport: ";
		cin >> departure;
	}
	while (destination.empty() )
	{
		cout << "Destination Airport: ";
		cin >> destination;
	}
	while (timeDeparture.empty() )
	{
		cout << "Time and date of Departure (2017-05-17 17:58:00) : ";
		cin >> timeDeparture;
	}
	while (plane.empty() )
	{
		cout << "Plane number to be used in flight: ";
		cin >> plane;
	}

	id = m_mangerPtr->addFlight(flightNum, departure, destination, timeDeparture, plane);
	//	uint addFlight(const string& _flightNum, const string& _departure, const string& _destination, const string& _timeDeparture, const string& _plane );

	cout << "\nSucsses. flight id " << id << ".\n";
	return id;
}

void UI_supervisor_t::showFlight(uint _flightID) const
{
	const vector<string> info = m_mangerPtr->getflightInfo(_flightID);
	printOut(info);
	return;
}


uint UI_supervisor_t::showFlight() const
{
	uint id = chooseUniqeID();
	showFlight(id);
	return id;
}

void UI_supervisor_t::showFlights() const
{
	const vector<vector<string> > info = m_mangerPtr->getflightsInfo();
	for (uint i = 0; i < info.size() ; ++i)
	{
		printOut(info[i]);
	}
	return;
}

void UI_supervisor_t::removeFlight() const
{
	uint flightID = chooseUniqeID();
	showFlight(flightID);

	cout << "Remove this flight? confirme. \n1 - yes\n0 - no ";
	bool isAction = false;
	cin >> isAction;
	if (isAction)
	{
		if ( m_mangerPtr->removeFlight(flightID) )
		{
			cout << "\nSuccess!\n";
		}
		else
		{
			cout << "\nFailed!\n";
		}
	}
	return;
}

uint UI_supervisor_t::orderTicket() const
{
	cout << "Enter the passenger ID number.\n";
	uint passengerID = chooseUniqeID();

	cout << "Enter the flight ID number.\n";
	uint flightID = chooseUniqeID();

	showTierNames(flightID);
	cout << "Enter the tier name.\n";
	string tier;
	cin >> tier;

	showFreeSeats(flightID, tier);
	cout << "Enter the seat ID number.\n";
	uint seatID = chooseUniqeID();

	uint ticketID = m_mangerPtr->order(flightID, seatID, passengerID);

	cout << "\nSucsses. Ticket id " << ticketID << ".\n";
	return ticketID;
}

void UI_supervisor_t::cancelTicket() const
{
	cout << "Enter the ticket number.\n";
	uint ticket = chooseUniqeID();
	if ( m_mangerPtr->cancelTicket(ticket) )
	{
		cout << "\nSuccess!\n";
	}
	else
	{
		cout << "\nFailed!\n";
	}
	return;
}

void UI_supervisor_t::showTicket() const
{
	cout << "Enter the ticket number.\n";
	uint ticket = chooseUniqeID();
	showTicket(ticket);
	return;
}

void UI_supervisor_t::showTickets() const
{
	cout << "Enter the passenger ID number.\n";
	uint passenger = chooseUniqeID();
	const vector<vector<string> > info = m_mangerPtr->getTicketsInfo(passenger);
	for (uint i = 0; i < info.size() ; ++i)
	{
		printOut(info[i]);
	}
	return;
}

void UI_supervisor_t::showTicket(uint _ticketNum) const
{
	const vector<string> info = m_mangerPtr->getTicketInfo(_ticketNum);
	printOut(info);
	return;
}

void UI_supervisor_t::showFreeSeats(uint _flightID, const string& _tier) const
{
	cout << "\nHere a list of available seats:\n";
	const vector<vector<string> > info = m_mangerPtr->getFreeSeats(_flightID, _tier);
	for (uint i = 0; i < info.size() ; ++i)
	{
		printOut( info.at(i) );
	}
	return;
	// TODO user can enter seat number not in tier selected
}

void UI_supervisor_t::showTierNames(uint _flightID) const
{
	cout << "\nAvalibul Tier on flight" << _flightID << ":\n";

	const vector<string> info = m_mangerPtr->getTiersNames(_flightID);
	printOut(info); // TODO do print as menu and user chooses number and not type nane
	return;
}

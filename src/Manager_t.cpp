/*
 * Manager_t.cpp
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#include "Manager_t.h"
#include "FlightManager_t.h"
#include "PassengerManagert.h"
#include "BookingManager_t.h"
//TODO #include  commactor h

#include <list>

Manager_t::Manager_t()
{
	m_flightMngPtr = new FlightManager_t();
	m_passengerMngPtr = new PassengerManager_t();
	m_bookingMngPtr = new BookingManager_t();
	m_commPtr = 0;
}

Manager_t::Manager_t(Communicator_t* _commPtr)
{
	m_flightMngPtr = new FlightManager_t();
	m_passengerMngPtr = new PassengerManager_t();
	m_bookingMngPtr = new BookingManager_t();
	m_commPtr = _commPtr;
}

Manager_t::~Manager_t()
{
	m_commPtr = 0;
	delete m_bookingMngPtr;
	delete m_passengerMngPtr;
	delete m_flightMngPtr;
}

void Manager_t::setCommunicator(Communicator_t* _commPtr)
{
	m_commPtr = _commPtr;
	return;
}

uint Manager_t::order(uint flightID, uint _seatNum, uint _passengerID)
{
	if (! m_passengerMngPtr->isPassengerExist(_passengerID) )
	{
		throw "Passenger does not exist in the system. create Passenger first";
	}
	if (m_flightMngPtr->isSeatOccupancy(flightID, _seatNum) )
	{ // seat is not free
		throw "asked seat is not available";
	}

	// get the price of the seat ordered
	uint price = m_flightMngPtr->getSeatPrice(flightID, _seatNum);
	// create a ticket in booking,
	uint newTicketNum = m_bookingMngPtr->addTicket(_passengerID, _seatNum, _passengerID, price);
	// actually save the seat on the plane
	if (! m_flightMngPtr->orderSeat(flightID, _seatNum, newTicketNum) )
	{ // order failed
		throw "can't order seat because of an unknown problem. ticket was created but seat was not save. watch out.";
	}

	m_passengerMngPtr->addTicket(_passengerID, newTicketNum);

	return newTicketNum;
}

bool Manager_t::cancelTicket(uint _ticketNum)
{
	// get needed information from ticket
	uint flight = m_bookingMngPtr->getFlighId(_ticketNum);
	uint seat = m_bookingMngPtr->getSeat(_ticketNum);
	uint passenger = m_bookingMngPtr->getPassangerId(_ticketNum);

	bool result = false;
	// cancel ticket information across system
	result |= m_bookingMngPtr->removeTicket(_ticketNum);
	m_passengerMngPtr->removeTicket(passenger, _ticketNum);
	result |= m_flightMngPtr->cancelSeat(flight, seat);

	return result;
}

void Manager_t::passenger(uint _id, const string _name, const string _address,
		const string _phone, const string _preferanceSeating)
{
	if (m_passengerMngPtr->isPassengerExist(_id))
	{ // update passenger
		m_passengerMngPtr->setName(_id, _name);
		m_passengerMngPtr->setAddress(_id, _address);
		m_passengerMngPtr->setPhone(_id, _phone);
		m_passengerMngPtr->setPreferanceSeating(_id, _preferanceSeating);
	}
	else
	{ // create new passenger
		if (! m_passengerMngPtr->addPassenger(_id, _name, _address, _phone, _preferanceSeating) )
		{
			throw "could not create passenger.";
		}
	}
	return;
}

bool Manager_t::removePassenger(uint _passengerID)
{
	if (! m_passengerMngPtr->isPassengerExist(_passengerID) )
	{
		return false;
	}

	list<uint> tickets;
	tickets = m_passengerMngPtr->getTickets(_passengerID);

	list<uint>::iterator itr = tickets.begin();
	while ( itr != tickets.end() )
	{
		// cancelTicket function also removes ticket from passenger
		if ( this->cancelTicket(*itr) )
		{
			return false;
		}
		++itr;
	}
	return true;
}

uint Manager_t::addFlight(const string& _flightNum, const string& _departure,
		const string& _destination, const string& _timeDeparture,
		const string& _plane)
{
	// new flight
	return m_flightMngPtr->addFlight(_flightNum, _departure, _destination, _timeDeparture, _plane);
}

bool Manager_t::updateFlight(uint _flightID, const string& _flightNum,
		const string& _departure, const string& _destination,
		const string& _timeDeparture)
{
	if (! m_flightMngPtr->isFlightExsists(_flightID) )
	{
		return false;
	}
	m_flightMngPtr->setFlightNum(_flightID, _flightNum);
	m_flightMngPtr->setDeparture(_flightID, _departure);
	m_flightMngPtr->setDestination(_flightID, _destination);

	return true;
}

bool Manager_t::removeFlight(uint _flightID)
{
	if (! m_flightMngPtr->isFlightExsists(_flightID) )
	{
		return false;
	}

	return m_flightMngPtr->removeFlight(_flightID);
}




















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
#include "ReportFormatter_t.h"
//TODO #include  commactor h

#include <list>

Manager_t::Manager_t()
{
	m_flightMngPtr = new FlightManager_t();
	m_passengerMngPtr = new PassengerManager_t();
	m_bookingMngPtr = new BookingManager_t();
	m_reportFormatterPtr = new ReportFormatter_t(*this);
	m_commPtr = 0;
}

Manager_t::Manager_t(Communicator_t* _commPtr)
{
	m_flightMngPtr = new FlightManager_t();
	m_passengerMngPtr = new PassengerManager_t();
	m_bookingMngPtr = new BookingManager_t();
	m_reportFormatterPtr = new ReportFormatter_t(*this);
	m_commPtr = _commPtr;
}

Manager_t::~Manager_t()
{
	m_commPtr = 0;
	delete m_reportFormatterPtr;
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
	uint newTicketNum = m_bookingMngPtr->addTicket(flightID, _seatNum, _passengerID, price);
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

	// cancel ticket information across system
	bool resultTicket = m_bookingMngPtr->removeTicket(_ticketNum);
	m_passengerMngPtr->removeTicket(passenger, _ticketNum);
	bool resultSeat =  m_flightMngPtr->cancelSeat(flight, seat);

	return (resultTicket && resultSeat) ? true : false;
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
		// cancelTicket function also removes ticket from passenger. but it doesn't matter as we remove passnger in a few lines
		this->cancelTicket(*itr);
		++itr;
	}

	return m_passengerMngPtr->removePassenger(_passengerID);
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

const string& Manager_t::getDeparture(uint _flightID) const
{
	return this->m_flightMngPtr->getDeparture(_flightID);
}

const string& Manager_t::getDestination(uint _flightID) const
{
	return this->m_flightMngPtr->getDestination(_flightID);
}

const string& Manager_t::getFlightNum(uint _flightID) const
{
	return this->m_flightMngPtr->getFlightNum(_flightID);
}

const string& Manager_t::getTimeDeparture(uint _flightID) const
{
	return this->m_flightMngPtr->getTimeDeparture(_flightID);
}

uint Manager_t::numberOfSeatAvalibul(uint _flightID) const
{
	return this->m_flightMngPtr->numberOfSeatAvalibul(_flightID);
}

bool Manager_t::isFlightFull(uint _flightID) const
{
	return this->m_flightMngPtr->isFlightFull(_flightID);
}

const vector<vector<string> > Manager_t::getFreeSeats(uint _flightID, const string& _tier) const
{
	const vector<uint> freeSeats = this->m_flightMngPtr->getFreeSeats(_flightID, _tier);
	return m_reportFormatterPtr->reportFreeSeat(_flightID, freeSeats);
}

uint Manager_t::getTierPrice(uint _flightID, const string& _tier) const
{
	return this->m_flightMngPtr->getTierPrice(_flightID, _tier);
}

uint Manager_t::getSeatPrice(uint _flightID, uint _seatNum) const
{
	return this->m_flightMngPtr->getSeatPrice(_flightID, _seatNum);
}

const vector<string> Manager_t::getTiersNames(uint _flightID) const
{
	return this->m_flightMngPtr->getTiersName(_flightID);
}

bool Manager_t::isSeatOccupancy(uint _flightID, uint _seatNum) const
{
	return this->m_flightMngPtr->isSeatOccupancy(_flightID, _seatNum);
}

const std::string& Manager_t::getSeatName(uint _flightID, uint _seatNum) const
{
	return this->m_flightMngPtr->getSeatName(_flightID, _seatNum);
}

const string& Manager_t::getTierName(uint _flightID, uint _SeatNum) const
{
	return this->m_flightMngPtr->getTierName(_flightID, _SeatNum);
}

const vector<string> Manager_t::getTicketInfo(uint _ticketNum) const
{
	return m_reportFormatterPtr->reportTicket(_ticketNum);
}

uint Manager_t::countTickets() const
{
	return this->m_bookingMngPtr->count();
}

float Manager_t::getBookingCost(uint _ticketNum) const
{
	return this->m_bookingMngPtr->getCost(_ticketNum);
}

uint Manager_t::getBookingFlighId(uint _ticketNum) const
{
	return this->m_bookingMngPtr->getFlighId(_ticketNum);
}

uint Manager_t::getBookingPassangerId(uint _ticketNum) const
{
	return this->m_bookingMngPtr->getPassangerId(_ticketNum);
}

uint Manager_t::getSeatOfBooking(uint _ticketNum) const
{
	return this->m_bookingMngPtr->getSeat(_ticketNum);
}

bool Manager_t::isTicketActive(uint _ticketNum) const
{
	return this->m_bookingMngPtr->isTicketActive(_ticketNum);
}

void Manager_t::deActivateTicket(uint _ticketNum)
{
	return this->m_bookingMngPtr->deActivateTicket(_ticketNum);
}

const vector<vector<string> > Manager_t::getTicketsInfo(uint _passengerID) const
{
	const list<uint>& seats = this->m_passengerMngPtr->getTickets(_passengerID);

	vector<vector<string> > output;
	list<uint>::const_iterator itr = seats.begin();
	while (itr != seats.end() )
	{
		// for every seat, do a nice report and push the vector<string> in to output.
		output.push_back( m_reportFormatterPtr->reportTicket(*itr) );
		++itr;
	}

	return output;
}

bool Manager_t::removeFlight(uint _flightID)
{
	if (! m_flightMngPtr->isFlightExsists(_flightID) )
	{
		return false;
	}

	return m_flightMngPtr->removeFlight(_flightID);
}

bool Manager_t::isPassengerExist(uint _passengerID) const
{
	return this->m_passengerMngPtr->isPassengerExist(_passengerID);
}

const string& Manager_t::getAddress(uint _passengerID) const
{
	return this->m_passengerMngPtr->getAddress(_passengerID);
}

const string& Manager_t::setAddress(uint _passengerID, const string& _address)
{
	return this->m_passengerMngPtr->setAddress(_passengerID, _address);
}

const string& Manager_t::getName(uint _passengerID) const
{
	return this->m_passengerMngPtr->getName(_passengerID);
}

const string& Manager_t::setName(uint _passengerID, const string& name)
{
	return this->m_passengerMngPtr->setName(_passengerID, name);
}

const string& Manager_t::getPhone(uint _passengerID) const
{
	return this->m_passengerMngPtr->getPhone(_passengerID);
}

const string& Manager_t::setPhone(uint _passengerID, const string& phone)
{
	return this->m_passengerMngPtr->setPhone(_passengerID, phone);
}

const string& Manager_t::getPreferanceSeating(uint _passengerID) const
{
	return this->m_passengerMngPtr->getPreferanceSeating(_passengerID);
}

const string& Manager_t::setPreferanceSeating(uint _passengerID, const string& preferanceSeating)
{
	return this->m_passengerMngPtr->setPreferanceSeating(_passengerID, preferanceSeating);
}


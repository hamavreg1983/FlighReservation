/*
 * FlightManager_t.cpp
 *
 *  Created on: Jun 24, 2017
 *      Author: yuval
 */

#include "FlightManager_t.h"
#include "Flight_t.h"

FlightManager_t::FlightManager_t()
{
	// TODO Auto-generated constructor stub

}

FlightManager_t::~FlightManager_t()
{
	// TODO Auto-generated destructor stub

	std::map<uint, Flight_t*>::iterator itr = m_flights.end();
	while (!m_flights.empty())
	{
		itr--;
		delete (*itr).second;
		m_flights.erase(itr);
	}
}

bool FlightManager_t::isEmpty() const
{
	return (bool) ! this->count();
}

uint FlightManager_t::count() const
{
	return m_flights.size();
}

uint FlightManager_t::addFlight(const string& _flightNum,
		const string& _departure, const string& _destination,
		const string& _timeDeparture, const string& _plane)
{
	Flight_t* tmpFlight = new Flight_t(_flightNum, _departure, _destination, _timeDeparture, _plane );
	uint tmpFlightID = tmpFlight->getFlightId();

	std::pair<std::map<uint,Flight_t*>::iterator,bool> ret;
	ret = m_flights.insert( pair<uint,Flight_t*>(tmpFlightID, tmpFlight) );
	if (!ret.second)
	{
		throw "could not add flight";
	}

	return tmpFlightID;

}

bool FlightManager_t::removeFlight(uint _flightID)
{
	// checks if flight exsist and return a pointer for del.
	Flight_t* flightPtr;
	flightPtr = this->findFlight(_flightID); // throw in did not find

	delete flightPtr;
	m_flights.erase(_flightID);
	return true;

}

uint FlightManager_t::getCapacity(uint _flightID) const
{
	return this->findFlight(_flightID)->getCapacity();
}

const string& FlightManager_t::getDeparture(uint _flightID) const
{
	return this->findFlight(_flightID)->getDeparture();
}

void FlightManager_t::setDeparture(uint _flightID, const string& _departure)
{
	return this->findFlight(_flightID)->setDeparture(_departure);
}

const string& FlightManager_t::getDestination(uint _flightID) const
{
	return this->findFlight(_flightID)->getDestination();
}

void FlightManager_t::setDestination(uint _flightID, const string& _destination)
{
	return this->findFlight(_flightID)->setDestination(_destination);
}

const string& FlightManager_t::getFlightNum(uint _flightID) const
{
	return this->findFlight(_flightID)->getFlightNum();
}

void FlightManager_t::setFlightNum(uint _flightID, const string& flightNum)
{
	return this->findFlight(_flightID)->setFlightNum(flightNum);
}

const string& FlightManager_t::getTimeDeparture(uint _flightID) const
{
	return this->findFlight(_flightID)->getTimeDeparture();
}

void FlightManager_t::setTimeDeparture(uint _flightID,
		const string& timeDeparture)
{
	return this->findFlight(_flightID)->setTimeDeparture(timeDeparture);
}

bool FlightManager_t::isTierFull(uint _flightID, const string& _tier) const
{
	return this->findFlight(_flightID)->isTierFull(_tier);
}

uint FlightManager_t::numberOfSeatAvalibul(uint _flightID) const
{
	return this->findFlight(_flightID)->numberOfSeatAvalibul();
}

bool FlightManager_t::isFlightFull(uint _flightID) const
{
	return this->findFlight(_flightID)->isFlightFull();
}

const vector<uint> FlightManager_t::getFreeSeats(uint _flightID,
		const string& _tier) const
{
	return this->findFlight(_flightID)->getFreeSeats(_tier);
}

uint FlightManager_t::getTierPrice(uint _flightID, const string& _tier) const
{
	return this->findFlight(_flightID)->getTierPrice(_tier);
}

uint FlightManager_t::setTierPrice(uint _flightID, const string& _tier,
		uint price)
{
	return this->findFlight(_flightID)->setTierPrice(_tier, price);
}

const vector<string> FlightManager_t::getTiersName(uint _flightID) const
{
	return this->findFlight(_flightID)->getTiersName();
}

bool FlightManager_t::isSeatOccupancy(uint _flightID, uint _seatNum) const
{
	return this->findFlight(_flightID)->isSeatOccupancy(_seatNum);
}

uint FlightManager_t::getTicket(uint _flightID, uint _seatNum) const
{
	return this->findFlight(_flightID)->getTicket(_seatNum);
}

const std::string& FlightManager_t::getSeatName(uint _flightID,
		uint _seatNum) const
{
	return this->findFlight(_flightID)->getSeatName(_seatNum);
}

bool FlightManager_t::orderSeat(uint _flightID, uint _seatNum,
		uint _ticketNum) const
{
	return this->findFlight(_flightID)->orderSeat(_seatNum, _ticketNum);
}

bool FlightManager_t::cancelSeat(uint _flightID, uint _seatNum) const
{
	return this->findFlight(_flightID)->cancelSeat(_seatNum);
}

Flight_t* FlightManager_t::findFlight(uint _flightID) const
{
	map<uint,Flight_t*>::const_iterator itr;

	itr = m_flights.find(_flightID);

	if (itr == m_flights.end() )
	{
		throw "did not find fight asked";
	}
	return (itr == m_flights.end() ) ? 0 : (*itr).second;
}

uint FlightManager_t::getSeatPrice(uint _flightID, uint _seatNum) const
{
	return this->findFlight(_flightID)->getSeatPrice(_seatNum);
}

bool FlightManager_t::isFlightExsists(uint _flightID) const
{
	map<uint,Flight_t*>::const_iterator itr;

	itr = m_flights.find(_flightID);

	return (itr == m_flights.end() ) ? false : true;
}

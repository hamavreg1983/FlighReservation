/*
 * PassengerManagert.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: Yuval Hamberg
 */

#include "PassengerManagert.h"
#include "Passenger_t.h"

PassengerManager_t::PassengerManager_t()
{
}

PassengerManager_t::~PassengerManager_t()
{
}

bool PassengerManager_t::addPassenger(uint _id)
{
	std::pair<std::set<Passenger_t>::iterator,bool> ret;
	ret = m_passengers.insert(_id);

	return ret.second;
}

bool PassengerManager_t::removePassenger(uint _id)
{
	std::set<Passenger_t>::iterator itr;
	itr = find(m_passengers.begin(), m_passengers.end(), _id);

	if (itr == m_passengers.end() ) // notfound
	{
		// throw "asked parameter to remove was not found in container."; // no need for throw just use bool
		return false;
	}

	Passenger_t tempFound = *itr;
	m_passengers.erase(*itr);

	return true;
}

const string& PassengerManager_t::getAddress(uint _passengerID) const
{
	return this->findPassenger(_passengerID).getAddress();

}

const string& PassengerManager_t::getName(uint _passengerID) const
{
	return this->findPassenger(_passengerID).getName();
}


const string& PassengerManager_t::setName(uint _passengerID, const string& _name)
{
	return this->findPassenger(_passengerID).setName(_name);
}

const string& PassengerManager_t::getPhone(uint _passengerID) const
{
	return this->findPassenger(_passengerID).getPhone();
}

const string& PassengerManager_t::setPhone(uint _passengerID, const string& _phone)
{
	return this->findPassenger(_passengerID).setPhone(_phone);
}

const string& PassengerManager_t::getPreferanceSeating(uint _passengerID) const
{
	return this->findPassenger(_passengerID).getPreferanceSeating();
}

const string& PassengerManager_t::setPreferanceSeating(uint _passengerID, const string& preferanceSeating)
{
	return this->findPassenger(_passengerID).setPreferanceSeating(preferanceSeating);
}

void PassengerManager_t::addTicket(uint _passengerID, uint _ticketNum)
{
	return this->findPassenger(_passengerID).addTicket(_ticketNum);
}

uint PassengerManager_t::removeTicket(uint _passengerID, uint _ticketNum)
{
	return this->findPassenger(_passengerID).removeTicket(_ticketNum);
}

const list<uint>& PassengerManager_t::getTickets(uint _passengerID) const
{
	return this->findPassenger(_passengerID).getTickets();
}

bool PassengerManager_t::isPassengerExist(uint _passengerID) const // TODO make sure this function works!
{
	try
	{
		findPassenger(_passengerID);
		return true;
	}
	catch (const char* _ex)
	{
		return false;
	}
}

Passenger_t& PassengerManager_t::findPassenger(uint _id) const
{
	std::set<Passenger_t>::iterator itr;
	itr = find(m_passengers.begin(), m_passengers.end(), _id);

	if (itr == m_passengers.end() )
	{
		throw "asked Passenger to get was not found in container.";
	}

	return (Passenger_t&) *itr; //remove const
}

bool PassengerManager_t::Add(const Passenger_t& _source)
{
	std::pair<std::set<Passenger_t>::iterator,bool> ret;
	m_passengers.insert(_source);

	return ret.second;
}

bool PassengerManager_t::isEmpty()
{
	return m_passengers.empty();
}

uint PassengerManager_t::count() const
{
	return m_passengers.size();
}

bool PassengerManager_t::addPassenger(uint _id, const string _name, const string _address, const string _phone, const string _preferanceSeating)
{
	Passenger_t newPassenger(_id, _name, _address, _phone, _preferanceSeating);

	std::pair<std::set<Passenger_t>::iterator,bool> ret;
	ret = m_passengers.insert(newPassenger);

	return ret.second;
}

const string& PassengerManager_t::setAddress(uint _passengerID,
		const string& _address)
{
	return this->findPassenger(_passengerID).setAddress(_address);
}

void PassengerManager_t::removeAllTicket(uint _passengerID)
{
	return this->findPassenger(_passengerID).removeAllTicket();
}

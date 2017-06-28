/*
 * Passenger_t.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: Yuval Hamberg
 */

#include "Passenger_t.h"

#include <iterator> 	// is needed ?
#include <algorithm>    // std::find

Passenger_t::Passenger_t(uint _id) : m_id(_id)
{
	m_name = "";
	m_address = "";
	m_phone = "";
	m_preferanceSeating = "";
}

Passenger_t::Passenger_t(uint _id, string _name, string _address, string _phone,
		string _preferanceSeating) : m_id(_id)
{
	m_name = _name;
	m_address = _address;
	m_phone = _phone;
	m_preferanceSeating = _preferanceSeating;
}

Passenger_t::~Passenger_t()
{
}

const string& Passenger_t::getAddress() const
{
	return m_address;
}

const string& Passenger_t::setAddress(const string& address)
{
	m_address = address;
	return m_address;

}

const uint Passenger_t::getId() const
{
	return m_id;
}

const string& Passenger_t::getName() const
{
	return m_name;
}

const string& Passenger_t::setName(const string& name)
{
	m_name = name;
	return m_name;
}

const string& Passenger_t::getPhone() const
{
	return m_phone;
}

const string& Passenger_t::setPhone(const string& phone)
{
	m_phone = phone;
	return m_phone;
}

const string& Passenger_t::getPreferanceSeating() const
{
	return m_preferanceSeating;
}

const string&  Passenger_t::setPreferanceSeating(const string& preferanceSeating)
{
	m_preferanceSeating = preferanceSeating;
	return m_preferanceSeating;
}

void Passenger_t::addTicket(uint _ticketNum)
{
	m_tickets.push_front(_ticketNum);
	return;
}

uint Passenger_t::removeTicket(uint _ticketNum)
{
	uint tempFound;
	std::list<uint>::iterator itr;
	itr = find(m_tickets.begin(), m_tickets.end(), _ticketNum);

	if (itr != m_tickets.end() ) // found
	{
		tempFound = *itr;
		m_tickets.remove(*itr);
	}
	else
	{
		throw "asked parameter to remove was not found in container.";
	}

	return tempFound;
}

const list<uint>& Passenger_t::getTickets() const
{
	return m_tickets;
}

bool Passenger_t::operator <(const Passenger_t& _other) const
{
	return m_id < _other.m_id;
}

bool Passenger_t::operator ==(const Passenger_t& _other) const
{
	return m_id == _other.m_id;
}

void Passenger_t::removeAllTicket()
{
	m_tickets.clear();
	return;
}

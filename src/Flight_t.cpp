/*
 * Flight_t.cpp
 *
 *  Created on: Jun 20, 2017
 *      Author: Yuval Hamberg
 */

#include <algorithm>
#include "Flight_t.h"
#include "Tier_t.h"

using namespace std;

uint Flight_t::m_flightSerialID = 0;

//Flight_t::Flight_t() : m_flightID(m_flightSerialID++)
//{
//	m_flightNum = "";
//	m_departure = "";
//	m_destination = "";
//	m_timeDeparture = "";
//	m_capacity = 0;
//}

Flight_t::Flight_t(const string& _flightNum, const string& _departure, const string& _destination, const string& _timeDeparture, const string& _plane )
: m_flightID(++m_flightSerialID)
{
	m_flightNum = _flightNum;
	m_departure = _departure;
	m_destination = _destination;
	m_timeDeparture = _timeDeparture;
	m_capacity = 0;
	m_plane = _plane;

	// TODO function get data from config file
	list<pair<string, uint> > planeData = getPlaneData("PlaneConfig.txt", m_plane);
	createTierSeat(planeData);

}

Flight_t::~Flight_t()
{
	std::vector<Tier_t*>::const_iterator itr = m_tiers.end();
	while (!m_tiers.empty())
	{
		itr--;
		delete *itr;
		m_tiers.pop_back();
	}
}

list<pair<string, uint> > Flight_t:: getPlaneData(const string& _configFile, const string& _planeID)
{
	// TODO call parser
	// TODO remove hardcoded

	list<pair<string, uint> > hardCodedplaneData;
	hardCodedplaneData.push_back(std::make_pair("tier1",10));
	hardCodedplaneData.push_back(std::make_pair("tier2",50));
	hardCodedplaneData.push_back(std::make_pair("Tourist",100));

	return hardCodedplaneData;
}

uint Flight_t:: createTierSeat(const list<pair<string,uint> >& _planeData)
{
	std::list<pair<string,uint> >::const_iterator itr = _planeData.begin();
	uint seatCounter = 1;
	Tier_t* tempTier;
	while (itr !=  _planeData.end() )
	{
		// TODO remove hard coded price
		tempTier = new Tier_t(itr->first , seatCounter , itr->second, 999);

		m_tiers.push_back( tempTier );

		seatCounter += itr->second;
		itr++;
	}
	m_capacity = seatCounter;
	return m_capacity;
}

uint Flight_t::getCapacity() const
{
	return m_capacity;
}

void Flight_t::setCapacity(uint capacity)
{

	m_capacity = capacity;
}

const string& Flight_t::getDeparture() const
{
	return m_departure;
}

void Flight_t::setDeparture(const string& departure)
{
	m_departure = departure;
}

const string& Flight_t::getDestination() const
{
	return m_destination;
}

void Flight_t::setDestination(const string& destination)
{
	m_destination = destination;
}

uint Flight_t::getFlightId() const
{
	return m_flightID;
}

const string& Flight_t::getFlightNum() const
{
	return m_flightNum;
}

void Flight_t::setFlightNum(const string& flightNum)
{
	m_flightNum = flightNum;
}


const string& Flight_t::getTimeDeparture() const
{
	return m_timeDeparture;
}

void Flight_t::setTimeDeparture(const string& timeDeparture)
{
	m_timeDeparture = timeDeparture;
}

bool Flight_t::isTierFull(const string& _tier) const
{
	Tier_t* aTier = findTier(_tier);
	return (bool) ! aTier->numSeatsAvalibul();
}

const std::vector<uint> Flight_t::getFreeSeats(const string& _tier) const
{
	vector<uint> freeSeatContiner;
	Tier_t* aTier = findTier(_tier);
	if (aTier->getCapacity() - aTier->getOccupiedNum() > 0 )
	{
		for (uint i = aTier->getFirstSeatNum() ; i < aTier->getLastSeatNum() ; i++)
		{
			if (! aTier->isOccupied(i) )
			{
				freeSeatContiner.push_back(i);
			}
		}
	}

	return freeSeatContiner;
}

uint Flight_t::getTierPrice(const string& _tier) const
{
	return findTier(_tier)->getPrice();
}

uint Flight_t::setTierPrice(const string& _tier, uint _price)
{
	return findTier(_tier)->setPrice(_price);
}

bool Flight_t::isSeatOccupancy(uint _seatNum) const
{
	return findSeatTier(_seatNum)->isOccupied(_seatNum);
}

uint Flight_t::getTicket(uint _seatNum) const
{
	return findSeatTier(_seatNum)->getTicket(_seatNum);
}

const std::string& Flight_t::getSeatName(uint _seatNum) const
{
	return findSeatTier(_seatNum)->getSeatName(_seatNum);
}

Tier_t* Flight_t:: findTier(const string& _tier) const
{
	for (uint i = 0; i < m_tiers.size() ; i++)
	{
		if (m_tiers[i]->getTierId() == _tier)
		{
			return m_tiers[i];
		}
	}

	throw "asked parameter to get was not found in container.";

	return 0;
}

bool Flight_t::orderSeat(uint _seatNum, uint _ticketNum) const
{
	return findSeatTier(_seatNum)->orderSeat(_seatNum, _ticketNum);
}

bool Flight_t::cancelSeat(uint _seatNum) const
{
	return findSeatTier(_seatNum)->cancelSeat(_seatNum);
}

bool Flight_t::isFlightFull() const
{
	return !numberOfSeatAvalibul();
}

uint Flight_t::numberOfSeatAvalibul() const
{
	uint freeSeats = 0;
	for (uint i = 0; i < m_tiers.size() ; i++)
	{
		freeSeats += m_tiers[i]->numSeatsAvalibul();
	}
	return freeSeats;
}

const vector<string> Flight_t::getTiersName() const
{
	std::vector<string> tiersOnFligth;
	string tempTierName;
	for (uint i = 0; i < m_tiers.size() ; i++)
	{
		tempTierName = m_tiers[i]->getTierId();
		tiersOnFligth.push_back(tempTierName);
	}
	return tiersOnFligth;
}

uint Flight_t::getFlightStaticID()
{
	return m_flightSerialID;
}

Tier_t* Flight_t:: findSeatTier(uint _seatNum) const
{
	for (uint i = 0; i < m_tiers.size() ; i++)
	{
		if ( m_tiers[i]->isSeatNumInTier(_seatNum) )
		{
			return m_tiers[i];
		}
	}

	throw "asked parameter to get was not found in container.";

	return 0;
}

const string& Flight_t::getTierName(uint _seatNum) const
{
	return this->findSeatTier(_seatNum)->getTierId();
}

uint Flight_t::getSeatPrice(uint _seatNum) const
{
	return this->findSeatTier(_seatNum)->getPrice();
}

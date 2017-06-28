/*
 * Flight_t.h
 *
 *  Created on: Jun 20, 2017
 *      Author: Yuval Hamberg
 */

#ifndef FLIGHT_T_H_
#define FLIGHT_T_H_

#include <string>
#include <vector>
#include <set>

#include <list>
using namespace std;

typedef unsigned int uint;

class Tier_t;

class Flight_t
{
	public:

//		Flight_t();
		Flight_t(const string& _flightNum, const string& _departure, const string& _destination, const string& _timeDeparture, const string& _plane );
		virtual ~Flight_t();

		uint getCapacity() const;
		void setCapacity(uint capacity);
		const string& getDeparture() const;
		void setDeparture(const string& departure);
		const string& getDestination() const;
		void setDestination(const string& destination);
		uint getFlightId() const;
		const string& getFlightNum() const;
		void setFlightNum(const string& flightNum);
		const string& getTimeDeparture() const;
		void setTimeDeparture(const string& timeDeparture);

		bool isTierFull(const string& _tier) const;
		uint numberOfSeatAvalibul() const;
		bool isFlightFull() const;
		const vector<uint> getFreeSeats(const string& _tier) const;
		uint getTierPrice(const string& _tier) const;
		uint setTierPrice(const string& _tier, uint price);
		const vector<string> getTiersName() const;

		const string& getTierName(uint _seatNum) const;
		uint getSeatPrice(uint _seatNum) const;

		bool isSeatOccupancy(uint _seatNum) const;
		uint getTicket(uint _seatNum) const;
		const std::string& getSeatName(uint _seatNum) const;

		bool orderSeat(uint _seatNum, uint _ticketNum) const;
		bool cancelSeat(uint _seatNum) const;

		static uint getFlightStaticID();
	protected:

	private:
		list<pair<string,uint> > getPlaneData(const string& _configFile, const string& _planeID);
		uint createTierSeat(const list<pair<string,uint> >& _planeData);
		Tier_t* findTier(const string& _tier) const;
		Tier_t* findSeatTier(uint _seatNum) const;

		static uint m_flightSerialID;
		const uint m_flightID;
		string m_flightNum;
		string m_departure;
		string m_destination;
		string m_timeDeparture;//(date?)
		uint m_capacity;
		string m_plane;
		vector<Tier_t*> m_tiers;

};

#endif /* FLIGHT_T_H_ */

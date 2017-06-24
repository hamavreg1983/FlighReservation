/*
 * Tier_t.h
 *
 *  Created on: Jun 21, 2017
 *      Author: Yuval Hamberg
 */

#ifndef TIER_T_H_
#define TIER_T_H_

#include <vector>
#include <string>

typedef unsigned int uint;
using namespace std;

class Seat_t;

class Tier_t
{
	public:
		Tier_t(string _tierID, uint _firstSeatNum, uint _capacity, uint _price);
		virtual ~Tier_t();
		Tier_t(const Tier_t& _source);

		uint getCapacity() const;
		uint getOccupiedNum() const;
		uint numSeatsAvalibul() const;
		uint getPrice() const;
		uint setPrice(uint price);
		uint getFirstSeatNum() const;
		uint getLastSeatNum() const;

		bool isSeatNumInTier(uint _seat) const;
		const string& getTierId() const;

		bool operator== (const string& _id) const;

		bool isOccupied(uint _seatNum) const;
		uint getTicket(uint _seatNum) const;
		const std::string& getSeatName(uint _seatNum) const;
		bool orderSeat(uint _seatNum, uint _ticketNum);
		bool cancelSeat(uint _seatNum);

	private:
		const Tier_t& operator=(const Tier_t& _source);
		Seat_t& getSeat(uint _seatNum) const;

		const string m_tierID;
		const uint m_firstSeatNum;
		const uint m_capacity;
		uint m_occupiedNum;
		vector<Seat_t> m_seats;
		uint m_price;

};


#endif /* TIER_T_H_ */

/*
 * Seat_t.h
 *
 *  Created on: Jun 20, 2017
 *      Author: Yuval Hamberg
 */

#ifndef SEAT_T_H_
#define SEAT_T_H_

#include <string>
typedef unsigned int uint;
using namespace std;

class Booking;

class Seat_t
{
	public:
//		Seat_t();
		Seat_t(uint _seatNum);
		virtual ~Seat_t();

		bool operator== (const Seat_t& _other) const;
		bool isOccupied() const;
		bool orderSeat(uint _ticketNum);
		bool cancelSeat();

		uint getTicket() const;
		uint setTicket(uint _ticketNum);

		const std::string& getSeatName() const;
		const uint getSeatNum() const;

		static uint m_seatNumItr;


	private:
		bool setOccupancy(bool _occupancyStatus);
		std::string itos(int _num);

		uint m_seatNum;
		std::string m_seatName;
		bool m_occupancy;
		uint m_ticket;
};

#endif /* SEAT_T_H_ */

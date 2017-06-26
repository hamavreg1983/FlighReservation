/*
 * Booking_t.h
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#ifndef BOOKING_T_H_
#define BOOKING_T_H_


typedef unsigned int uint;
using namespace std;

class Booking_t
{

	public:

		Booking_t();
		Booking_t(uint _flighID, uint _seat, uint _passangerId, float _cost);

		virtual ~Booking_t();

		float getCost() const;
		float setCost(float cost);
		uint getFlighId() const;
		uint setFlighId(uint flighId);
		uint getPassangerId() const;
		uint setPassangerId(uint passangerId);
		uint getSeat() const;
		uint setSeat(uint seat);

		bool isTicketActive() const;
		bool activateTicket();
		bool deActivateTicket();

		static uint getStaticUniqeTicketNum();
		uint getTicketNum() const;

		static uint m_staticUniqeTicketNum;

	private:
		const uint m_ticketNum;
		uint m_flighID;
		uint m_seat;
		uint m_passangerId;
		float m_cost;
		bool m_isActiveTicket; // historical ticket is false

		/* Disable the following by default */
		Booking_t(const Booking_t& other);
		Booking_t& operator=(const Booking_t&);

};

#endif /* ifndef BOOKING_T_H_ */

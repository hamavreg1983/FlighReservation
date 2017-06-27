/*
 * BookingManager_t.h
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#ifndef BOOKINGMANAGER_T_H_
#define BOOKINGMANAGER_T_H_

#include <map>

typedef unsigned int uint;
using namespace std;

class Booking_t;

class BookingManager_t
{

	public:

		/* Default Constructor */
		BookingManager_t();

		/* Deconstructor */
		virtual ~BookingManager_t();

		uint addTicket(uint _flighID, uint _seat, uint _passangerId, float _cost);
		bool removeTicket(uint _ticketNum);

		bool isEmpty() const;
		uint count() const;

		float getCost(uint _ticketNum) const;
		float setCost(uint _ticketNum, float cost);
		uint getFlighId(uint _ticketNum) const;
		uint getPassangerId(uint _ticketNum) const;
		uint getSeat(uint _ticketNum) const;

		bool isTicketActive(uint _ticketNum) const;
		void deActivateTicket(uint _ticketNum);

		uint getTotalTicketNum() const;

	private:
		map<uint, Booking_t*> m_bookings;
		void activateTicket(uint _ticketNum);

		Booking_t* findTicket(uint _ticketNum) const;

		/* Disable the following by default */
		BookingManager_t(const BookingManager_t& other);
		BookingManager_t& operator=(const BookingManager_t&);

};

#endif /* ifndef BOOKINGMANAGER_T_H_ */

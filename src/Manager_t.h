/*
 * Manager_t.h
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#ifndef MANAGER_T_H_
#define MANAGER_T_H_

typedef unsigned int uint;
using namespace std;

class FlightManager_t;
class PassengerManager_t;
class BookingManager_t;

class Manager_t
{

	public:
		Manager_t();
		virtual ~Manager_t();

		// flights function


		// passenger function


		// booking function
		uint addTicket(uint _flighID, uint _seat, uint _passangerId, float _cost);
		bool removeTicket(uint _ticketNum);
		bool isBookingEmpty() const;
		uint countBookings() const;
		float getBookingCost(uint _ticketNum) const;
		float setBookingCost(uint _ticketNum, float cost);
		uint getBookingFlighId(uint _ticketNum) const;
		uint getBookingPassangerId(uint _ticketNum) const;
		uint getBookingSeat(uint _ticketNum) const;
		bool isTicketActive(uint _ticketNum) const;
		void deActivateTicket(uint _ticketNum);

	private:
		FlightManager_t* m_flightMngPtr;
		PassengerManager_t* m_passengerMngPtr;
		BookingManager_t* m_bookingMngPtr;

		/* Disable the following by default */
		Manager_t(const Manager_t& other);
		Manager_t& operator=(const Manager_t&);

};

#endif /* ifndef MANAGER_T_H_ */

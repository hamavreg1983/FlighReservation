/*
 * Manager_t.h
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#ifndef MANAGER_T_H_
#define MANAGER_T_H_

#include <string>

typedef unsigned int uint;
using namespace std;

class FlightManager_t;
class PassengerManager_t;
class BookingManager_t;
class Communicator_t;

class Manager_t
{

	public:
		Manager_t(); // TODO should i remove?
		Manager_t(Communicator_t* _commPtr);
		virtual ~Manager_t();
		void setCommunicator(Communicator_t* _commPtr);

		// general Manger function
		uint order(uint flightID, uint _seatNum, uint _passengerID); // return ticket number
		bool cancelTicket(uint _ticketNum);
		void passenger(uint _id, const string _name, const string _address, const string _phone, const string _preferanceSeating); //create if needed update of not
		bool removePassenger(uint _passengerID);

		//findFlight(tempalte X) : list of flights // TODO





		// flights function


		// passenger function


		// booking function
//		uint addTicket(uint _flighID, uint _seat, uint _passangerId, float _cost);
//		bool removeTicket(uint _ticketNum);
//		bool isBookingEmpty() const;
//		uint countBookings() const;
//		float getBookingCost(uint _ticketNum) const;
//		float setBookingCost(uint _ticketNum, float cost);
//		uint getBookingFlighId(uint _ticketNum) const;
//		uint getBookingPassangerId(uint _ticketNum) const;
//		uint getBookingSeat(uint _ticketNum) const;
//		bool isTicketActive(uint _ticketNum) const;
//		void deActivateTicket(uint _ticketNum);


		// TODO move those to protected
		uint addFlight(const string& _flightNum, const string& _departure, const string& _destination, const string& _timeDeparture, const string& _plane );		// make friend to supervisor
		bool updateFlight(uint flightID, const string& _flightNum, const string& _departure, const string& _destination, const string& _timeDeparture);		// make friend to supervisor
		bool removeFlight(uint _flightID); 		// make friend to supervisor

	protected:

	private:
		FlightManager_t* m_flightMngPtr;
		PassengerManager_t* m_passengerMngPtr;
		BookingManager_t* m_bookingMngPtr;
		Communicator_t* m_commPtr;

		/* Disable the following by default */
		Manager_t(const Manager_t& other);
		Manager_t& operator=(const Manager_t&);

};

#endif /* ifndef MANAGER_T_H_ */

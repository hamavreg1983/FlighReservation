/*
 * Manager_t.h
 *
 *  Created on: Jun 25, 2017
 *      Author: uv
 */

#ifndef MANAGER_T_H_
#define MANAGER_T_H_

#include <string>
#include <vector>

typedef unsigned int uint;
using namespace std;

class FlightManager_t;
class PassengerManager_t;
class BookingManager_t;
class ReportFormatter_t;
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
		const string& getDeparture(uint _flightID) const;
		const string& getDestination(uint _flightID) const;
		const string& getFlightNum(uint _flightID) const;
		const string& getTimeDeparture(uint _flightID) const;
		uint numberOfSeatAvalibul(uint _flightID) const;
		bool isFlightFull(uint _flightID) const;
		// TODO devide to get seatInfo, than i can do it for all sort and quntity
		const vector<vector<string> > getFreeSeats(uint _flightID, const string& _tier) const;
		uint getTierPrice(uint _flightID, const string& _tier) const;
		uint getSeatPrice(uint _flightID, uint _seatNum) const;
		const vector<string> getTiersNames(uint _flightID) const;
		const string& getTierName(uint _flightID, uint _SeatNum) const;
		bool isSeatOccupancy(uint _flightID, uint _seatNum) const;
		const std::string& getSeatName(uint _flightID, uint _seatNum) const;

//		const vector<string> getflightInfo(uint _flightID) const; // TODO
//		const vector<vector<string> > getflightsInfo(uint _flightID) const; // TODO

		// passenger function
		bool isPassengerExist(uint _passengerID) const;
		const string& getAddress(uint _passengerID) const;
		const string& setAddress(uint _passengerID, const string& _address);
		const string& getName(uint _passengerID) const;
		const string& setName(uint _passengerID, const string& name);
		const string& getPhone(uint _passengerID) const;
		const string& setPhone(uint _passengerID, const string& phone);
		const string& getPreferanceSeating(uint _passengerID) const;
		const string& setPreferanceSeating(uint _passengerID, const string& preferanceSeating);

		const vector<vector<string> > getTicketsInfo(uint _passengerID) const;


		// booking function
		const vector<string> getTicketInfo(uint _ticketNum) const;
		uint countTickets() const;
		float getBookingCost(uint _ticketNum) const;
		uint getBookingFlighId(uint _ticketNum) const;
		uint getBookingPassangerId(uint _ticketNum) const;
		uint getSeatOfBooking(uint _ticketNum) const;
		bool isTicketActive(uint _ticketNum) const;
		void deActivateTicket(uint _ticketNum); // Supervisor

		// TODO move those to protected
		uint addFlight(const string& _flightNum, const string& _departure, const string& _destination, const string& _timeDeparture, const string& _plane );		// make friend to supervisor
		bool updateFlight(uint flightID, const string& _flightNum, const string& _departure, const string& _destination, const string& _timeDeparture);		// make friend to supervisor
		bool removeFlight(uint _flightID); 		// make friend to supervisor

	protected:

	private:
		FlightManager_t* m_flightMngPtr;
		PassengerManager_t* m_passengerMngPtr;
		BookingManager_t* m_bookingMngPtr;
		ReportFormatter_t* m_reportFormatterPtr;
		Communicator_t* m_commPtr;

		/* Disable the following by default */
		Manager_t(const Manager_t& other);
		Manager_t& operator=(const Manager_t&);

};

#endif /* ifndef MANAGER_T_H_ */

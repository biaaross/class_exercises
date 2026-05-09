#include "flight.h"
#include <iostream>
#include <string>
#include <fstream>


Flight::Flight(const std::string& pN,const std::string& fN,const std::string& sN,double tP)
    : passengerName(pN) , flightName(fN) , seatNumber(sN) , ticketPrice(tP) {};

Flight::~Flight() {
    std::cout<<"Data Deleted"<<std::endl;
    }


    void Flight::printTicket() {
        std::cout<<"Flight Information"<<std::endl;
        std::cout<<"Passenger Name"<<passengerName
                 <<"Flight Name"<<flightName
                 <<"Seat Number"<<seatNumber
                 <<"Ticket Price"<<ticketPrice<<std::endl;
    }

void Flight::saveTicket(const std::string& fileName) {
    std::ofstream flightFile(fileName,std::ios::app);

    if(!flightFile) {
        std::cerr<<"File Not Opened"<<std::endl;
        return; 
    }

    flightFile<<"Passenger Name"<<passengerName
              <<" | Flight Name"<<flightName
              <<" | Seat Number"<<seatNumber
              <<" | Ticket Price"<<ticketPrice<<std::endl;
    }











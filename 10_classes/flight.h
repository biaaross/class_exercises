#pragma once
#include <string>

class Flight {
    private:
    std::string passengerName;
    std::string flightName;
    std::string seatNumber;
    double ticketPrice;

    public:
    Flight(const std::string& pN,const std::string& fN,const std::string& sN,double tP);
    ~Flight();

    void printTicket(); 
    void saveTicket(const std::string& fileName);
};



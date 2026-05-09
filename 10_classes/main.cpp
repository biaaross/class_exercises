#pragma once
#include <string>

class Flight {
private:
    std::string passengerName;
    std::string flightNumber;
    std::string seatNumber;
    double ticketPrice;

public:
    Flight(const std::string& pName, const std::string& fNum, const std::string& sNum, double price);
    
    ~Flight();

    void printTicket() const;
    void saveTicket(const std::string& fileName) const;
};

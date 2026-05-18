#include "bus.h"
#include <iostream>
#include <string>

Bus::Bus(std::string id,double t,double e,int c) 
 : Vehicle(id,t,e) , passengerCount(c) {};

Bus::~Bus() {
    std::cout<<"ID:"<<unitId
             <<"[DESTROYED]"<<std::endl;
}

double Bus::calculateCarbonFootprint() const {
    return distanceTraveled * fuelEfficiency * 0.12;

}

std::string Bus::getType() const {
    return "BUS";
}

std::string Bus::serialize() const {
    return "Bus," + unitId + "," + std::to_string(distanceTraveled) + "," + 
           std::to_string(fuelEfficiency) + "," + std::to_string(passengerCount);
}
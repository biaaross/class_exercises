#include "metro.h"
#include <iostream>
#include <string>

Metro::Metro(std::string id,double t,double e,int w) 
 : Vehicle(id,t,e) , wagonCount(w) {};

Metro::~Metro() {
    std::cout<<"ID:"<<unitId
             <<"[DESTROYED]"<<std::endl;
}

double Metro::calculateCarbonFootprint() const {
    return distanceTraveled * fuelEfficiency * 0.05;

}

std::string Metro::getType() const {
    return "METRO";
}

std::string Metro::serialize() const {
    return "Metro," + unitId + "," + std::to_string(distanceTraveled) + "," + 
           std::to_string(fuelEfficiency) + "," + std::to_string(wagonCount);
}


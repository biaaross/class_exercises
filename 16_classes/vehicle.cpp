#include "vehicle.h"
#include <iostream>
#include <string>

Vehicle::Vehicle(std::string id,double t,double e) 
    : unitId(id) , distanceTraveled(t) , fuelEfficiency(e) {};
    
Vehicle::~Vehicle() {
    std::cout<<"ID:"<<unitId
             <<"[DESTROYED]"<<std::endl;
}

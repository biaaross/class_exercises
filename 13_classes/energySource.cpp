#include "energySource.h"
#include <iostream>
#include <string>

EnergySource::EnergySource(std::string n,double c) 
 : sourceName(n) , capacity(c) {}
 
EnergySource::~EnergySource() {
    std::cout<<"Source Name:"<<sourceName
             <<"Capacity"<<capacity
             <<"[DELETED]"<<std::endl;
}

std::string EnergySource::getSourceName() const {
     return sourceName; 
};


void EnergySource::showDetails() {
    std::cout<<"Source Name:"<<sourceName
             <<"Capacity"<<capacity<<std::endl;
}

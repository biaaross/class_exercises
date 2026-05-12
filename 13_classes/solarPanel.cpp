#include "solarPanel.h"
#include <iostream>
#include <string>


SolarPanel::SolarPanel(std::string n,double c,double  r)
 : EnergySource(n,c) , efficiencyRate(r) {};


SolarPanel::~SolarPanel() {
    std::cout<<"Source Name:"<<sourceName
             <<"Capacity"<<capacity
             <<"Efficiency Rate:"<<efficiencyRate
             <<"[DELETED]"<<std::endl;
}



void SolarPanel::calculateOutput() {
    double result = capacity * efficiencyRate;
    std::cout<<"[Solar]"<<sourceName<<"[Estimated Production]"<<result<<" kWh"<<std::endl;
}


void SolarPanel::showDetails() {
    std::cout <<"Source Name:"<<sourceName
              <<"Capacity"<<capacity
              <<" | Productivity: %" << (efficiencyRate * 100)
              <<std::endl;
}
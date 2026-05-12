#include "windTurbine.h"
#include <iostream>
#include <string>

WindTurbine::WindTurbine(std::string n,double c,double s)
 : EnergySource(n,c) , windSpeed(s) {};
 
 WindTurbine::~WindTurbine() {
     std::cout<<"Source Name:"<<sourceName
             <<"Capacity"<<capacity
             <<"Wind Speed:"<<windSpeed
             <<"[DELETED]"<<std::endl;
 }

 void WindTurbine::calculateOutput() {
    double result = capacity * (windSpeed / 10.0);
     std::cout<<"[Wind:]"<<sourceName<<"[Estimated Production]"<<result<<" kWh"<<std::endl;
 }


 void WindTurbine::showDetails() {
    EnergySource::showDetails(); 
    std::cout << " | Wind Speed: " << windSpeed << " m/s" << std::endl;
}
 
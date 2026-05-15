#include "CargoSystem.hpp"
#include <string>
#include <iostream>

Cargo::Cargo(std::string pn,double w,std::string tn)
     : productName(pn) , weight(w) , trackingNumber(tn) {};

Cargo::~Cargo() {
    std::cout<<"Tracking Number:"<<trackingNumber
             <<"[DESTROYED]"<<std::endl;
}


#include "doctor.h"
#include <iostream>
#include <string>

Doctor::Doctor(std::string n,std::string b)
 : doctorName(n) , branch(b) {};

 Doctor::~Doctor() {
    std::cout<<"Doctor tName: | "<< doctorName
             <<"Branch"<< branch
             <<"[DELETED]"<<std::endl;
 }

 
    std::string Doctor::getName() const {
        return doctorName;
    }

    
    std::string Doctor::getBranch() const {
        return branch;
    }
 


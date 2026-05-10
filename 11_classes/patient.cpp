#include "patient.h"
#include <iostream>
#include <string>

Patient::Patient(std::string n,std::string c) 
 : patientName(n) , complaint(c) {};

 Patient::~Patient() {
    std::cout<<"Patient Name: | "<< patientName
             <<"complaint"<< complaint
             <<"[DELETED]"<<std::endl;
             
 }

    std::string Patient::getName() const {
        return patientName;
    }

    
    std::string Patient::getComplaint() const {
        return complaint;
    }
 
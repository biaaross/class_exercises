#include "appointmen.h"
#include <iostream>

Appointment::Appointment(Patient* p, Doctor* d, std::string dt)
    : pPtr(p), dPtr(d), date(dt) {
    std::cout << "[SYSTEM]: Appointment record successfully created." << std::endl;
}

Appointment::~Appointment() {
    std::cout << "[SYSTEM]: Appointment document destroyed." << std::endl;
}

void Appointment::showAppointmentInfo() const {
    std::cout << "\n========== APPOINTMENT DETAILS ==========" << std::endl;
    std::cout << "DATE      : " << date << std::endl;
    
    if (pPtr != nullptr) {
        std::cout << "PATIENT   : " << pPtr->getName() 
                  << " (Complaint: " << pPtr->getComplaint() << ")" << std::endl;
    } else {
        std::cout << "PATIENT   : No patient assigned!" << std::endl;
    }
    
    if (dPtr != nullptr) {
        std::cout << "DOCTOR    : " << dPtr->getName() 
                  << " (Branch: " << dPtr->getBranch() << ")" << std::endl;
    } else {
        std::cout << "DOCTOR    : No doctor assigned!" << std::endl;
    }
    std::cout << "=========================================\n" << std::endl;
}


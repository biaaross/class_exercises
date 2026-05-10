#pragma once
#include <string>
#include "patient.h" 
#include "doctor.h"

class Appointment {
    private:
    Patient* pPtr;
    Doctor* dPtr;
    std::string date;

    public:
    Appointment(Patient* p,Doctor* d,std::string da);
    ~Appointment();

    void showAppointmentInfo() const;
};
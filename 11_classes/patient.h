#pragma once
#include <string>

class Patient {
    protected:
    std::string patientName;
    std::string complaint;

    public:
    Patient(std::string n,std::string c);
    ~Patient();

    std::string getName() const;
    std::string getComplaint() const;
};
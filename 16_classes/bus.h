#pragma once
#include "vehicle.h"
#include <string>

class Bus : public Vehicle {
    private:
    int passengerCount;

    public:
    Bus(std::string id,double t,double e,int c);
    ~Bus();
    double calculateCarbonFootprint() const override;
    std::string getType() const override;
    std::string Bus::serialize() const override;
};
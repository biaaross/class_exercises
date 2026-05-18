#pragma once
#include "vehicle.h"
#include <string>

class Metro : public Vehicle {
    private:
    int wagonCount;

    public:
    Metro(std::string id,double t,double e,int w);
    ~Metro();
    double calculateCarbonFootprint() const override;
    std::string getType() const override;
    std::string Metro::serialize() const;
};
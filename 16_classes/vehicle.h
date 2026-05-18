#pragma once
#include <string>

class Vehicle {
    protected:
    std::string unitId;
    double distanceTraveled;
    double fuelEfficiency;

    public:
    Vehicle(std::string id,double t,double e);
    virtual ~Vehicle();

    virtual double calculateCarbonFootprint() const = 0;
    virtual std::string getType() const = 0;
    virtual std::string serialize() const = 0;
};

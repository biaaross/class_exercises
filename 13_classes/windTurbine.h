#pragma once
#include "energySource.h"
#include <string>

class WindTurbine : public EnergySource {
    private:
    double windSpeed;

    public:
    WindTurbine(std::string n,double c,double s);
    ~WindTurbine();

    virtual void calculateOutput() override; 
    void showDetails() override;
};
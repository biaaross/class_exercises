#pragma once
#include "energySource.h"
#include <string>

class SolarPanel : public EnergySource {
    private:
    double efficiencyRate;

    public:
    SolarPanel(std::string n,double c,double r);
    ~SolarPanel();

    
    void calculateOutput() override;
    void showDetails() override;
};
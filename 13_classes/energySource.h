#pragma once
#include <string>

class EnergySource {
protected:
std::string sourceName;
double capacity;

public:
EnergySource(std::string n,double c);
virtual ~EnergySource();

std::string getSourceName() const;
virtual void calculateOutput() = 0;
virtual void showDetails();
};
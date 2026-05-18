#pragma once
#include <string>

class Cargo {
    protected:
    std::string productName;
    double weight;
    std::string trackingNumber;

    public:
    Cargo(std::string pn,double w,std::string tn);
    virtual ~Cargo();
    virtual std::string serialize() const  = 0;
    virtual void rapor() const = 0; 
};

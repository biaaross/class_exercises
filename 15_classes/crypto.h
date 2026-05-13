#pragma once
#include "asset.h"
#include <string>


class Crypto : public Asset {
    private:
    double coinAmount;
    double coinPrice;

    public:
    Crypto(std::string n,double b,std::string c,double coinAmount,double coinPrice);
    ~Crypto();
     double calculateValue() override;
    void display() override;
    std::string serialize() const override;    
};

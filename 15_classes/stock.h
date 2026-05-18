#pragma once
#include "asset.h"
#include <string>

class Stock : public Asset {
    private:
    int shareCount;
    double sharePrice;

    public:
    Stock(std::string n,double b,std::string c,int sc,double cp);
    ~Stock();

    double calculateValue() override;
    void display() override;
    std::string serialize() const override;    
};
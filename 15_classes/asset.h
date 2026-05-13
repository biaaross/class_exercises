#pragma once
#include <string>

class Asset {
    protected:
    std::string name;
    double balance;
    std::string currency;

    public:
    Asset(std::string n,double b,std::string c);
    ~Asset();
    virtual double calculateValue() = 0;
    virtual void display() = 0;
    virtual std::string serialize() const = 0;
};
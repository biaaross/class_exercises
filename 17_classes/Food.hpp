#pragma once
#include "CargoSystem.hpp"
#include <string>

class Food : public Cargo {
    private:
     std::string expirationDate;
    public:
    Food(std::string pn,double w,std::string tn,std::string ed);
    ~Food();
    
    std::string serialize() const override;
    void rapor() const override; 
};
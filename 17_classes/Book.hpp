#pragma once
#include "CargoSystem.hpp"
#include <string>

class Book : public Cargo {
    public:
    Book(std::string pn,double w,std::string tn);
    ~Book();
    
    std::string serialize() const override;
    void rapor() const override; 
};
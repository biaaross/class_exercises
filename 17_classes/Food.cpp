#include "Food.hpp"
#include <iostream>
#include <string>

Food::Food(std::string pn,double w,std::string tn,std::string ed)
     : Cargo(pn,w,tn) , expirationDate(ed) {};

Food::~Food() {};

std::string Food::serialize() const {
    return "FOOD" + productName + "|" + trackingNumber + "|" + expirationDate ; 
}

void Food::rapor() const {
    std::cout << "FOOD CARGO -> Product: " << productName 
              << " | Expiration Date: " << expirationDate << std::endl;
}
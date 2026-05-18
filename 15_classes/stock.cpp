#include "stock.h"
#include <iostream>
#include <string>
#include <fstream>

    Stock::Stock(std::string n,double b,std::string c,int sc,double cp)

     : Asset(n,b,c) , shareCount(sc) , sharePrice(cp) {} 
     
     Stock::~Stock() {
        std::cout<<"Share Count:"<<shareCount
                 <<"[DESTROYED]"<<std::endl;
     }

     double Stock::calculateValue() {
return shareCount * sharePrice;
     }

std::string Stock::serialize() const {
    return "1," + name + "," + std::to_string(balance) + "," + currency + "," 
           + std::to_string(shareCount) + "," + std::to_string(sharePrice);
}
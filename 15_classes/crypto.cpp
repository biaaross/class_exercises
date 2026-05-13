#include "crypto.h"
#include <iostream>
#include <string>
#include <fstream>


    Crypto::Crypto(std::string n,double b,std::string c,double ca,double cp)

     : Asset(n,b,c) , coinAmount(ca), coinPrice(cp) {} 
     
     Crypto::~Crypto() {
        std::cout<<"Coin amount:"<<coinAmount
                 <<"[DESTROYED]"<<std::endl;
     }

     double Crypto::calculateValue() {
return coinAmount * coinPrice;
     }

std::string Crypto::serialize() const {
    return "2," + name + "," + std::to_string(balance) + "," + currency + "," 
           + std::to_string(coinAmount) + "," + std::to_string(coinPrice);
}

 
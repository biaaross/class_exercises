#include "asset.h"
#include <iostream>
#include <string>

Asset::Asset(std::string n,double b,std::string c)
 : name(n) , balance(b) , currency(c) {};

 Asset::~Asset() {
    std::cout<<"ASSET:"<<name
             <<"[DESTORYED]"<<std::endl;
 }

 
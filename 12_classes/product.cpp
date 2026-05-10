#include "product.h"
#include <string>
#include <iostream>


Product::Product(std::string n,double p) 
    : name(n) , price(p) {};


    Product::~Product() {
    std::cout<<"Name: | "<< name
             <<"Price:"<<price
             <<"[DELETED]"<<std::endl;
};

std::string Product::getName() const {
    return name;
}

double Product::getPrice() const {
    return price;
}



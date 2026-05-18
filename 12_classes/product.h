#pragma once
#include <string>

class Product {
    protected:
    std::string name;
    double price;

    public:
    Product(std::string n,double p);
    ~Product();

    std::string getName() const;
    double getPrice() const;
};
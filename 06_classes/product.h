#pragma once
#include <string>

class product {
private:
    std::string name;
    int quantity;
    double price;

public:
    product(); // Default constructor (dizi için şart)
    product(std::string n, int q, double p);

    std::string getName() const;
    int getQuantity() const;
    double getPrice() const;

    void setQuantity(int newQuantity);
    std::string toFileString() const;
};
#include "product.h"
#include <string>

product::product() : name(""), quantity(0), price(0.0) {}

product::product(std::string n, int q, double p) 
    : name(n), quantity(q), price(p) {}

std::string product::getName() const { return name; }
int product::getQuantity() const { return quantity; }
double product::getPrice() const { return price; }

void product::setQuantity(int newQuantity) {
    quantity = (newQuantity < 0) ? 0 : newQuantity;
}

std::string product::toFileString() const {
    return name + ";" + std::to_string(quantity) + ";" + std::to_string(price);
}
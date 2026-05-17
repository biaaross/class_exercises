#include "Order.hpp"
#include <string>
#include <iostream>

Order::Order() {}
Order::Order(std::string id,std::string s,double p,int q, OrderType t) 
    : orderId(id) , symbol(s) , price(p) , quantity(q) , type(t) {} // Orijinal başlatma listene type eklendi

Order::~Order() {
    std::string side = (type == OrderType::BUY) ? "BUY" : "SELL";

    std::cout<<orderId<<" | "
             <<symbol<<" | "
             <<side<<" | " 
             <<price<<" | "
             <<quantity<<" | "
             <<"[DESTROYED]"<<std::endl;
}

std::string Order::getId() const {
    return orderId;
}


std::string Order::getSymbol() const {
    return symbol;
}


double Order::getPrice() const {
    return price;
}


int Order::getQuantity() const {
    return quantity;
}

OrderType Order::getType() const {
    return type;
}


void Order::setId(const std::string& newId) {
    if(!newId.empty()) {
        orderId = newId;
        return;
    }
        std::cerr<<"[INVALID --- NewId Is Empty]"<<std::endl;
}


void Order::setSymbol(const std::string& newSymbol) {
    if(!newSymbol.empty()) {
        symbol= newSymbol;
        return;
    }
        std::cerr<<"[INVALID --- NewSymbol Is Empty]"<<std::endl;
}


void Order::setPrice(double newPrice) {
    if(newPrice>=0) {
        price = newPrice;
        return;
    }
        std::cerr<<"[INVALID VALUE]"<<std::endl;
}



void Order::setQuantity(int newQuantity) {
    if(newQuantity>=0) {
        quantity = newQuantity;
        return;
    }
        std::cerr<<"[INVALID VALUE]"<<std::endl;
}
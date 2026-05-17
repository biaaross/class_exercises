#pragma once
#include <string>
#include "Order.hpp"
#include <iostream>

class LimitOrder : public Order {
    public:
    LimitOrder();
    LimitOrder(std::string id,std::string s,double p,int q, OrderType t);
    ~LimitOrder();

    void executeOrder(int matchedQty);
    std::string getOrderDetails() const;

};
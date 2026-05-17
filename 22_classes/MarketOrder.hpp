#pragma once
#include <string>
#include <iostream>
#include "Order.hpp"

class MarketOrder : public Order {
    public:
    MarketOrder();
    MarketOrder(std::string id, std::string s, int q, OrderType t);
    ~MarketOrder();

    void executeOrder(int matchedQty) override;
    std::string getOrderDetails() const override;
};
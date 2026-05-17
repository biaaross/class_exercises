#include "LimitOrder.hpp"

LimitOrder::LimitOrder() : Order() {}

LimitOrder::LimitOrder(std::string id, std::string s, double p, int q, OrderType t)
    : Order(id, s, p, q, t) {}

LimitOrder::~LimitOrder() {
    std::cout << "[LIMIT ORDER MEMORY CLEANUP] " << getId() << " dynamic allocations cleared safely." << std::endl;
}

void LimitOrder::executeOrder(int matchedQty) {
    int currentQty = getQuantity();
    
    setQuantity(currentQty - matchedQty);
    
    std::cout << "[LIMIT] Order partially matched by " << matchedQty << " units." << std::endl;
}

std::string LimitOrder::getOrderDetails() const {
    std::string side = (getType() == OrderType::BUY) ? "BUY" : "SELL";
    
    return "[LIMIT] " + getId() + " | " + getSymbol() + " | " + side + 
           " | Price: " + std::to_string(getPrice()) + 
           " | Remaining Qty: " + std::to_string(getQuantity());
}
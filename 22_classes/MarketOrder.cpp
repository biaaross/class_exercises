#include "MarketOrder.hpp"

MarketOrder::MarketOrder() : Order() {}

MarketOrder::MarketOrder(std::string id, std::string s, int q, OrderType t)
    : Order(id, s, 0.0, q, t) {}

MarketOrder::~MarketOrder() {
    std::cout << "[MARKET ORDER MEMORY CLEANUP] " << getId() << " cleared safely." << std::endl;
}

void MarketOrder::executeOrder(int matchedQty) {
    int currentQty = getQuantity();
    setQuantity(currentQty - matchedQty);
    
    std::cout << "[MARKET] Market Order instantly filled by " << matchedQty << " units." << std::endl;
}

std::string MarketOrder::getOrderDetails() const {
    std::string side = (getType() == OrderType::BUY) ? "BUY" : "SELL";
    
    return "[MARKET] " + getId() + " | " + getSymbol() + " | " + side + 
           " | Price: MARKET_PRICE | Remaining Qty: " + std::to_string(getQuantity());
}
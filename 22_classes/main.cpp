#include "Order.hpp"
#include "LimitOrder.hpp"
#include "MarketOrder.hpp"
#include "MachineEngine.hpp"

int main() {
    MachineEngine<Order> engine(2);

    std::cout << "--- Submitting Initial Limit Orders ---" << std::endl;
  
    engine.submitOrder(new LimitOrder("ORD-001", "BTC-USDT", 65000.0, 2, OrderType::BUY));
  
    engine.submitOrder(new LimitOrder("ORD-002", "BTC-USDT", 64800.0, 5, OrderType::SELL));

    engine.submitOrder(new LimitOrder("ORD-003", "BTC-USDT", 65000.0, 2, OrderType::SELL));

    engine.printOrderBook();

    engine.matchOrders();

    engine.printOrderBook();

    std::cout << "--- Submitting a Market Order ---" << std::endl;
    engine.submitOrder(new MarketOrder("ORD-004", "BTC-USDT", 3, OrderType::BUY));
    
    engine.printOrderBook();
    engine.matchOrders(); 
    engine.printOrderBook();

    
    engine.exportAuditTrail("audit_report.txt");

    std::cout << "\n--- Exiting Program (Destructor execution check) ---" << std::endl;
    return 0; 
}
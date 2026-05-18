
#include "orderTracker.h"
#include <iostream>

int main() {
    orderTracker tracker("business_logs.txt", "Downtown Tech Hub");

    std::cout << "--- Order System is running ---" << std::endl;

    tracker.addOrder("MacBook Pro M3", 1999.99, 1, "Alice Freeman");
    tracker.addOrder("Sony WH-1000XM5", 349.50, 2, "Bob Miller");
    tracker.addOrder("Logitech MX Master 3S", 99.00, 5, "Charlie Root");

    std::cout << "Successfully logged 3 orders to 'business_logs.txt'." << std::endl;
   
    return 0;
}
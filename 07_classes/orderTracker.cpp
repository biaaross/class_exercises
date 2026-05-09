#include "orderTracker.h"
#include <iostream>

orderTracker::orderTracker(const std::string& filePath, const std::string& store) {
    storeName = store;
    logFile.open(filePath, std::ios::app);

    if (!logFile) {
        std::cerr << "[ERROR]: Could not open file: " << filePath << std::endl;
        return;
    }

    logFile << "\n--- Session Started | Store: " << storeName << " ---" << std::endl;
}

orderTracker::~orderTracker() {
    if (logFile.is_open()) {
        logFile << "--- Session Closed ---" << std::endl;
        logFile.close();
    }
}

void orderTracker::addOrder(const std::string& productName, double price, int quantity, const std::string& customerName) {
    if (logFile.is_open()) {
        double total = price * quantity;

        logFile << "Customer: " << customerName 
                << " | Product: " << productName 
                << " | Qty: " << quantity 
                << " | Unit Price: " << price << " USD"
                << " | Total: " << total << " USD" << std::endl;
    } else {
        std::cerr << "[ERROR]: Order failed! Log file is not open." << std::endl;
    }
}
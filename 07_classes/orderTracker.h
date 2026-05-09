#pragma once
#include <string>
#include <fstream>

class orderTracker {
private:
    std::ofstream logFile;
    std::string storeName;

public:
    orderTracker(const std::string& filePath, const std::string& store);
    
    ~orderTracker();
    
    void addOrder(const std::string& productName, double price, int quantity, const std::string& customerName);
};
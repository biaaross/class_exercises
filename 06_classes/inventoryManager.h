#pragma once
#include "product.h"

class InventoryManager {
private:
    product* products;
    int capacity;
    int count;

public:
    InventoryManager(int c);
    ~InventoryManager();

    void addProduct(const product& p);
    void showInventory() const;
    void saveToFile(const std::string& filename) const;
};
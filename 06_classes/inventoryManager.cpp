#include "inventoryManager.h"
#include <iostream>
#include <fstream>

InventoryManager::InventoryManager(int c) : capacity(c), count(0) {
    products = new product[capacity];
}

InventoryManager::~InventoryManager() {
    delete[] products;
    std::cout << "Memory cleared by Destructor." << std::endl;
}

void InventoryManager::addProduct(const product& p) {
    if (count == capacity) {
        int newCapacity = capacity * 2;
        product* newArray = new product[newCapacity];
        
        for (int i = 0; i < count; i++) {
            newArray[i] = products[i]; 
        }
        delete[] products;

        products = newArray;
        capacity = newCapacity;

        std::cout << "The array has been expanded" << std::endl;
    }
    products[count] = p;
    count++;
}

void InventoryManager::showInventory() const {
    for (int i = 0; i < count; i++) {
        std::cout << "Product: " << products[i].getName() << " | Qty: " << products[i].getQuantity() << std::endl;
    }
}

void InventoryManager::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < count; i++) {
            file << products[i].toFileString() << std::endl;
        }
        file.close();
    }
}
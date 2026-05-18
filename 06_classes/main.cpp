#include <iostream>
#include <string>
#include "inventoryManager.h"
#include "product.h"


int main() {
    std::cout << "--- Inventory Management System Performance Test ---" << std::endl;

    InventoryManager store(2);

    std::cout << "[LOG] Initializing inventory with capacity 2..." << std::endl;

    product p1("Smartphone", 10, 850.50);
    product p2("Wireless Headphones", 25, 120.99);
    product p3("Gaming Monitor", 5, 450.00); 

    std::cout << "[LOG] Adding p1 and p2..." << std::endl;
    store.addProduct(p1);
    store.addProduct(p2);

    std::cout << "[LOG] Adding p3 (This should trigger array expansion)..." << std::endl;
    store.addProduct(p3); 

    std::cout << "\n--- Current Inventory Status ---" << std::endl;
    store.showInventory();

    std::cout << "\n[LOG] Saving data to 'inventory_backup.csv'..." << std::endl;
    store.saveToFile("inventory_backup.csv");

    std::cout << "\n[LOG] Testing complete. System shutting down..." << std::endl;
    

    return 0;
}
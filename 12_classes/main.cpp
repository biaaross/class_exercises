#include <iostream>
#include "warehouse.h"

int main() {
    int cap;
    std::cout << "Enter Warehouse Capacity: ";
    std::cin >> cap;

    Warehouse myDepo(cap);

    int choice = 0;
    while (choice != 5) {
        std::cout << "\n1. Add Product\n2. Show Inventory\n3. Save\n4. Load\n5. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 1) {
            std::string n; double p;
            std::cout << "Name: "; std::cin >> n;
            std::cout << "Price: "; std::cin >> p;
            
            Product* temp = new Product(n, p);
            if (!myDepo.addProduct(temp)) {
                delete temp; // Avoid leak if warehouse is full
            }
        } 
        else if (choice == 2) myDepo.showInventory();
        else if (choice == 3) myDepo.saveToFile("data.txt");
        else if (choice == 4) myDepo.loadFromFile("data.txt");
    }

    return 0;
}
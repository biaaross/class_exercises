#include "warehouse.h"
#include <iostream>
#include <string>
#include <fstream>

Warehouse::Warehouse(int cap) 
     :capacity(cap) , count(0) {
        shelves = new Product*[capacity];
    
        
        for(int i=0;i<capacity;i++) {
            shelves[i] = nullptr;
        }
    }

    Warehouse::~Warehouse() {
        for(int i=0;i<capacity;i++) {
            delete shelves[i];
        }
        delete[] shelves;

    std::cout << "[SYSTEM]: Warehouse fully cleared from memory." << std::endl;
    };

bool Warehouse::addProduct(Product* p) {
    if(count<capacity) {
        shelves[count] = p;
        count ++;
        return true;
    }
    std::cout << "[ERROR]: Warehouse full!" << std::endl;
    return false;
}

void Warehouse::showInventory() const {
    std::cout << "\n--- Current Inventory ---" << std::endl;
    for (int i = 0; i < count; i++) {
        std::cout << i + 1 << ". " << shelves[i]->getName() << " | $" << shelves[i]->getPrice() << std::endl;
    }
}

void Warehouse::saveToFile(std::string filename) {
    std::ofstream file(filename,std::ios::app);
    if(!file.is_open()) {
        std::cerr<<"File not Opened"<<std::endl;
        return;
    }

    for (int i = 0; i < count; i++) {
            file << shelves[i]->getName() << " " << shelves[i]->getPrice() << "\n";
        }
        file.close();
        std::cout << "[SUCCESS]: Saved to " << filename << std::endl;
}

void Warehouse::loadFromFile(std::string filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        int loadedCount;
        file >> loadedCount;
        for (int i = 0; i < loadedCount; i++) {
            std::string n; double p;
            file >> n >> p;
            addProduct(new Product(n, p)); // Yeni nesne oluştur ve listeye ekle
        }
        file.close();
        std::cout << "[SUCCESS]: Loaded from " << filename << std::endl;
    }
}
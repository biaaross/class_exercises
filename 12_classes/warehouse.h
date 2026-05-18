#pragma once
#include <string>
#include "product.h"

class Warehouse {
    protected:
    Product** shelves;
    int capacity;
    int count;

    public:
    Warehouse(int cap);
    ~Warehouse();

    bool addProduct(Product* p);
    void showInventory() const;
    void saveToFile(std::string filename);
    void loadFromFile(std::string filename);
};

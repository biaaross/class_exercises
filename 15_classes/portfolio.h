#pragma once
#include <iostream>
#include <string>
#include <fstream>

template <typename T>
class Portfolio {
private:
    T** items;          
    int capacity;       
    int count;          

    void resize() {
        capacity *= 2;
        T** newItems = new T*[capacity];
        for (int i = 0; i < count; i++) {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
    }

public:
    Portfolio(int initialCap = 5) : capacity(initialCap), count(0) {
        items = new T*[capacity];
    }

    ~Portfolio() {
        for (int i = 0; i < count; i++) {
            delete items[i];
        }
        delete[] items;     
    }

    void addAsset(T* item) {
        if (count >= capacity) {
            resize();
        }
        items[count++] = item;
    }

    double totalNetWorth() const {
        double total = 0;
        for (int i = 0; i < count; i++) {
            total += items[i]->calculateValue(); 
        }
        return total;
    }

    void saveToFile(const std::string& fileName) const {
        std::ofstream file(fileName);
        if (file.is_open()) {
            for (int i = 0; i < count; i++) {
                file << items[i]->serialize() << std::endl;
            }
            file.close();
            std::cout << "Data saved to " << fileName << std::endl;
        }
    }
};
#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "CargoSystem.hpp"

template <typename T>
class CargoManager {
    private:
    T** data;
    int capacity;
    int count;

    public:
    CargoManager(int c = 5) 
    : capacity(c) , count(0) {
        data = new T*[capacity];

        for(int i=0;i<capacity;i++) {
            data[i] = nullptr;
        }
    }

    
     ~CargoManager() {
        for (int i = 0; i < count; i++) {
            delete data[i]; 
        }
        delete[] data;      
    }


    void addItem(T* item) {
        if(count<capacity) {
            data[count] = item;
            count++;
        }
    }


    

       void saveToFile(const std::string& filename) {
        std::ofstream file(filename);
        if (file.is_open()) {
            for (int i = 0; i < count; i++) {
                file << data[i]->serialize() << "\n";
            }
            file.close();
            std::cout << "Data saved to " << filename << std::endl;
        }
    }
};
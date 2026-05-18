#pragma once
#include <iostream>
#include <string>
#include <fstream>

template <typename T>
class DataEngine {
private:
    T** dataArray;   
    int capacity;    
    int size;        

public:
    DataEngine(int initCapacity = 2) : capacity(initCapacity), size(0) {
        if (capacity <= 0) capacity = 2;
        
        dataArray = new T*[capacity];
        
        for (int i = 0; i < capacity; i++) {
            dataArray[i] = nullptr;
        }
    }

    ~DataEngine() {
        for (int i = 0; i < size; i++) {
            delete dataArray[i]; 
        }
        delete[] dataArray;     
    }

    void add(const T& item) {
        if (size >= capacity) {
            capacity *= 2; 
            T** tempArray = new T*[capacity];
            
            for (int i = 0; i < size; i++) {
                tempArray[i] = dataArray[i];
            }
            
            for (int i = size; i < capacity; i++) {
                tempArray[i] = nullptr;
            }
            
            delete[] dataArray;
            dataArray = tempArray;
        }

        dataArray[size] = new T(item);
        size++;
    }

    void listAll() const {
        if (size == 0) {
            std::cout << "[Warning] Engine is empty. No data to list." << std::endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            dataArray[i]->display(); 
        }
    }

     int getSize() const { return size; }
    int getCapacity() const { return capacity; }
    T* getAt(int index) const {
        if (index >= 0 && index < size) return dataArray[index];
        return nullptr;
    }
bool saveToFile(const std::string& filename) const {
        std::ofstream outFile(filename);
        
        if (!outFile.is_open()) {
            std::cerr << "[Hata] Dosya yazma icin acilamadi!" << std::endl;
            return false;
        }

        for (int i = 0; i < size; i++) {
            outFile << dataArray[i]->getId() << " " << dataArray[i]->getTamp() << "\n";
        }

        outFile.close();
        return true;
    }

    bool loadFromFile(const std::string& filename) {
        std::ifstream inFile(filename);
        
        if (!inFile.is_open()) {
            std::cerr << "[Hata] Dosya okuma icin acilamadi!" << std::endl;
            return false;
        }

        clear();

        std::string id;
        long long tamp;

        while (inFile >> id >> tamp) {
            T tempSensor(id, tamp);
            add(tempSensor); 
        }

        inFile.close();
        return true;
    }
};
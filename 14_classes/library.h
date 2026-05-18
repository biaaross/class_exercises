#pragma once
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
class Library {
private:
    T** data;        
    int capacity;
    int count;

public:
    Library(int cap = 20) : capacity(cap), count(0) {
        data = new T*[capacity];
    }

    ~Library() {
        for (int i = 0; i < count; i++) {
            delete data[i]; 
        }
        delete[] data;      
    }

    void addItem(T* item) {
        if (count < capacity) {
            data[count] = item;
            count++;
        }
    }

    void listAll() const {
        for (int i = 0; i < count; i++) {
            data[i]->display();
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
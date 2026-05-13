#pragma once
#include <iostream>
#include <string>
#include <fstream>

template <typename T>
class TransportNetwork {
    private:
    **T data;
    int capactiy;
    int count;

    public:
    TransportNetwork(int c = 20)
     : capactiy(c) , count(0) {
        data = new T*[capactiy];
     }

     ~TransportNetwork() {
        for (int i = 0; i < count; i++) {
            delete data[i]; 
        }
        delete[] data;      
    }

    void addItem(T* item) {
        if(count<capactiy) {
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
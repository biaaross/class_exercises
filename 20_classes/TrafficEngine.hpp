#pragma once
#include "NetworkPacket.hpp"
#include <string>
#include <iostream>
#include <fstream>

template <typename T>
class TrafficEngine {
    private:
    T** TrafficList;
    int capacity;
    int count;
    void resize();
    
    public:
    TrafficEngine(int cap = 15) 
        : capacity(cap) , count(0) {
            TrafficList = new T*[capacity];
        }

    ~TrafficEngine() {
        for (int i = 0; i < count; i++) {
        delete TrafficList[i]; 
    }
    delete[] TrafficList;
    };

    void addPacket(T* packet);
    void dropPacket(int index);
    void showTraffic() const;
    


    void saveReport(const std::string& filename) const;
    void loadReport(const std::string& filename);
};


template <typename T>
void TrafficEngine<T>::resize() {
    int newCapacity = capacity * 2;

    T** newTrafficList = new T*[newCapacity];

    for(int i=0;i<capacity;i++) {
        newTrafficList[i] = TrafficList[i];
    }

    for(int i=count;i<newCapacity;i++) {
        newTrafficList[i] = nullptr;
    }
    delete[] TrafficList;

    TrafficList = newTrafficList;
    capacity = newCapacity;
}



template <typename T>
void TrafficEngine<T>::addPacket(T* packet) {
   if (count >= capacity) {
        resize();
    }
    
    TrafficList[count] = packet;
    count++;
}

template <typename T>
void TrafficEngine<T>::dropPacket(int index) {
    if(index<0 || index>=count) {
        std::cerr<<"[INVALID INDEX]"<<std::endl;
        return;
    }

    delete TrafficList[index];

    for(int i=index;i<count-1;i++) {
        TrafficList[i] = TrafficList[i+1];
    }
    TrafficList[count - 1] = nullptr;
    count--;
}




    template <typename T>
void TrafficEngine<T>::showTraffic() const {
    if (count == 0) {
        std::cout << "[INFO] No active traffic data to display." << std::endl;
        return;
    }

    std::cout << "\n--- CURRENT NETWORK TRAFFIC (" << count << "/" << capacity << ") ---" << std::endl;
    
    for (int i = 0; i < count; i++) {
        TrafficList[i]->display(); 
    }
    std::cout << "-------------------------------------------\n" << std::endl;
}


template <typename T>
void TrafficEngine<T>::saveReport(const std::string& filename) const {
    std::ofstream file(filename, std::ios::app);
    if(!file.is_open()) {
        std::cerr << "[ERROR] Report file could not be opened!" << std::endl;
        return;
    }

    for(int i = 0; i < count; i++) {
        file << TrafficList[i]->getPacketId() << " "
             << TrafficList[i]->getSourceId() << " "
             << TrafficList[i]->getPayloadSize() << std::endl;
    }
}



#include <sstream>
template <typename T>
void TrafficEngine<T>::loadReport(const std::string& filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "[ERROR] Report file could not be opened!" << std::endl;
        return;
    }

    std::string line;
    std::cout << "\n--- LOADING PACKETS VIA GETLINE ---" << std::endl;

    while (std::getline(file, line)) {
        if (line.empty()) continue;

        std::stringstream ss(line);
        
        std::string id, source;
        int size;

        if (ss >> id >> source >> size) {
T* newPacket = new T(id, source, size);
            addPacket(newPacket);
            
            std::cout << "[SUCCESS] Loaded: " << id << " from line." << std::endl;
        } else {
            std::cerr << "[WARNING] Corrupted line format skipped: " << line << std::endl;
        }
    }
}
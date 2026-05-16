#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "LogEntry.hpp"


template <typename T>
class CyberPulseEngine {
    private:
    T** LogPool;
    int capacity;
    int count;
 
 
    void resizePool() {
        int newCapacity = capacity * 2;
        T** newLogPool = new T*[newCapacity];

        for(int i=0;i<count;i++) {
            newLogPool[i] = LogPool[i];
        }

        for(int i=capacity;i<newCapacity;i++) {
            newLogPool[i] = nullptr;
        }
        delete[] LogPool;
        LogPool = newLogPool;
        capacity = newCapacity;

    }

    public:
    CyberPulseEngine(int cap  = 5)
        : capacity(cap) , count(0) {
            LogPool = new T*[capacity];
        }

    ~CyberPulseEngine() {
        for(int i=0;i<count;i++) {
            delete LogPool[i];
        }
        delete[] LogPool;
    }

    CyberPulseEngine(const CyberPulseEngine&) = delete;
    CyberPulseEngine& operator=(const CyberPulseEngine&) = delete;

    void captureLog(T* newLog) {
        if (count >= capacity) {
            resizePool(); 
        }
        LogPool[count] = newLog; 
        count++;
    }



    void displayActiveLogs() const {
        if (count == 0) {
            std::cout << "[INFO] No active cyber threat logs in the pool." << std::endl;
            return;
        }
        std::cout << "\n================= CYBER PULSE ACTIVE THREATS =================" << std::endl;
        for (int i = 0; i < count; i++) {
            std::cout << "Log ID [" << i << "] -> ";
            LogPool[i]->analyzeThreat();
        }
        std::cout << "==============================================================" << std::endl;
    }

    void resolveLog(int index) {
        if (index < 0 || index >= count) {
            std::cout << "[ERROR] Invalid log index! Operation aborted." << std::endl;
            return;
        }

        std::cout << "\n[RESOLVING LOG] Removing threat at index " << index << "..." << std::endl;
        delete LogPool[index]; 

        
        for (int i = index; i < count - 1; i++) {
            LogPool[i] = LogPool[i + 1];
        }

        count--;
        std::cout << "[SUCCESS] Threat resolved. Log pool updated successfully." << std::endl;
    }

    void dumpLogHistory(const std::string& filename) {
        std::ofstream file(filename,std::ios::app);
        if(!file.is_open()) {
           std::cout << "[ERROR] Could not create or open log report file!" << std::endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            file << LogPool[i]->getTimesTamp() << " "
                    << LogPool[i]->getSourceIp() << " "
                    << LogPool[i]->getThreatLevel() << " "
                    << LogPool[i]->getAttackType() << "\n"; 
        }

        file.close();
        std::cout << "[SUCCESS] Forensic report generated: " << filename << std::endl;
    }


    void parseLogHistory(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cout << "[ERROR] Could not open forensic report file for reading!" << std::endl;
            return;
        }

        std::string tamp, ip, type;
        int level;
        int loadedCount = 0;

        while (file >> tamp >> ip >> level >> type) {
            
            T* historicalLog = new T(tamp, ip, level, type);
           
            captureLog(historicalLog);
            loadedCount++;
        }

        file.close();
        std::cout << "[SUCCESS] Forensic data parsing completed. " << loadedCount << " logs loaded back to RAM." << std::endl;

}
};
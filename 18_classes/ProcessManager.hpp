
#include <iostream>
#include <string>
#include <fstream>
template <typename T>
class ProcessManager {
private:
    T** processList; 
    int capacity;    
    int count;       
    void resize() {
        int newCap = capacity * 2;
        T** newList = new T*[newCap];
        for (int i = 0; i < count; i++) newList[i] = processList[i];
        delete[] processList;
        processList = newList;
        capacity = newCap;
    }   

public:
    ProcessManager(int initialCap = 2) 
        : capacity(initialCap) , count(0) {
            processList = new T*[capacity];
        }


    ~ProcessManager() {
        for(int i=0;i<count;i++) {
            delete processList[i];
        }
        delete[] processList;
    }

    void addItem(T* item) {
        if (count >= capacity) resize();
        processList[count++] = item;
    }
    
    void deleteItem(int index) {
        if (index < 0 || index >= count) return;
        delete processList[index];
        for (int i = index; i < count - 1; i++) {
            processList[i] = processList[i + 1];
        }
        processList[count - 1] = nullptr;
        count--;
    }

    void executeAll() {
        for (int i = 0; i < count; i++) processList[i]->execute();
    }  
    
    void saveLog(const std::string& filename) {
        std::ofstream file(filename); 

        if (file.is_open()) {
            file << "=== CYBERCORE OS SYSTEM LOG ===\n";
            file << "Total active processes: " << count << "\n";
            file << "-------------------------------\n";

            for (int i = 0; i < count; i++) {
                file << processList[i]->getStatus() << "\n";
            }

            file << "-------------------------------\n";
            file << "End of System Dump.\n";
            
            file.close(); 
            std::cout << "[SUCCESS] Log file created: " << filename << std::endl;
        } else {
            std::cerr << "[ERROR] Could not create log file!" << std::endl;
        }
    }
};

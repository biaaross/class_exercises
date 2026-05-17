#pragma once
#include "Order.hpp"
#include <iostream>
#include <string>
#include <fstream>

template <typename T>
class MachineEngine {
    private:
    T** orderList;
    int capacity;
    int count;

    public:
    MachineEngine(int cap = 6) 
        : capacity(cap) , count(0) {
            orderList = new T*[capacity];
        }
    
        ~MachineEngine() {
    for(int i = 0; i < count; i++) {
        if (orderList[i] != nullptr) { 
            delete orderList[i]; 
        }
    }
   delete[] orderList; 
    
    std::cout << "[ENGINE DESTROYED] All memory resources freed safely." << std::endl;
}

    void resize() {
        int newCapacity = capacity * 2;
        T** newOrderList = new T*[newCapacity];

        for(int i=0;i<capacity;i++) {
            newOrderList[i] = orderList[i];
        }

        for(int i=capacity;i<newCapacity;i++) {
            for (int i = 0; i < capacity; i++) {
                orderList[i] = nullptr;
            }
            
        }

     for(int i=0; i<capacity; i++) {
       if (orderList[i] != nullptr) { 
           delete orderList[i];
       }
   }

        delete[] orderList;

        orderList = newOrderList;
        capacity = newCapacity;
    }


    void submitOrder(T* order) {
        if(count < capacity) {
            resize();
        }

        orderList[count] = order;
        count++;
        return;
    
    }

    void matchOrders() {
        std::cout << "\n--- [MATCHING ENGINE PROCESSING] ---" << std::endl;

        for (int i = 0; i < count; i++) {
            for (int j = i + 1; j < count; j++) {
                
                if (orderList[i]->getQuantity() > 0 && orderList[j]->getQuantity() > 0) {
                    
                    if (orderList[i]->getSymbol() == orderList[j]->getSymbol() &&
                        orderList[i]->getType() != orderList[j]->getType()) {
                        
                        bool canMatch = false;
                        
                        if (orderList[i]->getPrice() == 0.0 || orderList[j]->getPrice() == 0.0) {
                            canMatch = true;
                        } 
                        else {
                            double buyPrice = (orderList[i]->getType() == OrderType::BUY) ? orderList[i]->getPrice() : orderList[j]->getPrice();
                            double sellPrice = (orderList[i]->getType() == OrderType::SELL) ? orderList[i]->getPrice() : orderList[j]->getPrice();
                            
                            if (buyPrice >= sellPrice) {
                                canMatch = true;
                            }
                        }

                        if (canMatch) {
                            int matchQty = std::min(orderList[i]->getQuantity(), orderList[j]->getQuantity());
                            
                            orderList[i]->executeOrder(matchQty);
                            orderList[j]->executeOrder(matchQty);
                        }
                    }
                }
            }
        }
        
        cleanFilledOrders();
        std::cout << "--- [MATCHING PROCESS COMPLETED] ---\n" << std::endl;
    }

    void printOrderBook() const {
        std::cout << "======= CURRENT ORDER BOOK =======" << std::endl;
        for (int i = 0; i < count; i++) {
            if (orderList[i] != nullptr) {
                std::cout << orderList[i]->getOrderDetails() << std::endl;
            }
        }
        std::cout << "==================================" << std::endl;
    }

    void exportAuditTrail(const std::string& filename) const {
        std::ofstream file(filename);
        if (file.is_open()) {
            file << "======= AUDIT TRAIL REPORT =======\n";
            for (int i = 0; i < count; i++) {
                if (orderList[i] != nullptr) {
                    file << orderList[i]->getOrderDetails() << "\n";
                }
            }
            file << "==================================\n";
            file.close();
            std::cout << "[REPORT] Audit trail successfully saved to " << filename << std::endl;
        } else {
            std::cerr << "[ERROR] Could not open file for writing!" << std::endl;
        }
    }
};
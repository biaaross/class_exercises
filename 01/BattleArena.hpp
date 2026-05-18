#pragma once
#include "GameCharacter.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

template <typename T>
class BattleArena {
    private:
    T** fighters;
    int capacity;
    int count;

    public:
    BattleArena(int cap = 20)
        : capacity(cap) , count(0) {
            fighters = new T*[capacity];
        }

    
    ~BattleArena() {
        for(int i=0;i<count;i++) {
            delete fighters[i];
        }
        delete[] fighters;
    }


    void resize() {
        int newCapacity = capacity * 2;
        T** newFighters = new T*[newCapacity];

        for(int i=0;i<capacity;i++) {
        newFighters[i] = fighters[i];
        }

        for(int i=capacity;i<newCapacity;i++) {
            newFighters[i] = nullptr;
        }

        delete[] fighters;
        fighters = newFighters;
        capacity = newCapacity;
    }



    void addCharacter(T* c) {
        if(count>=capacity) {
            resize();
        }
        fighters[count] = c;
        count++;
    }


    void startBrawl() {
        std::cout << "\n==========================================" << std::endl;
        std::cout << "          THE BRAWL BEGINS NOW!          " << std::endl;
        std::cout << "==========================================\n" << std::endl;

        if (count < 2) {
            std::cout << "Not enough fighters in the arena to start a brawl!" << std::endl;
            return;
        }

        int aliveCount = count;

        while (aliveCount > 1) {
            for (int i = 0; i < count; i++) {
        
                if (fighters[i]->getHealth() <= 0) continue;

                int targetIndex;
                do {
                    targetIndex = rand() % count;
                } while (targetIndex == i || fighters[targetIndex]->getHealth() <= 0);

                T* attacker = fighters[i];
                T* target = fighters[targetIndex];

                attacker->attack(target);

                if (target->getHealth() <= 0) {
                    std::cout << "\n💀 [DIED] " << target->getName() << " has been eliminated!\n" << std::endl;
                    aliveCount--;

                    if (aliveCount == 1) break;
                }
            }
        }

        for (int i = 0; i < count; i++) {
            if (fighters[i]->getHealth() > 0) {
                std::cout << "==========================================" << std::endl;
                std::cout << "🏆 WINNER: " << fighters[i]->getName() << " WINS THE BRAWL!" << std::endl;
                std::cout << "==========================================" << std::endl;
                break;
            }
        }
    }


void saveFighters(const std::string& filename) {
        std::ofstream outFile(filename);

        if (!outFile.is_open()) {
            std::cerr << "Error: Could not open file for writing!" << std::endl;
            return;
        }

        outFile << count << "\n";

        for (int i = 0; i < count; i++) {
            if (fighters[i]->getHealth() > 0) {
                outFile << fighters[i]->getName() << ","
                        << fighters[i]->getHealth() << ","
                        << fighters[i]->getDamage() << "\n";
            }
        }

        outFile.close();
        std::cout << "Successfully saved living fighters to " << filename << std::endl;
    }

    void loadFighters(const std::string& filename) {
        std::ifstream inFile(filename);

        if (!inFile.is_open()) {
            std::cerr << "Error: Could not open file for reading!" << std::endl;
            return;
        }

        std::string line;
        if (std::getline(inFile, line)) {
            std::cout << "Loading " << line << " characters from file..." << std::endl;
        }

        while (std::getline(inFile, line)) {
            if (line.empty()) continue;

            std::stringstream ss(line);
            std::string name, healthStr, damageStr;

            std::getline(ss, name, ',');
            std::getline(ss, healthStr, ',');
            std::getline(ss, damageStr, ',');

            int health = std::stoi(healthStr);
            int damage = std::stoi(damageStr);

            T* newCharacter = new Warrior(name, health, damage, 5); 
            addCharacter(newCharacter);
        }

        inFile.close();
        std::cout << "Fighters successfully loaded from " << filename << std::endl;
    }

};
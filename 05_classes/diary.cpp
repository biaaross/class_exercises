#include "diary.h"
#include <iostream>
#include <fstream>

diary::diary(std::string n) : fileName(n) {}

void diary::addEntry() {
    std::string text;
    std::cout << "Enter the text you want to add: ";
    std::getline(std::cin >> std::ws, text);

    std::ofstream addFile(fileName, std::ios::app);
    if (!addFile.is_open()) {
        std::cerr << "[ERROR] File could not be opened!" << std::endl;
        return;
    }
    
    addFile << text << std::endl;
    addFile.close(); 
    std::cout << "[SUCCESS] Entry added." << std::endl;
}

void diary::displayAll() {
    std::ifstream readFile(fileName);
    std::string line;
    
    if (!readFile.is_open()) {
        std::cout << "Diary is empty or file not found." << std::endl;
        return;
    }

    std::cout << "\n--- DIARY ENTRIES ---" << std::endl;
    while (std::getline(readFile, line)) {
        std::cout << "- " << line << std::endl;
    }
    readFile.close();
}

void diary::clearLogs() {
    std::ofstream clearFile(fileName, std::ios::trunc);
    if (clearFile.is_open()) {
        clearFile.close();
        std::cout << "[INFO] All logs cleared successfully." << std::endl;
    }
}
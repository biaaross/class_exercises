#include "achievementManager.h"
#include <iostream>
#include <string>
#include <fstream>

achievementManager::achievementManager(const std::string& pName, const std::string& fileName) {
    playerName = pName;

    logFile.open(fileName, std::ios::app);
    if(!logFile) {
        std::cerr << "[SYSTEM ERROR]: Could not initialize log file: " << fileName << std::endl;
        return;
    }
    else {
        logFile << "\n[NEW SESSION] Player '" << playerName << "' has joined the system." << std::endl;
    }
}

achievementManager::~achievementManager() {
    if(logFile.is_open()) {
        logFile << "[SESSION CLOSED] Activity log ended for " << playerName << "." << std::endl;
        logFile.close(); 
    }
}

void achievementManager::unclock(const std::string& achievementName, int playerScore) {
    if(playerScore >= 1000) {
        if(logFile.is_open()) {
            logFile << "[SUCCESS] Achievement Unlocked: " << achievementName 
                    << " | Final Score: " << playerScore << std::endl;
            
            std::cout << ">> Congratulations! '" << achievementName << "' unlocked." << std::endl;
        }
    } 
    else {
        if(logFile.is_open()) {
            logFile << "[LOCKED] Achievement: " << achievementName 
                    << " | Required: 1000 | Current: " << playerScore << std::endl;
        }
        
        std::cerr << "[!] Achievement Locked: " << achievementName 
                  << ". You need at least 1000 points (Current: " << playerScore << ")." << std::endl;
        return;
    }
}
#include "smartHome.h"
#include <iostream>
#include <string>
#include <fstream>

smartDevice::smartDevice(const std::string& name,const std::string& fileName) {
    deviceName = name;
    
    logFile.open(fileName,std::ios::app);
    if(!logFile) {
        std::cerr<<"File Not Opened"<<std::endl;
        return;
    }
     logFile << deviceName <<":"<<"Starred"<<std::endl;
}


smartDevice::~smartDevice() {
    if(logFile.is_open()) {
logFile << "[INFO]: Device " << deviceName << " is now offline." << std::endl;
        logFile.close();
    }
}


void smartDevice::addLog(const std::string& action,int value) {

    if(!value<0 && !value>100) {

        if(logFile.is_open()) {

        logFile << "Action: " << action 
                    << " | Value: " << value << "%" << std::endl;
        }
        
    }
    else {
    std::cerr << "[ERROR]: Invalid input! Value " << value 
                  << " is out of range (0-100) for " << deviceName << "." << std::endl;
    }
}
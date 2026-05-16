#include "LogEntry.hpp"
#include <iostream>
#include <string>

LogEntry::LogEntry() {}
LogEntry::LogEntry(std::string tamp,std::string ip,int level)
    : timestamp(tamp) , sourceIp(ip) , threatLevel(level) {}

LogEntry::~LogEntry() {
    std::cout<<"Times Tamp:"<<timestamp
             <<" | Source Ip:"<<sourceIp
             <<" | Threat Level:"<<threatLevel
             <<" | [DESTROYED]"<<std::endl;
}


std::string LogEntry::getTimesTamp() const {
    return timestamp;
}

std::string LogEntry::getSourceIp() const {
    return sourceIp;
}

int LogEntry::getThreatLevel() const {
    return threatLevel;
}

void LogEntry::setTimesTamp(const std::string& newTamp) {
    if(!newTamp.empty()) {
    timestamp = newTamp;
        return;
    }
    std::cout<<"[INVALID - Newtamp Is Empty]"<<std::endl;

}



    void LogEntry::setSourceIp(const std::string& newIp) {
           if(!newIp.empty()) {
         sourceIp = newIp;
        return;
    }
    std::cout<<"[INVALID - Newtamp Is Empty]"<<std::endl;

    }



    void LogEntry::setThreatLevel(int newLevel) {
        if(newLevel>=0) {
            threatLevel = newLevel;
            return;
        }
    std::cout<<"[INVALID VALUE]"<<std::endl;

    }
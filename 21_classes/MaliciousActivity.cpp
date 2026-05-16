#include "MaliciousActivityilog.hpp"
#include <iostream>
#include <string>

MaliciousActivity::MaliciousActivity() {}
MaliciousActivity::MaliciousActivity(std::string tamp,std::string ip,int level,std::string type) 
    : LogEntry(tamp,ip,level) , attackType(type) {}
    
MaliciousActivity::~MaliciousActivity() {}

void MaliciousActivity::analyzeThreat() const {
    std::cout<<"Times Tamp:"<<getTimesTamp()
             <<" | Source Ip:"<<getSourceIp()
             <<" | Threat Level:"<<getThreatLevel()
             <<" | Attack Type:"<<attackType
             <<std::endl;
            }
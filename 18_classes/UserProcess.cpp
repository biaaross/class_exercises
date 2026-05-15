#include "UserProcess.hpp"
#include <iostream>
#include <string>

UserProcess::UserProcess(int id,std::string n,int p,double m)
    : BaseProcess(id,n,p) , memoryUsage(m) {}
    
UserProcess::~UserProcess() {}

void UserProcess::execute() {
    std::cout<<"User application ["<<name<<"] is running.."<<std::endl;
}

std::string  UserProcess::getStatus() const {
    return "[SYSTEM-TASK] " + name + " (Memory: " + std::to_string(memoryUsage) + ")";
}

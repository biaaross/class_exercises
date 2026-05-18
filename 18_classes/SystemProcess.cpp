#include "SystemProcess.hpp"
#include <iostream>
#include <string>

SystemProcess::SystemProcess(int id,std::string n,int p)
    : BaseProcess(id,n,p) {}


SystemProcess::~SystemProcess() {}

void SystemProcess::execute() {
    std::cout<<"Kernel Executing System Task:["<<name<<"]"<<std::endl;
}

std::string SystemProcess::getStatus() const {
    return "[SYSTEM-TASK] " + name + " (Priority: " + std::to_string(priority) + ")";
}
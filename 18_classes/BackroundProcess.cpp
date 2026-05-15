#include "BackroundProcess.hpp"
#include <iostream>
#include <string>

BackroundProcess::BackroundProcess(int id,std::string n,int p)
    : BaseProcess(id,n,p)  {}
    
BackroundProcess::~BackroundProcess() {}

void BackroundProcess::execute() {
    std::cout<<"Service ["<<name<<"] is updating in background."<<std::endl;
}

std::string  BackroundProcess::getStatus() const {
return "[Background Service - ID] " + std::to_string(processId);
}

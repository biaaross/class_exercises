#include "BaseProcess.hpp"
#include <iostream>
#include <string>

BaseProcess::BaseProcess(int id,std::string n,int p)
    : processId(id) , name(n) , priority(p) {};

BaseProcess::~BaseProcess() {
    std::cout<<"ID:"<<processId
             <<"Name:"<<name
             <<"Prority:"<<priority
             <<"[DESTROYED]"<<std::endl;
}


#pragma once
#include <string>

class BaseProcess {
protected:
int processId;
std::string name;
int priority;

public:
BaseProcess(int id,std::string n,int p);
~BaseProcess();

virtual void execute() = 0;
virtual std::string getStatus() const = 0;

};
 
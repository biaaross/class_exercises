#pragma once
#include "BaseProcess.hpp"
#include <string>

class SystemProcess : public BaseProcess {
public:
SystemProcess(int id,std::string n,int p);
~SystemProcess();

 void execute() override;
 std::string getStatus() const override;

};
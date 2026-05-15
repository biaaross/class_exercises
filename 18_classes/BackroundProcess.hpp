#pragma once
#include "BaseProcess.hpp"
#include <string>

class BackroundProcess : public BaseProcess {
    public:
    BackroundProcess(int id,std::string n,int p);
    ~BackroundProcess();

    void execute() override;
    std::string getStatus() const override;
};
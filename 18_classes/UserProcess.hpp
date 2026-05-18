#pragma once
#include "BaseProcess.hpp"
#include <string>

class UserProcess : public BaseProcess {
    private:
    double memoryUsage;

    public:
    UserProcess(int id,std::string n,int p,double m);
    ~UserProcess();

    void execute() override;
    std::string getStatus() const override;
};
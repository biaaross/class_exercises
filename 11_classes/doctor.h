#pragma once
#include <string>

class Doctor {
    protected:
    std::string doctorName;
    std::string branch;

    public:
    Doctor(std::string n,std::string b);
    ~Doctor();

    std::string getName() const;
    std::string getBranch() const;
};
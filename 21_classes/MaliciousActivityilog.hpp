#pragma once
#include "LogEntry.hpp"
#include <string>

class MaliciousActivity : public LogEntry {
    private:
    std::string attackType;

    public:
    MaliciousActivity();
    MaliciousActivity(std::string tamp,std::string ip,int level,std::string type);
    ~MaliciousActivity();

    void analyzeThreat() const;
};
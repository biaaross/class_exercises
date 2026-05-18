#pragma once
#include <string>

class LogEntry {
    private:
    std::string timestamp;
    std::string sourceIp;
    int threatLevel;

    public:
    LogEntry();
    LogEntry(std::string tamp,std::string ip,int level);
    
    virtual ~LogEntry();
    std::string getTimesTamp() const;
    std::string getSourceIp() const;
    int getThreatLevel() const;

    void setTimesTamp(const std::string& newTamp);
    void setSourceIp(const std::string& newIp);
    void setThreatLevel(int newLevel);

    virtual void analyzeThreat() const = 0;

};
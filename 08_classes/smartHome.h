#pragma once
#include <string>
#include <fstream>

class smartDevice {
    private:
    std::ofstream logFile;
    std::string deviceName;

    public:
    smartDevice(const std::string& name,const std::string& fileName);
    ~smartDevice();
    void addLog(const std::string& action,int value);
};

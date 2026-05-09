#pragma once
#include <string>
#include <fstream>
class achievementManager {
    private:
    std::ofstream logFile;
    std::string playerName;

    public:
    achievementManager(const std::string& pName,const std::string& fileName);

    ~achievementManager();

    void unclock(const std::string&  achievementName,int playerScore);

};

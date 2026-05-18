#pragma once

#include <string>

class diary {
private:
    std::string fileName;

public:
    diary(std::string n); 

    void addEntry();
    void displayAll();
    void clearLogs();
};

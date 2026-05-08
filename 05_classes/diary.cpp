#include "diary.h"
#include <iostream>
#include <string>
#include <fstream>

class diary {
    private:
    std::string fileName;

    public:
    diary(std::string n)
    : fileName(n) {}; 

    void addEntry();
    void displayAll();
    void clearLogs();
};

void diary::addEntry() {
    std::string text;
    std::cout<<"Enter the text you want to add to the file."<<std::endl;
     std::getline(std::cin >> std::ws, text);

    std::ofstream addFile(fileName,std::ios::app);
    if(!addFile.is_open()) {
        std::cerr<<"[File not Opened]"<<std::endl;
        return;
    }
    
    addFile<<text<<std::endl;

} 




void diary::displayAll() {
    std::ifstream displayFile(fileName);
    if(!displayFile.is_open()) {
        std::cerr<<"File not Opened"<<std::endl;
        return;
    }

    std::string line;
    while(getline(displayFile,line)) {
        std::cout<<line<<std::endl;
    }
}



void diary::clearLogs() {
    std::ofstream clearFile(fileName,std::ios::trunc);
    if(!clearFile.is_open()) {
        std::cerr<<"File not Opened"<<std::endl;
        return;
 }
}
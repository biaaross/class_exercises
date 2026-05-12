#pragma once
#include <string>

class Media {
    protected:
    int id;
    std::string title;

    public:
    Media(int i,const std::string& t);
    virtual ~Media();
    
    virtual void display() = 0;
    std::string getTitle() const;
    virtual std::string serialize() const = 0;
    
};
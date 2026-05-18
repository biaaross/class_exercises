#pragma once
#include "media.h"
#include <string>

class Book : public Media {
    private:
    std::string author;

    public:
    Book(int i,std::string t,std::string a);
    ~Book();
    void display() override;
    std::string serialize() const override;
};
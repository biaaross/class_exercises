#include "media.h"
#include <iostream>
#include <string>


Media::Media(int i,const std::string& t)
 : id(i) , title(t) {}

Media::~Media() {
    std::cout<<"ID:"<<id
             <<"[DELETED]"<<std::endl;
}

std::string Media::getTitle() const {
    return title;
}



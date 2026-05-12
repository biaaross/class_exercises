#include "book.h"
#include <iostream>
#include <string>


Book::Book(int i,std::string t,std::string a)
 : Media(i,t) , author(a) {}

Book::~Book() {
   std::cout<<"ID:"<<id
             <<"TITTLE:"<<title
             <<"AUTHOR:"<<author
             <<"[DESTROYED]"<<std::endl;
}
void Book::display() {
    std::cout << "[BOOK] ID: " << id 
              << " | Title: " << title 
              << " | Author: " << author << std::endl;

}

std::string Book::serialize() const {
    return std::to_string(id) + "," + title + "," + author;
}
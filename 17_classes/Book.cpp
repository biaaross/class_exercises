#include "Book.hpp"
#include <iostream>
#include <string>

Book::Book(std::string pn,double w,std::string tn)
     : Cargo(pn,w,tn) {};

Book::~Book() {};

std::string Book::serialize() const {
    return "BOOK" + productName + "|" + trackingNumber + "|" + std::to_string(weight); 
}

void Book::rapor() const {
    std::cout << "BOOK CARGO -> Product: " << productName 
              << " | Weight: " << weight << std::endl;
}
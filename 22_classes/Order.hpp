#pragma once
#include <string>

// Sınav sorusundaki yön kuralı için enum tanımı
enum class OrderType { BUY, SELL };

class Order {
    private:
    std::string orderId;
    std::string symbol;
    double price;
    int quantity;
    OrderType type; 

    public:
    Order();
    Order(std::string id,std::string s,double p,int q, OrderType t); 
    virtual ~Order();

    std::string getId() const;
    std::string getSymbol() const;
    double getPrice() const;
    int getQuantity() const;
    OrderType getType() const; 

    void setId(const std::string& newId);
    void setSymbol(const std::string& newSymbol);
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);


    virtual void executeOrder(int matchedQty) = 0;
    virtual std::string getOrderDetails() const = 0;
};
#pragma once
#include <string>
class SensorData {
    private:
    std::string SensorId;
    long long timestamp;

    public:
    SensorData();
    SensorData(std::string id,long long t);
    
    ~SensorData();

    std::string getId() const;
    long long getTamp() const;

    void setId(const std::string& newId);
    void setTamp(long long newTamp);

    void display() const;
};
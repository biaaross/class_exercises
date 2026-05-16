#include "Sensor.hpp"
#include <iostream>
#include <string>

SensorData::SensorData() {};
SensorData::SensorData(std::string id,long long t) 
    : SensorId(id) , timestamp(t) {}


SensorData::~SensorData() {
    std::cout<<"Sensor Id:"<<SensorId
             <<"Times Tamp:"<<timestamp
             <<"[DESTROYED]"<<std::endl;
}

std::string SensorData::getId() const {
    return SensorId;
}


long long SensorData::getTamp() const {
    return timestamp;
}


  void SensorData::setId(const std::string& newId) {
    if(!newId.empty()) {
        SensorId = newId;
        return;
    }
    std::cerr<<"[Invalid]"<<std::endl;

  }
    void SensorData::setTamp(long long newTamp) {
        if(newTamp>=0) {
            timestamp = newTamp;
            return;
        }
    std::cerr<<"[Invalid]"<<std::endl;
    }

    void SensorData::display() const {
          std::cout<<"Sensor Id:"<<SensorId
             <<"| Times Tamp:"<<timestamp<<std::endl;
    }


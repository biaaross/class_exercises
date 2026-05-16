#include "NetworkPacket.hpp"
#include <iostream>
#include <string>

NetworkPacket::NetworkPacket() {}

NetworkPacket::NetworkPacket(std::string packetid,std::string sourceid,int size) 
    : packetId(packetid) , sourceId(sourceid) , payloadSize(size) {}
    
NetworkPacket::~NetworkPacket() {
    std::cout<<"Packet Id:"<<packetId
             <<"Source Id:"<<sourceId
             <<"[DESTROYED]"<<std::endl;  
}




    std::string NetworkPacket::getPacketId() const {
        return packetId;
    }

    std::string NetworkPacket::getSourceId() const {
        return sourceId;
    
    }


    
    int NetworkPacket::getPayloadSize() const {
        return payloadSize;
    
    }



    void NetworkPacket::setpacketId(const std::string& newPacketId)  {
        if(newPacketId.empty()) {
    std::cerr<<"[EMPTY STRING]"<<std::endl;
    return;
}
packetId = newPacketId;
    }


    void NetworkPacket::setsourceId(const std::string& newSourceId)  {
if(newSourceId.empty()) {
    std::cerr<<"[EMPTY STRING]"<<std::endl;
    return;
}
sourceId = newSourceId;
    }
    
    void  NetworkPacket::setPayloadSize(int newSize)  {
        if(newSize<0) {
            std::cerr<<"[INVALID VALUE]"<<std::endl;
            return;
        }

        payloadSize = newSize;
    }




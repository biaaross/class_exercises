#pragma once
#include <string>

class NetworkPacket {
    private:
    std::string packetId;
    std::string sourceId;
    int payloadSize;

    public:
    NetworkPacket();
    NetworkPacket(std::string packetid,std::string sourceid,int size);
    virtual ~NetworkPacket();

    std::string getPacketId() const;
    std::string getSourceId() const;
    int getPayloadSize() const;
    
    void setpacketId(const std::string& newPacketId);
    void setsourceId(const std::string& newSourceId);
    void setPayloadSize(int newSize);

    virtual void display() const = 0;
};

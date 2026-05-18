#include <iostream>
#include "NetworkPacket.hpp"
#include "TrafficEngine.hpp"

class ConcretePacket : public NetworkPacket {
public:
    ConcretePacket(std::string id, std::string src, int sz) 
        : NetworkPacket(id, src, sz) {}

    void display() const override {
        std::cout << "[Packet Info] ID: " << getPacketId() 
                  << " | Source: " << getSourceId() 
                  << " | Size: " << getPayloadSize() << " bytes" << std::endl;
    }
};

int main() {
    std::cout << "=== NETWORK TRAFFIC ENGINE TEST STARTED ===\n" << std::endl;

    TrafficEngine<ConcretePacket> engine(5);

    std::cout << ">>> Adding packets..." << std::endl;
    engine.addPacket(new ConcretePacket("PKT-101", "192.168.1.10", 64));
    engine.addPacket(new ConcretePacket("PKT-102", "10.0.0.1", 1500));
    engine.addPacket(new ConcretePacket("PKT-103", "172.16.0.5", 256));
    
    engine.showTraffic();

    std::cout << ">>> Dropping packet at index 1..." << std::endl;
    engine.dropPacket(1); 
    
    std::cout << "\n>>> Updated Traffic Status:" << std::endl;
    engine.showTraffic();

    std::string reportFile = "network_report.txt";
    std::cout << ">>> Saving traffic report to '" << reportFile << "'..." << std::endl;
    engine.saveReport(reportFile);

    std::cout << "\n>>> Creating empty Traffic Engine..." << std::endl;
    TrafficEngine<ConcretePacket> loadedEngine(10);

    std::cout << ">>> Loading data from report file..." << std::endl;
    loadedEngine.loadReport(reportFile);

    std::cout << "\n>>> Loaded Traffic Status:" << std::endl;
    loadedEngine.showTraffic();

    std::cout << "=== PROGRAM FINISHED (Cleaning up memory) ===" << std::endl;
    
    return 0;
}
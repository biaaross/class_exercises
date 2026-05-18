#include <iostream>
#include "vehicle.h"
#include "bus.h"
#include "metro.h"
#include "TransportNetwork.h" 

int main() {
    TransportNetwork<Vehicle> myCityFleet(2);

    std::cout << "--- Smart City Fleet Management System ---" << std::endl;

    try {
        std::cout << "\nAdding vehicles to the fleet..." << std::endl;
        
        myCityFleet.addItem(new Bus("BUS-101", 150.5, 12.5, 45));
        myCityFleet.addItem(new Metro("METRO-01", 300.0, 5.2, 8));
        
        myCityFleet.addItem(new Bus("BUS-202", 80.0, 14.0, 30)); 
        
        std::cout << "All vehicles added successfully.\n" << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "An error occurred: " << e.what() << std::endl;
    }

    std::cout << "Saving fleet data to file..." << std::endl;
    myCityFleet.saveToFile("smart_city_fleet.txt");

    std::cout << "\nClosing system and clearing memory..." << std::endl;

    return 0;
}
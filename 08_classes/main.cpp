#include "smartHome.h"
#include <iostream>

int main() {
    smartDevice livingRoomLight("Living Room Light", "home_automation.log");

    std::cout << "--- Smart Home System Initialized ---" << std::endl;

    livingRoomLight.addLog("Brightness Set", 75);
    livingRoomLight.addLog("Brightness Set", 20);

    livingRoomLight.addLog("Brightness Set", 150); 
    livingRoomLight.addLog("Brightness Set", -10);

    std::cout << "--- Process Completed. Check home_automation.log for details. ---" << std::endl;

    return 0;
}
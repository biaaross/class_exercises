#include <iostream>
#include <fstream>
#include <string>
#include "SolarPanel.h"
#include "WindTurbine.h"

void loadData(EnergySource* grid[], int& count, int max) {
    std::ifstream inputFile("sources.txt");
    if (!inputFile) {
        std::cerr << "Error: sources.txt not found!" << std::endl;
        return;
    }

    std::string type, name;
    double cap, extra;

    while (inputFile >> type >> name >> cap >> extra && count < max) {
        if (type == "Solar") {
            grid[count++] = new SolarPanel(name, cap, extra);
        } else if (type == "Wind") {
            grid[count++] = new WindTurbine(name, cap, extra);
        }
    }
    inputFile.close();
}

void saveReport(EnergySource* grid[], int count) {
    std::ofstream outputFile("report.txt");
    if (!outputFile) {
        std::cerr << "Error: Could not create report.txt!" << std::endl;
        return;
    }

    outputFile << "--- CITY ENERGY REPORT ---" << std::endl;
    for (int i = 0; i < count; i++) {
        outputFile << "Source: " << grid[i]->getSourceName() << std::endl;
    }
    outputFile.close();
}

int main() {
    const int MAX = 50;
    EnergySource* myGrid[MAX];
    int currentCount = 0;

    loadData(myGrid, currentCount, MAX);

    std::cout << "\nDisplaying Energy Sources:\n";
    for (int i = 0; i < currentCount; i++) {
        myGrid[i]->showDetails();
        myGrid[i]->calculateOutput();
        std::cout << "-----------------------" << std::endl;
    }

    saveReport(myGrid, currentCount);

    for (int i = 0; i < currentCount; i++) {
        delete myGrid[i];
    }

    std::cout << "\nProcess finished. Report saved to report.txt." << std::endl;
    return 0;
}
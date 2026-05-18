#include "diary.h"
#include <iostream>

int main() {
    diary myDiary("my_notes.txt");
    int choice;

    do {
        std::cout << "1. Add Entry\n2. Display All\n3. Clear All\n0. Exit\nSelection: ";
        std::cin >> choice;

        switch (choice) {
            case 1: myDiary.addEntry(); break;
            case 2: myDiary.displayAll(); break;
            case 3: myDiary.clearLogs(); break;
            case 0: std::cout << "Exiting..." << std::endl; break;
            default: std::cout << "Invalid choice!" << std::endl;
        }
    } while (choice != 0);

    return 0;
}
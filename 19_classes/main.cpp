#include <iostream>
#include "Sensor.hpp"
#include "DataEngine.hpp"

int main() {
    std::cout << "=== Test Basliyor ===" << std::endl;

    DataEngine<SensorData> engine;

    engine.add(SensorData("TEMP_01", 1500));
    engine.add(SensorData("HIZ_02", 2500));
    engine.add(SensorData("BASINC_03", 3500)); // Kapasite aşılınca otomatik resize çalışacak

    std::cout << "\n--- Ilk Eklenen Veriler ---" << std::endl;
    engine.listAll();

    std::cout << "\n--- Dosyaya Kaydediliyor... ---" << std::endl;
    engine.saveToFile("veriler.txt");

    std::cout << "\n--- Yeni Motor Olusturuluyor ve Yukleniyor... ---" << std::endl;
    DataEngine<SensorData> yeniEngine;
    yeniEngine.loadFromFile("veriler.txt");

    std::cout << "\n--- Dosyadan Gelen Veriler ---" << std::endl;
    yeniEngine.listAll();

    return 0;
}
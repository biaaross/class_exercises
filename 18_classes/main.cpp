#include <iostream>
#include <string>
#include "ProcessManager.hpp"
#include "SystemProcess.hpp"
#include "UserProcess.hpp"
#include "BackroundProcess.hpp"

int main() {
    ProcessManager<BaseProcess> scheduler(2);

    std::cout << "--- CyberCore OS Scheduler Baslatiliyor ---\n" << std::endl;

    std::cout << "[INFO] Surecler ekleniyor..." << std::endl;
    scheduler.addItem(new SystemProcess(101, "Kernel_Init", 10));
    scheduler.addItem(new UserProcess(202, "Google Chrome", 5, 1024.8));
    
    scheduler.addItem(new BackroundProcess(303, "Cloud_Sync", 2));
    scheduler.addItem(new UserProcess(404, "VS_Code", 7, 2048.2));

    std::cout << "\n--- Mevcut Tum Surecler Calistiriliyor ---" << std::endl;
    scheduler.executeAll();

    std::cout << "\n--- Silme Testi: Index 1 (Chrome) sistemden cikariliyor ---" << std::endl;
    scheduler.deleteItem(1);

    std::cout << "\n--- Guncel Liste Calistiriliyor (Sola kayma kontrolu) ---" << std::endl;
    scheduler.executeAll();

    std::cout << "\n[LOG] Sistem durumu log dosyasına kaydediliyor..." << std::endl;
    scheduler.saveLog("system_dump.log");

    std::cout << "\n--- Program Sonu: Bellek Temizligi Basliyor ---" << std::endl;
 
    return 0;
}
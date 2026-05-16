#include "CyberPulseEngine.hpp"
#include "MaliciousActivityilog.hpp"
#include <iostream>

int main() {
    CyberPulseEngine<MaliciousActivity> engine(2);

    std::cout << "--- 1. ADIM: Canli Siber Saldiri Loglari Yakalaniyor ---" << std::endl;

    engine.captureLog(new MaliciousActivity("23:15:01", "192.168.1.45", 9, "SQL_Injection"));
    engine.captureLog(new MaliciousActivity("23:16:42", "10.0.0.8", 7, "Brute_Force"));
    
    std::cout << "\n[DİKKAT] Birazdan eklenecek log kapasiteyi (2) asacagi icin havuz genisleyecek..." << std::endl;
    engine.captureLog(new MaliciousActivity("23:19:12", "172.16.254.1", 10, "DDoS_Attack")); 

    engine.displayActiveLogs();


    std::cout << "\n--- 2. ADIM: Adli Bilisim Raporu Diske Yaziliyor ---" << std::endl;
    engine.dumpLogHistory("forensic_report.log");


    std::cout << "\n--- 3. ADIM: Siber Tehdit Cozumu (Resolve) Testi ---" << std::endl;
    engine.resolveLog(0);

    engine.displayActiveLogs();


    std::cout << "\n==================================================================" << std::endl;
    std::cout << "--- 4. ADIM: YENI MOTOR ILE DOSYADAN RECOVERY (GERI YUKLEME) ---" << std::endl;
    std::cout << "==================================================================" << std::endl;

    CyberPulseEngine<MaliciousActivity> recoveryEngine(5);

    recoveryEngine.parseLogHistory("forensic_report.log");

    recoveryEngine.displayActiveLogs();

    return 0;
}
#include <iostream>
#include "CargoManager.hpp" 
#include "Book.hpp"
#include "Food.hpp"

int main() {
    CargoManager<Cargo> depo(10);

    std::cout << "--- Kargo Kayit Sistemi Baslatiliyor ---" << std::endl;

    depo.addItem(new Book("C++ Programlama", 1.2, "BK-101"));
    depo.addItem(new Food("Sut", 1.0, "FD-202", "2026-08-15"));
    depo.addItem(new Book("Sefiller", 0.9, "BK-102"));
    depo.addItem(new Food("Zeytinyagi", 5.0, "FD-203", "2027-01-20"));

    std::cout << "\n--- Mevcut Kargolarin Raporu ---" << std::endl;
    depo.saveToFile("kargo_verileri.txt");

    std::cout << "\n--- Islem Tamamlandi. Program Kapatiliyor ---" << std::endl;
    
    return 0; 
}
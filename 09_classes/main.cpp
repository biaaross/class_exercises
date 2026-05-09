#include "achievementManager.h"
#include <iostream>

int main() {
    achievementManager myGame("EjderAvcisi_61", "oyun_kayitlari.txt");

    std::cout << "--- Oyun Basari Sistemi Calisiyor ---" << std::endl;

    myGame.unclock("Ilk Kan", 1250);

    myGame.unclock("Efsanevi Kahraman", 450);

    myGame.unclock("Usta Avci", 1000);

    std::cout << "--- Test Tamamlandi. Log dosyasini kontrol edebilirsiniz. ---" << std::endl;

    return 0;
}
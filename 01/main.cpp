#include "BattleArena.hpp"
#include "Warrior.hpp"
#include "Mage.hpp"
#include <iostream>
#include <ctime>   
#include <cstdlib> 

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "=== STAGE 1: Creating Characters & Initial Arena ===" << std::endl;
    
    BattleArena<GameCharacter> dynamicArena(10);

    dynamicArena.addCharacter(new Warrior("Aragorn", 140, 18, 6)); // İsim, Can, Hasar, Zırh
    dynamicArena.addCharacter(new Mage("Gandalf", 90, 22, 40));    // İsim, Can, Hasar, Mana
    dynamicArena.addCharacter(new Warrior("Gimli", 160, 15, 8));
    dynamicArena.addCharacter(new Mage("Saruman", 95, 20, 30));

    std::cout << "\n=== STAGE 2: Saving Arena State to File ===" << std::endl;
    dynamicArena.saveFighters("arena_backup.txt");

    std::cout << "\n=== STAGE 3: Loading Characters into a New Arena ===" << std::endl;
    BattleArena<GameCharacter> loadedArena(5);
    
    loadedArena.loadFighters("arena_backup.txt");

    std::cout << "\n=== STAGE 4: Let the Carnage Begin! ===" << std::endl;
    loadedArena.startBrawl();

    return 0;
}
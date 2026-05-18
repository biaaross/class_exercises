#include "Mage.hpp"
#include <iostream>
#include <string>

//*
//*
//*

Mage::Mage() : GameCharacter("Unknown Mage", 90, 25), mana(50) {}

Mage::Mage(const std::string& n, int h, int d, int m)
    : GameCharacter(n, h, d), mana(m) {}

Mage::~Mage() {
    std::cout << "NAME: "        << getName()
              << " | HEALTH: "   << getHealth()
              << " | DAMAGE: "   << getDamage()
              << " | MANA: "     << mana
              << " [DESTROYED]"  << std::endl;
}

//*
//*
//*

void Mage::attack(GameCharacter* target) {
    if (target == nullptr) {
        return;
    }

    if (mana >= 10) {
        mana -= 10; 
        int spellDamage = getDamage() * 2; 

        std::cout << getName() << " casts a Fireball! " << target->getName() 
                  << " takes " << spellDamage << " spell damage. [Mana Remaining: " << mana << "]" << std::endl;
                  
        target->takeDamage(spellDamage);
    } 
    else {
        std::cout << getName() << " is out of mana! Attacking weakly with staff. " << std::endl;
        target->takeDamage(getDamage());
    }
}
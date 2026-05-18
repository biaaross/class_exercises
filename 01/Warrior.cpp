#include "Warrior.hpp"
#include <iostream>
#include <string>

Warrior::Warrior() {}
Warrior::Warrior(const std::string& n, int h, int d,int a)
    : GameCharacter(n,h,d) , armor(a) {}

Warrior::~Warrior() {
    std::cout<<"NAME:"<<getName()
             <<"HEALTH:"<<getHealth()
             <<"BASE DAMAGE:"<<getDamage()
             <<"ARMOR:"<<armor
             <<"[DESTROYED]"<<std::endl;
}
void Warrior::attack(GameCharacter* target) {
    if (target == nullptr) {
        return;
    }

    std::cout << getName() << " swings their axe! " 
              << target->getName() << " takes " << getDamage() << " damage." << std::endl;
              
    target->takeDamage(getDamage());
}

void Warrior::takeDamage(int damage) {
   
    int netDamage = damage - armor;
    if (netDamage < 0) {
        netDamage = 0;
    }

    int currentHealth = getHealth();
    int newHealth = currentHealth - netDamage;
    if (newHealth < 0) {
        newHealth = 0;
    }

    setHealth(newHealth);

    std::cout << getName() << " mitigated damage with armor! Net damage taken: " 
              << netDamage << " | Remaining Health: " << getHealth() << std::endl;
}
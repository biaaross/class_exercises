#pragma once

#include "GameCharacter.hpp"
#include <string>

class Mage : public GameCharacter {
private:
    int mana;

public:
   
Mage();
    Mage(const std::string& n, int h, int d, int m);
    ~Mage() override;

    void attack(GameCharacter* target) override;
};
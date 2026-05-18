#pragma once
#include <string>
#include "GameCharacter.hpp"

class Warrior : public GameCharacter {
    private:
    int armor;

    public:
    Warrior();
    Warrior(const std::string& n, int h, int d,int a);
    ~Warrior() override;

    void attack(GameCharacter* target) override;
    void takeDamage(int damage) override;
};
#include "GameCharacter.hpp"
#include <iostream>
#include <string>

//*
//*
//*

GameCharacter::GameCharacter() {}

GameCharacter::GameCharacter(const std::string& n, int h, int d)
    : name(n), health(h), baseDamage(d) {}

GameCharacter::~GameCharacter() {}

//*
//*
//*

void GameCharacter::takeDamage(int damage) {
    if (damage < 0) {
        damage = 0;
    }
    
    health -= damage;
    if (health < 0) {
        health = 0;
    }
    std::cout << name << " " << damage << " hasar aldi! Kalan Can: " << health << std::endl;
}

//*
//*
//*

std::string GameCharacter::getName() const {
    return name;
}

int GameCharacter::getHealth() const {
    return health;
}

int GameCharacter::getDamage() const {
    return baseDamage;
}

//*
//*
//*

void GameCharacter::setName(const std::string& newName) {
    if (!newName.empty()) {
        name = newName;
        return;
    }
    std::cerr << "NewName Is Empty" << std::endl;
}

void GameCharacter::setHealth(int newHealth) {
    if (newHealth >= 0) {
        health = newHealth;
        return;
    }
    std::cerr << "[INVALID VALUE]" << std::endl;
}

void GameCharacter::setDamage(int newDamage) {
    if (newDamage >= 0) {
        baseDamage = newDamage;
        return;
    }
    std::cerr << "[INVALID VALUE]" << std::endl;
}
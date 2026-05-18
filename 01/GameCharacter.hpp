#pragma once

#include <string>

class GameCharacter {
private:
    std::string name;
    int         health;
    int         baseDamage;

public:
    
GameCharacter();
    GameCharacter(const std::string& n, int h, int d);
    virtual ~GameCharacter();

    
    virtual void attack(GameCharacter* target) = 0;
    virtual void takeDamage(int damage);

    
    std::string getName() const;
    int         getHealth() const;
    int         getDamage() const;


    void setName(const std::string& newName);
    void setHealth(int newHealth);
    void setDamage(int newDamage);
};
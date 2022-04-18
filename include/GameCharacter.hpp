#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#include "Object.hpp"

class GameCharacter: public Object {
private:
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;

public:
    GameCharacter(string, string, int = 0, int = 0, int = 0);
    bool checkIsDead();
    int takeDamage(int);

    /* Set & Get function*/
    void setMaxHealth(int);
    void setCurrentHealth(int);
    void setAttack(int);
    void setDefense(int);
    int getMaxHealth();
    int getCurrentHealth();
    int getAttack();
    int getDefense();
};

#endif // GAMECHARACTER_H_INCLUDED

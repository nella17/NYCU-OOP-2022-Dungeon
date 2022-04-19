#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <string>
#include "Object.hpp"

class GameCharacter: public Object {
public:
    GameCharacter(std::string, Object::Type, int = 0, int = 0, int = 0);
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

private:
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
};

#endif // GAMECHARACTER_H_INCLUDED

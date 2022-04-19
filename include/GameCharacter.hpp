#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <string>
#include "Object.hpp"

class GameCharacter: public Object {
public:
    GameCharacter(std::string, Object::Type, int = 0, int = 0, int = 0);
    bool check_is_dead();
    int take_damage(int);

    /* Set & Get function*/
    void set_maxHealth(int);
    void set_currentHealth(int);
    void set_attack(int);
    void set_defense(int);
    int get_maxHealth();
    int get_currentHealth();
    int get_attack();
    int get_defense();

private:
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
};

#endif // GAMECHARACTER_H_INCLUDED

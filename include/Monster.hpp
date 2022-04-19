#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <string>
#include "Object.hpp"
#include "GameCharacter.hpp"

class Monster: public GameCharacter {
public:
    Monster(std::string, int, int, int);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object_ptr);

private:
};

#endif // ENEMY_H_INCLUDED

#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "GameCharacter.hpp"
#include "Player.hpp"

using namespace std;

class Monster: public GameCharacter {
private:

public:
    Monster(string, int, int, int);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(const Object_ptr);
};

#endif // ENEMY_H_INCLUDED

#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

#include "GameCharacter.hpp"
#include "Player.hpp"

class Monster: public GameCharacter {
private:

public:
    Monster(string, int, int, int);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object_ptr);
};

#endif // ENEMY_H_INCLUDED

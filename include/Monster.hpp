#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "helper.hpp"
using namespace std;

#include "GameCharacter.hpp"
#include "Player.hpp"

class Monster: public GameCharacter {
public:
    Monster(string, int, int, int);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool triggerEvent(Object_ptr);

private:
};

#endif // ENEMY_H_INCLUDED

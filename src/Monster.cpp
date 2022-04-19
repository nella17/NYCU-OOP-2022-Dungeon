#include "Monster.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include "helper.hpp"

#include "Player.hpp"

Monster::Monster(std::string _name, int _maxHealth, int _attack, int _defense):
        GameCharacter(_name, Object::Type::Monster, _maxHealth, _attack, _defense) {}

// TODO
bool Monster::triggerEvent(Object_ptr) {
    return false;
}

#include "Monster.hpp"

Monster::Monster(string _name, int _maxHealth, int _attack, int _defense):
        GameCharacter(_name, "Monster", _maxHealth, _attack, _defense) {}

// TODO
bool Monster::triggerEvent(const Object_ptr) {
    return true;
}

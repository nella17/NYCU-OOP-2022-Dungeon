#include "Player.hpp"

Player::Player(string _name, int _maxHealth, int _attack, int _defense):
        GameCharacter(_name, "Player", _maxHealth, _attack, _defense) {}

// TODO
bool Player::triggerEvent(Object_ptr obj) {
    return false;
}

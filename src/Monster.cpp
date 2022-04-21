#include "Monster.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include "helper.hpp"

#include "Player.hpp"

Monster::Monster(std::string _name, int _maxHealth, int _attack, int _defense):
        GameCharacter(_name, Object::Type::Monster, _maxHealth, _attack, _defense) {}

void Monster::print_status(InteractablePtr) {}
void Monster::print_menu() {}
bool Monster::handle_key(int, ObjectPtr) { return false; }

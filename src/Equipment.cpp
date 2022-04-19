#include "Equipment.hpp"

Equipment::Equipment(std::string _name, int _health, int _attack, int _defense):
        Item(_name, Object::Type::Equipment), health(_health), attack(_attack), defense(_defense) {}

int Equipment::getHealth() { return health; }
int Equipment::getAttack() { return attack; }
int Equipment::getDefense() { return defense; }
void Equipment::setHealth(int _health) { health = _health; }
void Equipment::setAttack(int _attack) { attack = _attack; }
void Equipment::setDefense(int _defense) { defense = _defense; }

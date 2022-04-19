#include "Potion.hpp"

Potion::Potion(std::string _name, int _health, int _attack, int _defense):
        Item(_name, Object::Type::Potion), health(_health), attack(_attack), defense(_defense) {}

int Potion::getHealth() { return health; }
int Potion::getAttack() { return attack; }
int Potion::getDefense() { return defense; }
void Potion::setHealth(int _health) { health = _health; }
void Potion::setAttack(int _attack) { attack = _attack; }
void Potion::setDefense(int _defense) { defense = _defense; }

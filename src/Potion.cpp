#include "Potion.hpp"

Potion::Potion(std::string _name, int _health, int _attack, int _defense):
        Item(_name, Object::Type::Potion), health(_health), attack(_attack), defense(_defense) {}

int Potion::get_health() const { return health; }
int Potion::get_attack() const { return attack; }
int Potion::get_defense() const { return defense; }

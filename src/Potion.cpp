#include "Potion.hpp"

Potion::Potion(std::string _name, int _health, int _attack, int _defense):
        Item(_name, Object::Type::Potion), health(_health), attack(_attack), defense(_defense) {}

int Potion::get_health() { return health; }
int Potion::get_attack() { return attack; }
int Potion::get_defense() { return defense; }
void Potion::set_health(int _health) { health = _health; }
void Potion::set_attack(int _attack) { attack = _attack; }
void Potion::set_defense(int _defense) { defense = _defense; }

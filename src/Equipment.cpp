#include "Equipment.hpp"

Equipment::Equipment(std::string _name, int _health, int _attack, int _defense):
        Item(_name, Object::Type::Equipment), health(_health), attack(_attack), defense(_defense) {}

void Equipment::set_health(int _health) { health = _health; }
void Equipment::set_attack(int _attack) { attack = _attack; }
void Equipment::set_defense(int _defense) { defense = _defense; }
int Equipment::get_health() const { return health; }
int Equipment::get_attack() const { return attack; }
int Equipment::get_defense() const { return defense; }

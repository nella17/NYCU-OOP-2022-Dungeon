#include "Equip.hpp"

#include <iostream>
#include "helper.hpp"

#include "Player.hpp"

Equip::Equip(std::string _name, Type _type, int _health, int _attack, int _defense):
        Item(_name, Item::Type::Equip), type(_type), health(_health), attack(_attack), defense(_defense) {}

bool Equip::trigger_event(ObjectPtr obj) {
    auto player = std::dynamic_pointer_cast<Player>(obj);
    if (player == nullptr)
        return false;
    auto equip = std::dynamic_pointer_cast<Equip>(shared_from_this());
    return player->equip_item(equip);
}

std::string Equip::name_of_type() const {
    return enum_name(get_item_type()) + "(" + enum_name(type) + ")";
}

std::ostream& Equip::show_info(std::ostream& os) const {
    return os
        << "health(" << health << ") / "
        << "attack(" << attack << ") / "
        << "defense(" << defense << ")";
}

Equip::Type Equip::get_equip_type() const { return type; }
int Equip::get_health() const { return health; }
int Equip::get_attack() const { return attack; }
int Equip::get_defense() const { return defense; }

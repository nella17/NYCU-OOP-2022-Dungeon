#include "Potion.hpp"

#include <iostream>
#include <stdexcept>
#include "helper.hpp"
#include "MsgBox.hpp"
#include "GameCharacter.hpp"
#include "Monster.hpp"
#include "Player.hpp"

Potion::Potion(std::string _name, Type _type, int _value):
        Item(_name, Item::Type::Potion), type(_type), value(_value) {}

bool Potion::trigger_event(ObjectPtr obj) {
    auto game = std::dynamic_pointer_cast<GameCharacter>(obj);
    if (game == nullptr)
        return MsgBox::add("Potion only works on GameCharacter"), false;
    if (game->get_type() == Object::Type::NPC)
        return MsgBox::add("Potion cannot be used on NPC"), false;
    auto player = std::dynamic_pointer_cast<Player>(game);
    if (player == nullptr)
        return apply_effect(game);
    switch (type) {
        case Type::Heal:
            return apply_effect(player);
        case Type::Damage:
        case Type::Weaken:
            return trigger_event(player->get_interact(1));
        default:
            throw std::runtime_error("Unknown potion type");
    }
}

bool Potion::apply_effect(GameCharacterPtr game) {
    switch (type) {
        case Type::Heal:
            game->heal(value, shared_from_this());
            return true;
        case Type::Damage:
            game->take_damage(value, shared_from_this());
            return true;
        case Type::Weaken:
            game->weaken(value, shared_from_this());
            return true;
        default:
            throw std::runtime_error("Unknown potion type");
    }
}

std::string Potion::name_of_type() const {
    return enum_name(get_item_type()) + "(" + enum_name(type) + ")";
}

std::ostream& Potion::show_info(std::ostream& os) const {
    return os
        << "value(" << value << ")";
}

int Potion::get_value() const { return value; }

#include "Monster.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include "helper.hpp"

#include "Player.hpp"

Monster::Monster(std::string _name, int _maxHealth, int _attack, int _defense):
        GameCharacter(_name, Object::Type::Monster, _maxHealth, _attack, _defense) {}

void Monster::print_status(InteractablePtr) {
    GameCharacter::print_status();
}

void Monster::print_menu() {
    std::cout << "------ Monster Menu ---------\n";
    std::cout << "  [A] \tAttack\n";
}

bool Monster::handle_key(int key, ObjectPtr obj) {
    if (key == LEAVE_KEY && obj == nullptr)
        return check_is_dead();

    auto player = std::dynamic_pointer_cast<Player>(obj);
    if (player == nullptr)
        return false;

    switch (key) {
        case 'A': {
            take_damage(player->get_attack(), player);
            player->take_damage(get_attack(), shared_from_this());
            return check_is_dead();
        }
        default:
            return false;
    }
}

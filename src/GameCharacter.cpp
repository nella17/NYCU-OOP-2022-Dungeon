#include "GameCharacter.hpp"

#include <iostream>
#include "helper.hpp"

GameCharacter::GameCharacter(std::string _name, Object::Type _type, int _maxHealth, int _attack, int _defense):
        Object(_name, _type), maxHealth(_maxHealth), currentHealth(_maxHealth), attack(_attack), defense(_defense) {}

bool GameCharacter::check_is_dead() {
    return currentHealth <= 0;
}
int GameCharacter::take_damage(int damage) {
    return currentHealth -= std::max(0, damage - defense);
}

void GameCharacter::print_status() {
    std::cout << "  Name\t\t: " << get_name() << '\n'
              << "  Health\t: " << get_currentHealth() << " / " << get_maxHealth() << '\n'
              << "  Attack\t: " << get_attack() << '\n'
              << "  Defense\t: " << get_defense() << '\n';
}

int GameCharacter::get_maxHealth() const { return maxHealth; }
int GameCharacter::get_currentHealth() const { return currentHealth; }
int GameCharacter::get_attack() const { return attack; }
int GameCharacter::get_defense() const { return defense; }

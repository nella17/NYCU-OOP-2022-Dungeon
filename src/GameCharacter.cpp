#include "GameCharacter.hpp"

#include <iostream>
#include "helper.hpp"

GameCharacter::GameCharacter(std::string _name, Object::Type _type, int _maxHealth, int _attack, int _defense):
        Object(_name, _type), maxHealth(_maxHealth), currentHealth(_maxHealth), attack(_attack), defense(_defense) {}

bool GameCharacter::check_is_dead() {
    return currentHealth <= 0;
}
int GameCharacter::take_damage(int damage) {
    return currentHealth -= damage;
}

void GameCharacter::set_maxHealth(int _maxHealth) { maxHealth = _maxHealth; }
void GameCharacter::set_currentHealth(int _currentHealth) { currentHealth = _currentHealth; }
void GameCharacter::set_attack(int _attack) { attack = _attack; }
void GameCharacter::set_defense(int _defense) { defense = _defense; }
int GameCharacter::get_maxHealth() const { return maxHealth; }
int GameCharacter::get_currentHealth() const { return currentHealth; }
int GameCharacter::get_attack() const { return attack; }
int GameCharacter::get_defense() const { return defense; }

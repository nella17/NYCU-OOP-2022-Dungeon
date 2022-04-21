#include "GameCharacter.hpp"

#include <iostream>
#include "helper.hpp"
#include "MsgBox.hpp"
#include "Monster.hpp"

GameCharacter::GameCharacter(std::string _name, Object::Type _type, int _maxHealth, int _attack, int _defense):
        Interactable(_name, _type), maxHealth(_maxHealth), currentHealth(_maxHealth), attack(_attack), defense(_defense) {}

bool GameCharacter::check_is_dead() {
    return currentHealth <= 0;
}

void GameCharacter::take_damage(int damage, ObjectPtr obj) {
    auto d = damage - defense;
    currentHealth -= d;
    if (currentHealth < 0)
        currentHealth = 0;
    if (currentHealth > maxHealth)
        currentHealth = maxHealth;
    std::string msg = "";
    msg += get_name() + " takes " + std::to_string(damage) + " damage from " + obj->get_name() + ",\n";
    msg += " actual damage = attack - defense = " + std::to_string(damage) + " - " + std::to_string(defense) + " = " + std::to_string(d) + "\n";
    msg += " and now has " + std::to_string(currentHealth) + " health left.\n";
    MsgBox::add(msg);
    if (check_is_dead()) {
        switch (get_type()) {
            case Object::Type::Player:
                throw std::runtime_error("Player is dead!");
                break;
            case Object::Type::Monster:
                throw std::dynamic_pointer_cast<Monster>(shared_from_this());
                break;
            default:
                throw std::runtime_error("GameCharacter::take_damage unknown type");
        }
    }
}

void GameCharacter::heal(int heal, ObjectPtr obj) {
    currentHealth += heal;
    if (currentHealth > maxHealth)
        currentHealth = maxHealth;
    std::string msg = "";
    msg += get_name() + " heals " + std::to_string(heal) + " health to " + obj->get_name() + ",\n";
    msg += " and now has " + std::to_string(currentHealth) + " health left.\n";
    MsgBox::add(msg);
}

void GameCharacter::weaken(int weaken, ObjectPtr obj) {
    attack -= weaken;
    if (attack < 0)
        attack = 0;
    defense -= weaken;
    if (defense < 0)
        defense = 0;
    std::string msg = "";
    msg += get_name() + " weakens " + std::to_string(weaken) + " attack and defense to " + obj->get_name() + ",\n";
    msg += " and now has " + std::to_string(attack) + " attack and " + std::to_string(defense) + " defense left.\n";
    MsgBox::add(msg);
}

void GameCharacter::print_status(InteractablePtr) {
    std::cout << "  Name\t\t: " << get_name() << '\n'
              << "  Health\t: " << get_currentHealth() << " / " << get_maxHealth() << '\n'
              << "  Attack\t: " << get_attack() << '\n'
              << "  Defense\t: " << get_defense() << '\n';
}

void GameCharacter::increase_status(int _health, int _attack, int _defense) {
    maxHealth += _health;
    currentHealth += _health;
    attack += _attack;
    defense += _defense;
}
void GameCharacter::decrease_status(int _health, int _attack, int _defense) {
    increase_status(-_health, -_attack, -_defense);
}

int GameCharacter::get_maxHealth() const { return maxHealth; }
int GameCharacter::get_currentHealth() const { return currentHealth; }
int GameCharacter::get_attack() const { return attack; }
int GameCharacter::get_defense() const { return defense; }

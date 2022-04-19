#include "GameCharacter.hpp"

#include <iostream>
#include "helper.hpp"

GameCharacter::GameCharacter(std::string _name, Object::Type _type, int _maxHealth, int _attack, int _defense):
        Object(_name, _type), maxHealth(_maxHealth), currentHealth(_maxHealth), attack(_attack), defense(_defense) {}

bool GameCharacter::checkIsDead() {
    return currentHealth <= 0;
}
int GameCharacter::takeDamage(int damage) {
    return currentHealth -= damage;
}

void GameCharacter::setMaxHealth(int _maxHealth) { maxHealth = _maxHealth; }
void GameCharacter::setCurrentHealth(int _currentHealth) { currentHealth = _currentHealth; }
void GameCharacter::setAttack(int _attack) { attack = _attack; }
void GameCharacter::setDefense(int _defense) { defense = _defense; }
int GameCharacter::getMaxHealth() { return maxHealth; }
int GameCharacter::getCurrentHealth() { return currentHealth; }
int GameCharacter::getAttack() { return attack; }
int GameCharacter::getDefense() { return defense; }

void GameCharacter::drawStatus() {
    std::cout << getType() << "'s Status\n"
              << "Name\t: " << getName() << '\n'
              << "Health\t: " << currentHealth << " / " << maxHealth << '\n'
              << "Attack\t: " << attack << '\n'
              << "Defense\t: " << defense << '\n'
            << std::endl;
}

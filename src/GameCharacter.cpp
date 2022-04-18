#include "GameCharacter.hpp"

GameCharacter::GameCharacter(string _name, Object::Type _tag, int _maxHealth, int _attack, int _defense):
        Object(_name, _tag), maxHealth(_maxHealth), currentHealth(_maxHealth), attack(_attack), defense(_defense) {}

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

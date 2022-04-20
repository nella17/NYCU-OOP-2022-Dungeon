#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <string>
#include "Interactable.hpp"
class Record;

class GameCharacter: public Interactable {
    friend class Record;
public:
    GameCharacter(std::string, Object::Type, int = 0, int = 0, int = 0);
    bool check_is_dead();
    int take_damage(int);

    void print_status(InteractablePtr = nullptr);

    /* Set & Get function*/
    int get_maxHealth() const;
    int get_currentHealth() const;
    int get_attack() const;
    int get_defense() const;

private:
    int maxHealth;
    int currentHealth;
    int attack;
    int defense;
};

#endif // GAMECHARACTER_H_INCLUDED

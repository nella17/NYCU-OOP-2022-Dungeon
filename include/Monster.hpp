#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED

#include <string>
#include "Object.hpp"
#include "GameCharacter.hpp"
class Record;

class Monster: public GameCharacter {
    friend class Record;
public:
    Monster(std::string, int, int, int);

    void print_status(InteractablePtr = nullptr);
    void print_menu();
    bool handle_key(int, ObjectPtr);

    /* Virtual function that you need to complete   */
    /* In Monster, this function should deal with   */
    /* the combat system.                           */
    bool trigger_event(ObjectPtr);

private:
};

#endif // ENEMY_H_INCLUDED

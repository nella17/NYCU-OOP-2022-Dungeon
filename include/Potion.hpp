#ifndef POTION_H_INCLUDED
#define POTION_H_INCLUDED

#include <string>
#include "Item.hpp"

class Potion: public Item {
public:
    Potion(std::string, int, int, int);

    /* Set & Get function*/
    int get_health();
    int get_attack();
    int get_defense();
    void set_health(int);
    void set_attack(int);
    void set_defense(int);

private:
    int health, attack, defense;
};

#endif // POTION_H_INCLUDED

#ifndef POTION_H_INCLUDED
#define POTION_H_INCLUDED

#include <string>
#include "Item.hpp"

class Potion: public Item {
public:
    Potion(std::string, int, int, int);

    /* Set & Get function*/
    void set_health(int);
    void set_attack(int);
    void set_defense(int);
    int get_health() const;
    int get_attack() const;
    int get_defense() const;

private:
    int health, attack, defense;
};

#endif // POTION_H_INCLUDED

#ifndef POTION_H_INCLUDED
#define POTION_H_INCLUDED

#include <iostream>
#include <string>
#include "Item.hpp"

class Potion: public Item {
public:
    Potion(std::string, int, int, int);

    std::ostream& show_info(std::ostream&) const;

    /* Set & Get function*/
    int get_health() const;
    int get_attack() const;
    int get_defense() const;

private:
    int health, attack, defense;
};

#endif // POTION_H_INCLUDED

#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include <string>
#include "Item.hpp"

class Equipment: public Item {
public:
    Equipment(std::string, int, int, int);

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

#endif // EQUIPMENT_H_INCLUDED

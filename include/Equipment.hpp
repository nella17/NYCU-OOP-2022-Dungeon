#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include <string>
#include "Item.hpp"

class Equipment: public Item {
public:
    Equipment(std::string, int, int, int);

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

#endif // EQUIPMENT_H_INCLUDED

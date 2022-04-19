#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include <iostream>
#include <string>
#include "Item.hpp"

class Equipment: public Item {
public:
    enum class Type {
        None = 0,
        Head,
        Body,
        LeftHand,
        RightHand,
    };

    Equipment(std::string, Type, int, int, int);

    std::ostream& show_info(std::ostream&) const;

    /* Set & Get function*/
    int get_health() const;
    int get_attack() const;
    int get_defense() const;

private:
    Type type;
    int health, attack, defense;
};

#endif // EQUIPMENT_H_INCLUDED

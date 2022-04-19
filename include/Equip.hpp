#ifndef EQUIP_H_INCLUDED
#define EQUIP_H_INCLUDED

#include <iostream>
#include <string>
#include "Item.hpp"
class Record;

class Equip: public Item {
    friend class Record;
public:
    enum class Type {
        None = 0,
        Head,
        Body,
        LeftHand,
        RightHand,
        Feet,
    };

    Equip(std::string, Type, int, int, int);

    std::string name_of_type() const;
    std::ostream& show_info(std::ostream&) const;

    /* Set & Get function*/
    int get_health() const;
    int get_attack() const;
    int get_defense() const;

private:
    const Type type;
    const int health, attack, defense;
};

#endif // EQUIP_H_INCLUDED

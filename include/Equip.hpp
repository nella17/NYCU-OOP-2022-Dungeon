#ifndef EQUIP_H_INCLUDED
#define EQUIP_H_INCLUDED

#include <iostream>
#include <string>
#include <memory>
#include "Item.hpp"

class Equip;
using EquipPtr = std::shared_ptr<Equip>;

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

    bool trigger_event(ObjectPtr);
    std::string name_of_type() const;
    std::ostream& show_info(std::ostream&) const;

    /* Set & Get function*/
    Type get_equip_type() const;
    int get_health() const;
    int get_attack() const;
    int get_defense() const;

private:
    const Type type;
    const int health, attack, defense;
};

#endif // EQUIP_H_INCLUDED

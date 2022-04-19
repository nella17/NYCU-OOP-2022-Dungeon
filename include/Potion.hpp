#ifndef POTION_H_INCLUDED
#define POTION_H_INCLUDED

#include <iostream>
#include <string>
#include "Item.hpp"

class Potion: public Item {
public:
    enum class Type {
        Heal,
        Damage,
        Weaken,
    };

    Potion(std::string, Type, int);

    std::ostream& show_info(std::ostream&) const;

    /* Set & Get function*/
    int get_value() const;

private:
    const Type type;
    const int value;
};

#endif // POTION_H_INCLUDED

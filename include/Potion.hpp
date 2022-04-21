#ifndef POTION_H_INCLUDED
#define POTION_H_INCLUDED

#include <iostream>
#include <string>
#include "Item.hpp"
#include "GameCharacter.hpp"

class Potion: public Item {
    friend class Record;
public:
    enum class Type {
        Heal,
        Damage,
        Weaken,
    };

    Potion(std::string, Type, int);

    bool trigger_event(ObjectPtr);
    std::string name_of_type() const;
    std::ostream& show_info(std::ostream&) const;

    /* Set & Get function*/
    int get_value() const;

private:
    bool apply_effect(GameCharacterPtr);
    const Type type;
    const int value;
};

#endif // POTION_H_INCLUDED

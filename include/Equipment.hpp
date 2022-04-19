#ifndef EQUIPMENT_H_INCLUDED
#define EQUIPMENT_H_INCLUDED

#include <string>
#include "Item.hpp"

class Equipment: public Item {
public:
    Equipment(std::string, int, int, int);

    /* Set & Get function*/
    int getHealth();
    int getAttack();
    int getDefense();
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);

private:
    int health, attack, defense;
};

#endif // EQUIPMENT_H_INCLUDED

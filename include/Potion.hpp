#ifndef POTION_H_INCLUDED
#define POTION_H_INCLUDED

#include <string>
#include "Item.hpp"

class Potion: public Item {
public:
    Potion(std::string, int, int, int);

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

#endif // POTION_H_INCLUDED

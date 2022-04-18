#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <set>
#include <memory>
using namespace std;

class Item;
using Item_ptr = shared_ptr<Item>;
using Items_set = set<Item_ptr>;

#include "Object.hpp"
#include "Player.hpp"

class Item: public Object {
public:
    Item(string, int, int, int);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool triggerEvent(Object_ptr);

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

#endif // ITEM_H_INCLUDED

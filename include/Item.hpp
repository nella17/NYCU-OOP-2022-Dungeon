#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <set>
#include <memory>
#include "Object.hpp"

class Item;
using Item_ptr = std::shared_ptr<Item>;
using Items_set = std::set<Item_ptr>;

class Item: public Object {
public:
    Item(std::string, int, int, int);

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

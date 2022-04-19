#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <string>
#include <set>
#include <memory>
#include "Object.hpp"

class Item;
using ItemPtr = std::shared_ptr<Item>;
using ItemsSet = std::set<ItemPtr>;

class Item: public Object {
public:
    Item(std::string, Object::Type);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool trigger_event(ObjectPtr);

private:
};

#endif // ITEM_H_INCLUDED

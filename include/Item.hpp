#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <set>
#include <memory>
#include "Object.hpp"
class Record;

class Item;
using ItemPtr = std::shared_ptr<Item>;
using ItemsSet = std::set<ItemPtr>;

class Item: public Object {
    friend class Record;
public:
    enum Type {
        Equip,
        Potion,
        Key,
        Lock,
    };

    Item(std::string, Item::Type, Object::Type = Object::Type::Item);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool trigger_event(ObjectPtr);

    virtual std::string name_of_type() const;
    virtual std::ostream& show_info(std::ostream&) const = 0;

    Item::Type get_item_type() const;

private:
    const Item::Type type;
};

std::ostream& operator<<(std::ostream&, const Item&);

#endif // ITEM_H_INCLUDED

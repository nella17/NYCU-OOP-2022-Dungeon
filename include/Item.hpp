#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>
#include <set>
#include <memory>
#include "Record.hpp"
#include "Object.hpp"

class Item;
using ItemPtr = std::shared_ptr<Item>;
using ItemsSet = std::set<ItemPtr>;

class Item: public Object {
    friend class Record;
public:
    Item(std::string, Object::Type);

    /* Virtual function that you need to complete    */
    /* In Item, this function should deal with the   */
    /* pick up action. You should add status to the  */
    /* player.                                       */
    bool trigger_event(ObjectPtr);

    virtual std::string name_of_type() const;
    virtual std::ostream& show_info(std::ostream&) const = 0;

private:
};

std::ostream& operator<<(std::ostream&, const Item&);

#endif // ITEM_H_INCLUDED

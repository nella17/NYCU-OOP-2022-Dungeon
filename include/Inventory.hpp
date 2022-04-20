#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include <string>
#include <memory>
#include "Interactable.hpp"
#include "Item.hpp"

class Inventory: public Interactable, public ItemsSet {
public:
    Inventory(ItemsSet = {});
    void print_status(InteractablePtr = nullptr);
    void print_menu();
    bool handle_key(int, ObjectPtr = nullptr);
    bool trigger_event(ObjectPtr);

private:
};

#endif // INVENTORY_H_INCLUDED

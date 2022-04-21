#ifndef INVENTORY_H_INCLUDED
#define INVENTORY_H_INCLUDED

#include <string>
#include <memory>
#include "Interactable.hpp"
#include "Item.hpp"

class Inventory;
using InventoryPtr = std::shared_ptr<Inventory>;

class Inventory: public Interactable, public ItemsSet {
    friend class Record;
public:
    Inventory(std::string, ItemsSet = {});
    void print_status(InteractablePtr = nullptr);
    void print_menu();
    bool handle_key(int, ObjectPtr = nullptr);

private:
};

#endif // INVENTORY_H_INCLUDED

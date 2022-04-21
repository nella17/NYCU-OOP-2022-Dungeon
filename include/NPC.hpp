#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <string>
#include "GameCharacter.hpp"
#include "Item.hpp"
#include "Object.hpp"
#include "Inventory.hpp"

class NPC;
using NPCPtr = std::shared_ptr<NPC>;

class NPC: public GameCharacter {
    friend class Record;
public:
    NPC(std::string, std::string, ItemsSet = {});

    void print_status(InteractablePtr = nullptr);
    void print_menu();
    bool handle_key(int, ObjectPtr);

private:
    std::string script;
    InventoryPtr inventory;
};

#endif // NPC_H_INCLUDED

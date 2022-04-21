#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Dungeon.hpp"
#include "Object.hpp"
#include "Interactable.hpp"
#include "Room.hpp"
#include "GameCharacter.hpp"
#include "Player.hpp"
#include "NPC.hpp"
#include "Inventory.hpp"
#include "Item.hpp"
#include "Equip.hpp"
#include "Potion.hpp"
#include "Key.hpp"

/* This is the record system. Get the information of the  */
/* player and rooms then save them to (a) file(s). Notice */
/* that using pass by reference can prevent sending the   */
/* whole vector to the function.                          */

class Record {
public:
    static std::string file_name;
    static bool save(const Dungeon&);
    static bool load(Dungeon&);

private:
    static void save_Object(const ObjectPtr&);
    static void load_Object(ObjectPtr&);

    static void save_Interactable(const InteractablePtr&);
    static void load_Interactable(InteractablePtr&);

    static void save_Rooms(const std::vector<RoomPtr>&);
    static void load_Rooms(std::vector<RoomPtr>&);

    static void save_GameCharacter(const GameCharacterPtr&);
    static void load_GameCharacter(GameCharacterPtr&);

    static void save_Player(const PlayerPtr&);
    static void load_Player(PlayerPtr&);

    static void save_NPC(const NPCPtr&);
    static void load_NPC(NPCPtr&);

    static void save_Inventory(const InventoryPtr&);
    static void load_Inventory(InventoryPtr&);

    static void save_Item(const ItemPtr&);
    static void load_Item(ItemPtr&);

    static void save_Equip(const EquipPtr&);
    static void load_Equip(EquipPtr&);

    static void save_Potion(const PotionPtr&);
    static void load_Potion(PotionPtr&);

    static void save_Key(const KeyPtr&);
    static void load_Key(KeyPtr&);

};

#endif // RECORD_H_INCLUDED

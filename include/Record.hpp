#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iosfwd>
#include <string>
#include <vector>
#include <memory>

#include "Dungeon.hpp"
#include "Object.hpp"
#include "Interactable.hpp"
#include "Room.hpp"
#include "GameCharacter.hpp"
#include "Player.hpp"
#include "Monster.hpp"
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
    static bool exists();
    static bool save(Dungeon*);
    static bool load(Dungeon*);

private:
    static void save_Dungeon();
    static void load_Dungeon();

    static void save_Object(const ObjectPtr&);
    static ObjectPtr load_Object();

    static void save_Interactable(const InteractablePtr&);
    static InteractablePtr load_Interactable(Object::Type);

    static int get_room_id(const RoomPtr&);
    static RoomPtr load_room_by_id();

    static void save_Room(const RoomPtr&);
    static RoomPtr load_Room();

    static void save_Room_neighbors(const RoomPtr&);
    static void load_Room_neighbors(RoomPtr);

    static void save_GameCharacter(const GameCharacterPtr&);
    static GameCharacterPtr load_GameCharacter(Object::Type);

    static void save_Player(const PlayerPtr&);
    static PlayerPtr load_Player();

    static void save_Monster(const MonsterPtr&);
    static MonsterPtr load_Monster();

    static void save_NPC(const NPCPtr&);
    static NPCPtr load_NPC();

    static void save_Inventory(const InventoryPtr&);
    static InventoryPtr load_Inventory();

    static void save_Item(const ItemPtr&);
    static ItemPtr load_Item();

    static void save_Equip(const EquipPtr&);
    static EquipPtr load_Equip();

    static void save_Potion(const PotionPtr&);
    static PotionPtr load_Potion();

    static void save_Key(const KeyPtr&);
    static KeyPtr load_Key(Item::Type);

};

#endif // RECORD_H_INCLUDED

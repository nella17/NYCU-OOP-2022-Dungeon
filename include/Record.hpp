#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Dungeon.hpp"
#include "Object.hpp"
#include "Room.hpp"
// GameCharacter
#include "Player.hpp"
#include "Monster.hpp"
#include "NPC.hpp"
// Item
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
    static void save_GameCharacter(const GameCharacterPtr&);
    static void load_GameCharacter(GameCharacterPtr&);

    static void save_Player(const PlayerPtr&);
    static void load_Player(PlayerPtr&);

    static void save_Rooms(const std::vector<RoomPtr>&);
    static void load_Rooms(std::vector<RoomPtr>&);
};

#endif // RECORD_H_INCLUDED

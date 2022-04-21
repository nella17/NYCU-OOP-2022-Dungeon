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
    static void save(const PlayerPtr);
    static void load(PlayerPtr&);

    static void save(const std::vector<RoomPtr>&);
    static void load(std::vector<RoomPtr>&);
};

#endif // RECORD_H_INCLUDED

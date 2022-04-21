#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Room.hpp"
#include "Player.hpp"

/* This is the record system. Get the information of the  */
/* player and rooms then save them to (a) file(s). Notice */
/* that using pass by reference can prevent sending the   */
/* whole vector to the function.                          */

class Record {
public:
    static std::string file_name;
    static bool save(const PlayerPtr, const std::vector<RoomPtr>&);
    static bool load(PlayerPtr&, std::vector<RoomPtr>&);
private:
    static void save_player(const PlayerPtr);
    static void load_player(PlayerPtr&);
    static void save_rooms(const std::vector<RoomPtr>&);
    static void load_rooms(std::vector<RoomPtr>&);
};

#endif // RECORD_H_INCLUDED

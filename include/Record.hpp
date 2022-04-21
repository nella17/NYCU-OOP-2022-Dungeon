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
    static const std::string file_name;
    static void save_to_file(const PlayerPtr, const std::vector<Room>&);
    static void load_from_file(PlayerPtr&, std::vector<Room>&);
private:
    static void save_player(const PlayerPtr);
    static void load_player(PlayerPtr&);
    static void save_rooms(const std::vector<Room>&);
    static void load_rooms(std::vector<Room>&);
};

#endif // RECORD_H_INCLUDED

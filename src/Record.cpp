#include "Record.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "helper.hpp"

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

std::string Record::file_name = "save.txt";
namespace {
    std::fstream io;
};

void Record::save(const PlayerPtr player, const std::vector<RoomPtr>& rooms) {
    io = std::fstream(file_name);
    save_player(player);
    save_rooms(rooms);
    io.close();
}
void Record::load(PlayerPtr& player, std::vector<RoomPtr>& rooms) {
    io = std::fstream(file_name);
    load_player(player);
    load_rooms(rooms);
    io.close();
}

// TODO
void Record::save_player(const PlayerPtr) {}
// TODO
void Record::load_player(PlayerPtr&) {}

// TODO
void Record::save_rooms(const std::vector<RoomPtr>&) {}
// TODO
void Record::load_rooms(std::vector<RoomPtr>&) {}

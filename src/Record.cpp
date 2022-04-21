#include "Record.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <exception>
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

bool Record::save(const PlayerPtr player, const std::vector<RoomPtr>& rooms) {
    try {
        io.open(file_name);
        if (!io.is_open())
            throw std::runtime_error("Can't open file \"" + file_name + "\"");
        save_player(player);
        save_rooms(rooms);
        io.close();
        return true;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return false;
    }
}
bool Record::load(PlayerPtr& player, std::vector<RoomPtr>& rooms) {
    try {
        io.open(file_name);
        if (!io.is_open())
            throw std::runtime_error("Can't open file \"" + file_name + "\"");
        load_player(player);
        load_rooms(rooms);
        io.close();
        return true;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return false;
    }
}

// TODO
void Record::save_player(const PlayerPtr) {}
// TODO
void Record::load_player(PlayerPtr&) {}

// TODO
void Record::save_rooms(const std::vector<RoomPtr>&) {}
// TODO
void Record::load_rooms(std::vector<RoomPtr>&) {}

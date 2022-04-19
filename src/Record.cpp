#include "Record.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "helper.hpp"

#include "Item.hpp"
#include "Monster.hpp"
#include "NPC.hpp"

namespace {
// TODO
void save_player(const std::shared_ptr<Player>, std::ofstream&&) {}

// TODO
void load_player(std::shared_ptr<Player>&, std::ifstream&&) {}

// TODO
void save_rooms(const std::vector<Room>&, std::ofstream&&) {}
// TODO
void load_rooms(std::vector<Room>&, std::ifstream&&) {}
};

void Record::save_to_file(const std::shared_ptr<Player> player, const std::vector<Room>& rooms) {
    save_player(player, std::ofstream("data/player.txt"));
    save_rooms(rooms, std::ofstream("data/rooms.txt"));
}
void Record::load_from_file(std::shared_ptr<Player>& player, std::vector<Room>& rooms) {
    load_player(player, std::ifstream("data/player.txt"));
    load_rooms(rooms, std::ifstream("data/rooms.txt"));
}

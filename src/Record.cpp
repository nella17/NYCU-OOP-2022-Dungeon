#include "Record.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include "helper.hpp"

#include "Item.hpp"
#include "Monster.hpp"
#include "NPC.hpp"

// TODO
void savePlayer(const std::shared_ptr<Player>, std::ofstream&&) {}

// TODO
void loadPlayer(std::shared_ptr<Player>&, std::ifstream&&) {}

// TODO
void saveRooms(const std::vector<Room>&, std::ofstream&&) {}
// TODO
void loadRooms(std::vector<Room>&, std::ifstream&&) {}

void Record::saveToFile(const std::shared_ptr<Player> player, const std::vector<Room>& rooms) {
    savePlayer(player, std::ofstream("data/player.txt"));
    saveRooms(rooms, std::ofstream("data/rooms.txt"));
}
void Record::loadFromFile(std::shared_ptr<Player>& player, std::vector<Room>& rooms) {
    loadPlayer(player, std::ifstream("data/player.txt"));
    loadRooms(rooms, std::ifstream("data/rooms.txt"));
}

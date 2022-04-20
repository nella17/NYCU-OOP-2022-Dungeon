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

void Record::save_to_file(const PlayerPtr player, const std::vector<Room>& rooms) {
    save_player(player, std::ofstream("data/player.txt"));
    save_rooms(rooms, std::ofstream("data/rooms.txt"));
}
void Record::load_from_file(PlayerPtr& player, std::vector<Room>& rooms) {
    load_player(player, std::ifstream("data/player.txt"));
    load_rooms(rooms, std::ifstream("data/rooms.txt"));
}

// TODO
void Record::save_player(const PlayerPtr, std::ofstream&&) {}
// TODO
void Record::load_player(PlayerPtr&, std::ifstream&&) {}

// TODO
void Record::save_rooms(const std::vector<Room>&, std::ofstream&&) {}
// TODO
void Record::load_rooms(std::vector<Room>&, std::ifstream&&) {}

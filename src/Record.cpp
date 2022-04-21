#include "Record.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <exception>
#include "helper.hpp"

#define _ <<' '<<

std::string Record::file_name = "save.txt";
namespace {
    std::fstream io;
};

bool Record::save(const Dungeon& dungeon) {
    try {
        io.open(file_name, std::ios::out);
        if (!io.is_open())
            throw std::runtime_error("Can't open file \"" + file_name + "\"");
        save(dungeon.player);
        save(dungeon.rooms);
        io.close();
        return true;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return false;
    }
}
bool Record::load(Dungeon& dungeon) {
    try {
        io.open(file_name, std::ios::in);
        if (!io.is_open())
            throw std::runtime_error("Can't open file \"" + file_name + "\"");
        load(dungeon.player);
        load(dungeon.rooms);
        io.close();
        return true;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return false;
    }
}

void Record::save(const PlayerPtr player) {
}

void Record::load(PlayerPtr&) {
}

void Record::save(const std::vector<RoomPtr>& rooms) {
    io _ rooms.size();
    for(const auto& room : rooms) {
        io _ room->isBlocked _ room->isLocked _ room->isExit _ room->index;
        io _ room->neighbors.size();
        for(const auto& [dir, neighbor] : room->neighbors)
            io _ enum_name(dir) _ neighbor->index;
    }
}
void Record::load(std::vector<RoomPtr>& rooms) {
    int size;
    io >> size;
    rooms.resize(size);
    for(auto& room: rooms) {
        io >> room->isBlocked >> room->isLocked >> room->isExit >> room->index;
        size_t sz;
        io >> sz;
        while (sz--) {
            std::string s;
            int index;
            io >> s >> index;
            auto dir = magic_enum::enum_cast<Direction>(s).value_or(Direction::None);
            room->neighbors[dir] = rooms[index];
        }
    }
}

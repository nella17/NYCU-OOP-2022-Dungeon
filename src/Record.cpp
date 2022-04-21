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
}
void Record::load(std::vector<RoomPtr>& rooms) {
}

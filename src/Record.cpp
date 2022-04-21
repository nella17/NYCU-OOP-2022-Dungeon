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

    template<typename E>
    std::enable_if_t<std::is_enum_v<E>, std::istream&>
    operator>>(std::istream& is, E &e) {
        std::string s; is >> s;
        e = enum_cast<E>(s).value();
        return is;
    }

    template<typename E>
    std::enable_if_t<std::is_enum_v<E>, std::ostream&>
    operator<<(std::ostream& os, const E &e) {
        return os << enum_name(e);
    }
};

bool Record::save(const Dungeon& dungeon) {
    try {
        io.open(file_name, std::ios::out);
        if (!io.is_open())
            throw std::runtime_error("Can't open file \"" + file_name + "\"");
        save_Player(dungeon.player);
        save_Rooms(dungeon.rooms);
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
        load_Player(dungeon.player);
        load_Rooms(dungeon.rooms);
        io.close();
        return true;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return false;
    }
}


void Record::save_Object(const ObjectPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
void Record::load_Object(ObjectPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Interactable(const InteractablePtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
void Record::load_Interactable(InteractablePtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Rooms(const std::vector<RoomPtr>& rooms) {
    io _ rooms.size();
    for(const auto& room : rooms) {
        io _ room->isBlocked _ room->isLocked _ room->isExit _ room->index;
        io _ room->neighbors.size();
        for(const auto& [dir, neighbor] : room->neighbors)
            io _ dir _ neighbor->index;
    }
}
void Record::load_Rooms(std::vector<RoomPtr>& rooms) {
    int size;
    io >> size;
    rooms.resize(size);
    for(auto& room: rooms) {
        io >> room->isBlocked >> room->isLocked >> room->isExit >> room->index;
        size_t sz;
        io >> sz;
        while (sz--) {
            Direction dir;
            int index;
            io >> dir >> index;
            room->neighbors[dir] = rooms[index];
        }
    }
}

void Record::save_GameCharacter(const GameCharacterPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
void Record::load_GameCharacter(GameCharacterPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Player(const PlayerPtr& player) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
void Record::load_Player(PlayerPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_NPC(const NPCPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
void Record::load_NPC(NPCPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Inventory(const InventoryPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
void Record::load_Inventory(InventoryPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Item(const ItemPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
void Record::load_Item(ItemPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Equip(const EquipPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
void Record::load_Equip(EquipPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Potion(const PotionPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
void Record::load_Potion(PotionPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Key(const KeyPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
void Record::load_Key(KeyPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

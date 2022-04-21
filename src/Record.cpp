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
    Dungeon* dungeon;

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

bool Record::save(Dungeon* _dungeon) {
    dungeon = _dungeon;
    try {
        io.open(file_name, std::ios::out);
        if (!io.is_open())
            throw std::runtime_error("Can't open file \"" + file_name + "\"");
        save_Dungeon();
        io.close();
        return true;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return false;
    }
}
bool Record::load(Dungeon* _dungeon) {
    dungeon = _dungeon;
    try {
        io.open(file_name, std::ios::in);
        if (!io.is_open())
            throw std::runtime_error("Can't open file \"" + file_name + "\"");
        load_Dungeon();
        io.close();
        return true;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
        return false;
    }
}


void Record::save_Dungeon() {
    save_Object(dungeon->player);
    io _ dungeon->rooms.size();
    for(const auto& room: dungeon->rooms)
        save_Object(room);
}

void Record::load_Dungeon() {
    dungeon->player = std::dynamic_pointer_cast<Player>(load_Object());
    int size; io >> size;
    dungeon->rooms.resize(size);
    for(auto& room: dungeon->rooms)
        room = std::dynamic_pointer_cast<Room>(load_Object());
}

void Record::save_Object(const ObjectPtr& obj) {
    io _ obj->name _ obj->type;
    switch (obj->type) {
        case Object::Type::Item:
        case Object::Type::Lock:
            save_Item(std::dynamic_pointer_cast<Item>(obj));
            break;
        case Object::Type::Inventory:
            save_Inventory(std::dynamic_pointer_cast<Inventory>(obj));
            break;
        case Object::Type::Player:
            save_Player(std::dynamic_pointer_cast<Player>(obj));
            break;
        case Object::Type::Monster:
            save_Monster(std::dynamic_pointer_cast<Monster>(obj));
            break;
        case Object::Type::NPC:
            save_NPC(std::dynamic_pointer_cast<NPC>(obj));
            break;
        case Object::Type::Room:
            save_Room(std::dynamic_pointer_cast<Room>(obj));
            break;
    }
}
ObjectPtr Record::load_Object() {
    std::string name; io >> name;
    Object::Type type; io >> type;
    ObjectPtr obj;
    switch (type) {
        case Object::Type::Item:
        case Object::Type::Lock:
            obj = load_Item();
            break;
        case Object::Type::Inventory:
            obj = load_Inventory();
            break;
        case Object::Type::Player:
            obj = load_Player();
            break;
        case Object::Type::Monster:
            obj = load_Monster();
            break;
        case Object::Type::NPC:
            obj = load_NPC();
            break;
        case Object::Type::Room:
            obj = load_Room();
            break;
    }
    assert(obj->type == type);
    obj->name = name;
}

void Record::save_Interactable(const InteractablePtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
InteractablePtr Record::load_Interactable() {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Room(const RoomPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
RoomPtr Record::load_Room() {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_GameCharacter(const GameCharacterPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
GameCharacterPtr Record::load_GameCharacter() {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Player(const PlayerPtr& player) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
PlayerPtr Record::load_Player() {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Monster(const MonsterPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
MonsterPtr Record::load_Monster() {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_NPC(const NPCPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
NPCPtr Record::load_NPC() {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Inventory(const InventoryPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
InventoryPtr Record::load_Inventory() {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Item(const ItemPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
ItemPtr Record::load_Item() {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Equip(const EquipPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
EquipPtr Record::load_Equip() {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Potion(const PotionPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
PotionPtr Record::load_Potion() {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

void Record::save_Key(const KeyPtr&) {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}
KeyPtr Record::load_Key() {
    throw std::runtime_error("Not implemented " + std::string(__func__));
}

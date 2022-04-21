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

    void save_str(std::string& s) {
        io _ '@' << s << '@';
    }
    std::string load_str() {
        std::string s = "";
        char c;
        do c = io.get(); while (c != '@');
        c = io.get();
        while (c != '@') {
            s += c;
            c = io.get();
        }
        return s;
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
    io _ dungeon->rooms.size();
    for(const auto& room: dungeon->rooms)
        save_Object(room);
    for(const auto& room: dungeon->rooms)
        save_Room_neighbors(room);
    save_Object(dungeon->player);
}
void Record::load_Dungeon() {
    int size; io >> size;
    dungeon->rooms.resize(size);
    for(auto& room: dungeon->rooms)
        room = std::dynamic_pointer_cast<Room>(load_Object());
    for(auto& room: dungeon->rooms)
        load_Room_neighbors(room);
    dungeon->player = std::dynamic_pointer_cast<Player>(load_Object());
}

void Record::save_Object(const ObjectPtr& ptr) {
    save_str(ptr->name);
    io _ ptr->type;
    switch (ptr->type) {
        case Object::Type::Item:
        case Object::Type::Lock:
            save_Item(std::dynamic_pointer_cast<Item>(ptr));
            break;
        case Object::Type::Inventory:
            save_Inventory(std::dynamic_pointer_cast<Inventory>(ptr));
            break;
        case Object::Type::Player:
        case Object::Type::Monster:
        case Object::Type::NPC:
            save_GameCharacter(std::dynamic_pointer_cast<GameCharacter>(ptr));
            break;
        case Object::Type::Room:
            save_Room(std::dynamic_pointer_cast<Room>(ptr));
            break;
        case Object::Type::None:
            throw std::runtime_error("Can't save object of type None");
    }
}
ObjectPtr Record::load_Object() {
    std::string name = load_str();
    Object::Type type; io >> type;
    ObjectPtr ptr;
    switch (type) {
        case Object::Type::Item:
        case Object::Type::Lock:
            ptr = load_Item();
            break;
        case Object::Type::Inventory:
            ptr = load_Inventory();
            break;
        case Object::Type::Player:
        case Object::Type::Monster:
        case Object::Type::NPC:
            ptr = load_GameCharacter(type);
            break;
        case Object::Type::Room:
            ptr = load_Room();
            break;
        case Object::Type::None:
            throw std::runtime_error("Can't save object of type None");
    }
    assert(ptr->type == type);
    ptr->name = name;
    return ptr;
}

void Record::save_Room(const RoomPtr& room) {
    io _ room->isBlocked _ room->isLocked _ room->isExit _ room->index;
    io _ room->objects.size();
    for(const auto& [key, obj]: room->objects) {
        io _ key;
        save_Object(obj);
    }
}
RoomPtr Record::load_Room() {
    RoomPtr room = std::make_shared<Room>();
    io >> room->isBlocked >> room->isLocked >> room->isExit >> room->index;
    int size; io >> size;
    while (size--) {
        int key; io >> key;
        room->objects[key] = load_Object();
    }
    return room;
}

void Record::save_Room_neighbors(const RoomPtr& room) {
    io _ room->neighbors.size();
    for(const auto& [dir, neighbor]: room->neighbors)
        io _ dir _ neighbor->index;
}
void Record::load_Room_neighbors(RoomPtr room) {
    int size; io >> size;
    while (size--) {
        Direction dir; io >> dir;
        int index; io >> index;
        room->neighbors[dir] = dungeon->rooms[index];
    }
}

void Record::save_GameCharacter(const GameCharacterPtr& ptr) {
    io _ ptr->maxHealth _ ptr->currentHealth _ ptr->attack _ ptr->defense;
    switch (ptr->type) {
        case Object::Type::Player:
            save_Player(std::dynamic_pointer_cast<Player>(ptr));
            break;
        case Object::Type::Monster:
            save_Monster(std::dynamic_pointer_cast<Monster>(ptr));
            break;
        case Object::Type::NPC:
            save_NPC(std::dynamic_pointer_cast<NPC>(ptr));
            break;
        default:
            throw std::runtime_error("Can't save object of type " + enum_name(ptr->type) + " as GameCharacter");
    }
}
GameCharacterPtr Record::load_GameCharacter(Object::Type type) {
    int maxHealth; io >> maxHealth;
    int currentHealth; io >> currentHealth;
    int attack; io >> attack;
    int defense; io >> defense;
    GameCharacterPtr ptr;
    switch (type) {
        case Object::Type::Player:
            ptr = load_Player();
            break;
        case Object::Type::Monster:
            ptr = load_Monster();
            break;
        case Object::Type::NPC:
            ptr = load_NPC();
            break;
        default:
            throw std::runtime_error("Can't load object of type " + enum_name(type) + " as GameCharacter");
    }
    ptr->maxHealth = maxHealth;
    ptr->currentHealth = currentHealth;
    ptr->attack = attack;
    ptr->defense = defense;
    return ptr;
}

void Record::save_Player(const PlayerPtr& player) {
    io _ player->currentRoom->index _ player->previousRoom->index;
    save_Object(player->inventory);
    io _ player->equips.size();
    for(const auto& [type, equip]: player->equips) {
        io _ type;
        save_Object(equip);
    }
}
PlayerPtr Record::load_Player() {
    PlayerPtr player = std::make_shared<Player>("", 0, 0, 0);
    io >> player->currentRoom->index >> player->previousRoom->index;
    player->inventory = std::dynamic_pointer_cast<Inventory>(load_Object());
    int size; io >> size;
    while (size--) {
        Equip::Type type; io >> type;
        player->equips[type] = std::dynamic_pointer_cast<Equip>(load_Object());
    }
    return player;
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

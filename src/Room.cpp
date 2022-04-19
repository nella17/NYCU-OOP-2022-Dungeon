#include "Room.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <random>

Room::Room(bool _isExit, int _index, ObjectsMap _objects):
    isBlocked(false), isExit(_isExit), index(_index), objects(_objects) {}

constexpr int name_size = 2;

std::string Room::name() {
    std::mt19937 gen(index);
    std::string name = "";
    if (isExit) name = std::string("Exit").substr(0, name_size);
    for (int i = name.size(); i < name_size; i++) {
        int x = gen() % 16;
        name += (char)(x + (x < 10 ? '0' : 'A' - 10));
    }
    return name;
}

void Room::draw_neighbors(Room* previous) {
    auto get_name = [&](DIRECTION dir = DIRECTION::None) {
        auto ptr = get_neighbor(dir, previous);
        auto name = ptr ? '[' + ptr->name() + ']' : std::string(name_size+2,' ');
        if (isBlocked && ptr == nullptr) name = "[🔒 ]";
        return name;
    };
    std::cout << std::string(name_size+2,' ') << get_name(DIRECTION::UP) << '\n'
            << get_name(DIRECTION::LEFT) << get_name()  << get_name(DIRECTION::RIGHT) << '\n'
            << std::string(name_size+2,' ') << get_name(DIRECTION::DOWN) << '\n'
            << std::endl;
}

bool Room::trigger_object_event(int key, ObjectPtr obj) {
    auto it = objects.find(key);
    if (it == objects.end())
        return false;
    return it->second->trigger_event(obj);
}

void Room::push_object(int key, ObjectPtr obj) {
    objects.emplace(key, obj);
    switch_states(true, obj);
}

bool Room::pop_object(int key) {
    auto it = objects.find(key);
    if (it == objects.end())
        return false;
    switch_states(false, it->second);
    objects.erase(it);
    return true;
}

/* Set & Get function*/
void Room::set_room(DIRECTION dir, Room* room) { neighbors[dir] = room; }
void Room::set_isExit(bool _isExit) { isExit = _isExit; }
void Room::set_index(int _index) { index = _index; }
void Room::clear_objects() {
    isBlocked = false;
    objects.clear();
}
bool Room::get_isExit() { return isExit; }
bool Room::get_isBlocked() { return isBlocked; }
int Room::get_index() { return index; }
ObjectPtr Room::get_object(int key) {
    auto it = objects.find(key);
    if (it == objects.end())
        return nullptr;
    return it->second;
}
ObjectsMap Room::get_objects() { return objects; }
Room* Room::get_neighbor(DIRECTION dir, Room* previous) {
    if (dir == DIRECTION::None)
        return this;
    auto it = neighbors.find(dir);
    if (it == neighbors.end())
        return nullptr;
    auto ptr = it->second;
    if (isBlocked && ptr != previous)
        ptr = nullptr;
    return ptr;
}

void Room::switch_states(bool value, ObjectPtr obj) {
    switch (obj->get_type()) {
        case Object::Type::Monster:
            isBlocked = value;
            break;
        default:
            break;
    }
}

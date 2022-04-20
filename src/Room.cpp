#include "Room.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <random>

Room::Room(bool _isExit, int _index, ObjectsMap _objects):
    isBlocked(false), isLocked(false), isExit(_isExit), index(_index), objects(_objects) {}

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
        auto name = std::string(name_size+2,' ');
        if (ptr == nullptr) {
            if (isBlocked) name = "[❓ ]";
        } else {
            name = '[' + ptr->name() + ']';
            if (ptr->isLocked) name = "[🔒 ]";
        }
        return name;
    };
    std::cout << "  +" << std::string((name_size+2)*3,'-') << "+\n"
              << "  |" << std::string(name_size+2,'.') << get_name(DIRECTION::UP) << std::string(name_size+2,'.') << "|\n"
              << "  |" << get_name(DIRECTION::LEFT) << get_name()  << get_name(DIRECTION::RIGHT) << "|\n"
              << "  |" << std::string(name_size+2,'.') << get_name(DIRECTION::DOWN) << std::string(name_size+2,'.') << "|\n"
              << "  +" << std::string((name_size+2)*3,'-') << "+\n";
}

void Room::print_menu() {
    for(auto [key, obj]: get_objects())
        std::cout << "  [" << char(key) << "] " << enum_name(obj->get_type()) << "\t" << obj->get_name() << '\n';
}

bool Room::trigger_object_event(int key, ObjectPtr obj) {
    auto ptr = get_object(key);
    if (ptr == nullptr)
        return false;
    return ptr->trigger_event(obj);
}

void Room::push_object(int key, ObjectPtr obj) {
    objects.emplace(key, obj);
    switch_states(true, obj);
}

bool Room::pop_object(int key) {
    auto ptr = get_object(key);
    if (ptr == nullptr)
        return false;
    switch_states(false, ptr);
    objects.erase(key);
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
bool Room::get_isExit() const { return !isLocked && isExit; }
bool Room::get_isBlocked() const { return isBlocked; }
int Room::get_index() const { return index; }
ObjectPtr Room::get_object(int key) const {
    auto it = objects.find(key);
    if (it == objects.end())
        return nullptr;
    return it->second;
}
ObjectsMap Room::get_objects() const {
    ObjectsMap ret;
    for (auto [key, obj]: objects)
        if (check_object(obj) != nullptr)
            ret.emplace(key, obj);
    return ret;
}
Room* Room::get_neighbor(DIRECTION dir, Room* previous) const {
    if (dir == DIRECTION::None)
        return (Room*)this;
    auto it = neighbors.find(dir);
    if (it == neighbors.end())
        return nullptr;
    auto ptr = it->second;
    if (ptr != previous) if (isBlocked || isLocked)
        ptr = nullptr;
    return ptr;
}

void Room::switch_states(bool value, ObjectPtr obj) {
    switch (obj->get_type()) {
        case Object::Type::Lock:
            isLocked = value;
            [[fallthrough]];
        case Object::Type::Monster:
            isBlocked = value;
            break;
        default:
            break;
    }
}

ObjectPtr Room::check_object(ObjectPtr obj) const {
    if (isLocked) {
        if (obj->get_type() != Object::Type::Lock)
            return nullptr;
    } else if (isBlocked) {
        if (obj->get_type() != Object::Type::Monster)
            return nullptr;
    }
    return obj;
}

#include "Room.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include "GameCharacter.hpp"

constexpr int name_size = 2;
std::string Room::name(int index, bool isExit) {
    std::mt19937 gen(index);
    std::string name = "";
    if (isExit) name = std::string("Exit").substr(0, name_size);
    for (int i = name.size(); i < name_size; i++) {
        int x = gen() % 16;
        name += (char)(x + (x < 10 ? '0' : 'A' - 10));
    }
    return name;
}

Room::Room(int _index, bool _isExit, ObjectsMap _objects):
    Object(name(_index, _isExit), Object::Type::Room), isBlocked(false), isLocked(false), isExit(_isExit), index(_index), objects(_objects) {}

void Room::draw_neighbors(RoomPtr previous) {
    auto get_name = [&](DIRECTION dir = DIRECTION::None) {
        auto ptr = get_neighbor(dir, previous);
        auto name = std::string(name_size+2,' ');
        if (ptr == nullptr) {
            if (isBlocked) name = "[❓ ]";
        } else {
            name = '[' + ptr->get_name() + ']';
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
    auto objs = get_objects();
    if (!objs.empty()) {
        std::cout << "---- room menu ----\n";
        for(auto [key, obj]: get_objects())
            std::cout << "  [" << char(key) << "] " << enum_name(obj->get_type()) << "\t" << obj->get_name() << '\n';
    }
}

bool Room::trigger_event(int key, ObjectPtr obj) {
    auto ptr = get_object(key);
    if (ptr == nullptr)
        return false;
    return ptr->trigger_event(key, obj);
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
void Room::set_room(DIRECTION dir, RoomPtr room) { neighbors[dir] = room; }
void Room::set_isExit(bool _isExit) {
    isExit = _isExit;
    set_name(name(index, isExit));
}
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
RoomPtr Room::get_neighbor(DIRECTION dir, RoomPtr previous) {
    if (dir == DIRECTION::None)
        return std::dynamic_pointer_cast<Room>(shared_from_this());
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

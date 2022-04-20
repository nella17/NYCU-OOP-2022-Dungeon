#include "Room.hpp"

#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include "GameCharacter.hpp"
#include "Player.hpp"

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
    Interactable(name(_index, _isExit), Object::Type::Room), isBlocked(false), isLocked(false), isExit(_isExit), index(_index), objects(_objects) {}

void Room::print_status(InteractablePtr interact) {
    auto previous = interact->get_type() != Object::Type::Player ? nullptr : std::dynamic_pointer_cast<Player>(interact)->get_previousRoom();
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
    std::cout << "--------- Room Menu ---------\n";
    std::cout << "  [W][A][S][D] \tMovement\n";
    for(auto&& [key, obj]: get_objects())
        std::cout << "  [" << char(key) << "] " << enum_name(obj->get_type()) << "\t" << obj->get_name() << '\n';
}

bool Room::handle_key(int key, ObjectPtr obj) {
    if (is_dir_key(key)) {
        auto dir = key_to_dir(key);
        auto previous = std::dynamic_pointer_cast<Player>(obj)->get_previousRoom();;
        auto room = get_neighbor(dir, previous);
        if (room == nullptr)
            return false;
        throw room;
    }

    auto ptr = get_object(key);
    if (ptr == nullptr)
        return false;
    auto interact = std::dynamic_pointer_cast<Interactable>(ptr);
    if (interact != nullptr)
        throw interact;

    auto player = std::dynamic_pointer_cast<Player>(obj);
    if (player != nullptr && ptr->get_type() == Object::Type::Item) {
        auto item = std::dynamic_pointer_cast<Item>(ptr);
        player->add_item(item);
        return assert(pop_object(key)), true;
    }

    if (ptr->trigger_event(obj))
        return assert(pop_object(key)), true;

    return false;
}

bool Room::trigger_event(ObjectPtr) {
    return false;
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
    return check_object(it->second);
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
    auto item = std::dynamic_pointer_cast<Item>(obj);
    switch (obj->get_type()) {
        case Object::Type::Item:
            if (item == nullptr or item->get_item_type() != Item::Type::Lock)
                break;
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
    auto item = std::dynamic_pointer_cast<Item>(obj);
    if (isLocked) {
        if (item != nullptr && item->get_item_type() != Item::Type::Lock)
            return nullptr;
    } else if (isBlocked) {
        if (obj->get_type() != Object::Type::Monster)
            return nullptr;
    }
    return obj;
}

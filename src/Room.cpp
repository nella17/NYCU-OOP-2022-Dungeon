#include "Room.hpp"

Room::Room(bool _isExit, int _index, Objects_map _objects):
    isExit(_isExit), index(_index), objects(_objects) {}

constexpr int name_size = 2;

std::string Room::name() {
    std::mt19937 gen(index);
    std::string s = "";
    for (int i = 0; i < name_size; i++) {
        int x = gen() % 16;
        s += (char)(x + (x < 10 ? '0' : 'A' - 10));
    }
    return s;
}

void Room::switchState(bool value, Object_ptr object) {
    switch (object->getType()) {
        case Object::Type::Monster:
            isBlocked = value;
            break;
        default:
            break;
    }
}

void Room::pushObject(int key, Object_ptr object) {
    objects.emplace(key, object);
    switchState(true, object);
}

bool Room::popObject(int key) {
    auto it = objects.find(key);
    if (it == objects.end())
        return false;
    switchState(false, it->second);
    objects.erase(it);
    return true;
}

/* Set & Get function*/
void Room::setRoom(DIRECTION dir, Room* room) { neighborRooms[dir] = room; }
void Room::setIsExit(bool _isExit) { isExit = _isExit; }
void Room::setIndex(int _index) { index = _index; }
void Room::clearObjects() {
    isBlocked = false;
    objects.clear();
}
bool Room::getIsExit() { return isExit; }
bool Room::getIsBlocked() { return isBlocked; }
int Room::getIndex() { return index; }
Object_ptr Room::getObject(int key) {
    auto it = objects.find(key);
    if (it == objects.end())
        return nullptr;
    return it->second;
}
Objects_map Room::getObjects() { return objects; }
Room* Room::getRoom(DIRECTION dir) {
    auto it = neighborRooms.find(dir);
    return it == neighborRooms.end() ? nullptr : it->second;
}

void Room::drawNeighbors() {
    auto getname = [&](DIRECTION dir = DIRECTION::UNKNOWN) {
        auto r = dir == DIRECTION::UNKNOWN ? this : getRoom(dir);
        auto s = r ? '[' + r->name() + ']' : std::string(name_size+2,' ');
        return s;
    };
    std::cout << std::string(name_size+2,' ') << getname(DIRECTION::UP) << '\n'
            << getname(DIRECTION::LEFT) << getname()  << getname(DIRECTION::RIGHT) << '\n'
            << std::string(name_size+2,' ') << getname(DIRECTION::DOWN) << '\n'
            << std::endl;
}

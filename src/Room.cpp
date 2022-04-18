#include "Room.hpp"

Room::Room(bool _isExit, int _index, Objects_map _objects):
    isExit(_isExit), index(_index), objects(_objects) {}

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
Objects_map Room::getObjects() { return objects; }
Room* Room::getRoom(DIRECTION dir) {
    auto it = neighborRooms.find(dir);
    return it == neighborRooms.end() ? nullptr : it->second;
}

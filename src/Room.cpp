#include "Room.hpp"

Room::Room(bool _isExit, int _index, Objects_map _objects):
    isExit(_isExit), index(_index), objects(_objects) {}

void Room::pushObject(char key, Object_ptr object) {
    objects.emplace(key, object);
}

bool Room::popObject(char key) {
    auto it = objects.find(key);
    if (it == objects.end())
        return false;
    objects.erase(it);
    return true;
}

/* Set & Get function*/
void Room::setRoom(DIRECTION dir, Room* room) { neighborRooms[dir] = room; }
void Room::setIsExit(bool _isExit) { isExit = _isExit; }
void Room::setIndex(int _index) { index = _index; }
void Room::setObjects(Objects_map _objects) { objects = _objects; }
bool Room::getIsExit() { return isExit; }
int Room::getIndex() { return index; }
Objects_map Room::getObjects() { return objects; }
Room* Room::getRoom(DIRECTION dir) { return neighborRooms[dir]; }

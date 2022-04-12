#include "Room.hpp"

Room::Room(bool _isExit, int _index, vector<shared_ptr<Object>> _objects):
    isExit(_isExit), index(_index), objects(_objects) {}

bool Room::popObject(shared_ptr<Object> object) {
    for(auto it = objects.begin(); it != objects.end(); it++)
        if (*it == object) {
            objects.erase(it);
            return true;
        }
    return false;
}

/* Set & Get function*/
void Room::setRoom(DIRECTION dir, int room) { neighborRooms[static_cast<int>(dir)] = room; }
void Room::setIsExit(bool _isExit) { isExit = _isExit; }
void Room::setIndex(int _index) { index = _index; }
void Room::setObjects(vector<shared_ptr<Object>> _objects) { objects = _objects; }
bool Room::getIsExit() { return isExit; }
int Room::getIndex() { return index; }
vector<shared_ptr<Object>> Room::getObjects() { return objects; }
int Room::getRoom(DIRECTION dir) { return neighborRooms[static_cast<int>(dir)]; }

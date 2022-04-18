#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <random>
#include "helper.hpp"
using namespace std;

#include "Object.hpp"


class Room {
public:
    Room(bool = false, int = -1, Objects_map= {});
    void pushObject(int, Object_ptr);
    bool popObject(int); /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void setRoom(DIRECTION, Room*);
    void setIsExit(bool);
    void setIndex(int);
    void setObjects(Objects_map);
    bool getIsExit();
    int getIndex();
    Objects_map getObjects();
    Room* getRoom(DIRECTION);

private:
    bool isExit;
    int index;
    map<DIRECTION,Room*> neighborRooms;
    Objects_map objects;/*contain 1 or multiple objects, including monster, npc, etc*/
};

#endif // ROOM_H_INCLUDED

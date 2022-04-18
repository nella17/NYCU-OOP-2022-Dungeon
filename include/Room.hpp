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

#define LINK_ROOM(r1, d1, r2, d2) \
    (r1)->setRoom(d2, r2); \
    (r2)->setRoom(d1, r1);

class Room {
public:
    Room(bool = false, int = -1, Objects_map= {});
    void pushObject(int, Object_ptr);
    bool popObject(int); /*pop out the specific object, used when the interaction is done*/
    void drawNeighbors();

    /* Set & Get function*/
    void setRoom(DIRECTION, Room*);
    void setIsExit(bool);
    void setIndex(int);
    void clearObjects();
    bool getIsExit();
    bool getIsBlocked();
    int getIndex();
    Objects_map getObjects();
    Room* getRoom(DIRECTION);

private:
    void switchState(bool, Object_ptr);

    bool isBlocked, isExit;
    int index;
    map<DIRECTION,Room*> neighborRooms;
    Objects_map objects;/*contain 1 or multiple objects, including monster, npc, etc*/
};

#endif // ROOM_H_INCLUDED

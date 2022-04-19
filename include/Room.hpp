#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <string>
#include <map>
#include "helper.hpp"
#include "Object.hpp"

#define LINK_ROOM(r1, d1, r2, d2) \
    (r1)->setRoom(d2, r2); \
    (r2)->setRoom(d1, r1);

class Room {
public:
    Room(bool = false, int = -1, Objects_map= {});
    void pushObject(int, Object_ptr);
    bool popObject(int); /*pop out the specific object, used when the interaction is done*/
    std::string name();
    void drawNeighbors();

    /* Set & Get function*/
    void setRoom(DIRECTION, Room*);
    void setIsExit(bool);
    void setIndex(int);
    void clearObjects();
    bool getIsExit();
    bool getIsBlocked();
    int getIndex();
    Object_ptr getObject(int);
    Objects_map getObjects();
    Room* getRoom(DIRECTION);

private:
    void switchState(bool, Object_ptr);

    bool isBlocked, isExit;
    int index;
    std::map<DIRECTION,Room*> neighborRooms;
    Objects_map objects;/*contain 1 or multiple objects, including monster, npc, etc*/
};

#endif // ROOM_H_INCLUDED

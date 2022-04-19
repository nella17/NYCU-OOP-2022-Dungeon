#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <string>
#include <map>
#include "helper.hpp"
#include "Object.hpp"

class Room {
public:
    Room(bool = false, int = -1, Objects_map= {});
    std::string name();
    void drawNeighbors(Room* = nullptr);

    bool triggerObjectEvent(int, Object_ptr);
    void pushObject(int, Object_ptr);
    bool popObject(int); /*pop out the specific object, used when the interaction is done*/

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
    Room* getRoom(DIRECTION, Room* previous = nullptr);

private:
    void switchState(bool, Object_ptr);

    bool isBlocked, isExit;
    int index;
    std::map<DIRECTION,Room*> neighborRooms;
    Objects_map objects;/*contain 1 or multiple objects, including monster, npc, etc*/
};

inline void LINK_ROOM(Room* r1, DIRECTION d1, Room* r2, DIRECTION d2) {
    r1->setRoom(d2, r2);
    r2->setRoom(d1, r1);
}

#endif // ROOM_H_INCLUDED

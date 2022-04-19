#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <string>
#include <map>
#include "helper.hpp"
#include "Object.hpp"

class Room {
public:
    Room(bool = false, int = -1, ObjectsMap= {});
    std::string name();
    void draw_neighbors(Room* = nullptr);
    void print_menu();

    bool trigger_object_event(int, ObjectPtr);
    void push_object(int, ObjectPtr);
    bool pop_object(int); /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void set_room(DIRECTION, Room*);
    void set_isExit(bool);
    void set_index(int);
    void clear_objects();
    bool get_isExit();
    bool get_isBlocked();
    int get_index();
    ObjectPtr get_object(int);
    ObjectsMap get_objects();
    Room* get_neighbor(DIRECTION, Room* previous = nullptr);

private:
    void switch_states(bool, ObjectPtr);
    ObjectPtr check_object(ObjectPtr);

    bool isBlocked, isLocked, isExit;
    int index;
    std::map<DIRECTION,Room*> neighbors;
    ObjectsMap objects;/*contain 1 or multiple objects, including monster, npc, etc*/
};

inline void LINK_ROOM(Room* r1, DIRECTION d1, Room* r2, DIRECTION d2) {
    r1->set_room(d2, r2);
    r2->set_room(d1, r1);
}

#endif // ROOM_H_INCLUDED

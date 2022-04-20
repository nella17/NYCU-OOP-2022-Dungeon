#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <string>
#include <map>
#include <memory>
#include "helper.hpp"
#include "Object.hpp"
class Record;

class Room;
using RoomPtr = std::shared_ptr<Room>;

class Room: public Object {
    friend class Record;
public:
    static std::string name(int, bool);

    Room(int = -1, bool = false, ObjectsMap= {});
    void draw_neighbors(RoomPtr = nullptr);
    void print_menu();

    bool trigger_event(int, ObjectPtr);
    void push_object(int, ObjectPtr);
    bool pop_object(int); /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void set_room(DIRECTION, RoomPtr);
    void set_isExit(bool);
    void set_index(int);
    void clear_objects();
    bool get_isExit() const;
    bool get_isBlocked() const;
    int get_index() const;
    ObjectPtr get_object(int) const;
    ObjectsMap get_objects() const;
    RoomPtr get_neighbor(DIRECTION, RoomPtr previous = nullptr);

private:
    void switch_states(bool, ObjectPtr);
    ObjectPtr check_object(ObjectPtr) const;

    bool isBlocked, isLocked, isExit;
    int index;
    std::map<DIRECTION,RoomPtr> neighbors;
    ObjectsMap objects;/*contain 1 or multiple objects, including monster, npc, etc*/
};

inline void LINK_ROOM(RoomPtr r1, DIRECTION d1, RoomPtr r2, DIRECTION d2) {
    r1->set_room(d2, r2);
    r2->set_room(d1, r1);
}

#endif // ROOM_H_INCLUDED

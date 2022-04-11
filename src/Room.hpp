#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "Object.hpp"

using namespace std;

enum DIRECTION {
    LEFT = 0,
    RIGHT = 1,
    UP = 2,
    DOWN = 3,
};

class Room {
private:
    bool isExit;
    int index;
    array<int,4> neighborRooms;
    vector<shared_ptr<Object>> objects; /*contain 1 or multiple objects, including monster, npc, etc*/

public:
    Room(bool, int, vector<shared_ptr<Object>>);
    bool popObject(shared_ptr<Object>); /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void setRoom(DIRECTION, int);
    void setIsExit(bool);
    void setIndex(int);
    void setObjects(vector<shared_ptr<Object>>);
    bool getIsExit();
    int getIndex();
    vector<shared_ptr<Object>> getObjects();
    int getRoom(DIRECTION);
};

#endif // ROOM_H_INCLUDED

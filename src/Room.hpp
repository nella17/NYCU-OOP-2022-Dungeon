#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "Object.hpp"

using namespace std;

enum class DIRECTION {
    LEFT, RIGHT, UP, DOWN,
};

class Room {
private:
    bool isExit;
    int index;
    map<DIRECTION, int> neighborRooms;
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

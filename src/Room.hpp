#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.hpp"

using namespace std;

class Room {
private:
    int upRoom, downRoom, leftRoom, rightRoom;
    bool isExit;
    int index;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/

public:
    Room();
    Room(bool, int, vector<Object*>);
    bool popObject(Object*); /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void setUpRoom(int);
    void setDownRoom(int);
    void setLeftRoom(int);
    void setRightRoom(int);
    void setIsExit(bool);
    void setIndex(int);
    void setObjects(vector<Object*>);
    bool getIsExit();
    int getIndex();
    vector<Object*> getObjects();
    int getUpRoom();
    int getDownRoom();
    int getLeftRoom();
    int getRightRoom();
};

#endif // ROOM_H_INCLUDED

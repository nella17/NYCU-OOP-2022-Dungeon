#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <map>
#include <memory>
using namespace std;

#include "GameCharacter.hpp"
#include "Room.hpp"
#include "Item.hpp"

class Player: public GameCharacter {
private:
    Room *currentRoom, *previousRoom;
    Items_set inventory;

public:
    Player(string, int, int, int);
    void addItem(Item_ptr);
    void increaseStates(int, int, int);
    void changeRoom(Room*);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(const Object_ptr);

    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(Items_set);
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    Items_set getInventory();
};

#endif // PLAYER_H_INCLUDED

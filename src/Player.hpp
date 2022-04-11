#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "GameCharacter.hpp"
#include "Room.hpp"
#include "Item.hpp"

using namespace std;

class Item;

class Player: public GameCharacter {
private:
    int currentRoom, previousRoom;
    vector<Item> inventory;

public:
    Player();
    Player(string, int, int, int);
    void addItem(Item);
    void increaseStates(int, int, int);
    void changeRoom(int);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(const shared_ptr<Object>);

    /* Set & Get function*/
    void setCurrentRoom(int);
    void setPreviousRoom(int);
    void setInventory(vector<Item>);
    int getCurrentRoom();
    int getPreviousRoom();
    vector<Item> getInventory();
};

#endif // PLAYER_H_INCLUDED

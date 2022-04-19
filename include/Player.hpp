#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include "GameCharacter.hpp"
#include "Room.hpp"
#include "Item.hpp"

class Player: public GameCharacter {
public:
    Player(std::string, int, int, int);
    void addItem(Item_ptr);
    void increaseStates(int, int, int);
    void changeRoom(Room*);

    void printStatus();
    void printMenu();
    bool handleMenu(int);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool triggerEvent(Object_ptr);

    /* Set & Get function*/
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setInventory(Items_set);
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    Items_set getInventory();

private:
    Room *currentRoom, *previousRoom;
    Items_set inventory;
};

#endif // PLAYER_H_INCLUDED

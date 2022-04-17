#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <exception>
#include "Player.hpp"
#include "Monster.hpp"
#include "NPC.hpp"
#include "Room.hpp"
#include "Record.hpp"
#include "helper.hpp"

using namespace std;

class Dungeon {
private:
    shared_ptr<Player> player;
    vector<Room> rooms;

public:
    Dungeon();

    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which include several different rooms */
    void createMap();

    /* Deal with player's moveing action */
    void handleMovement();

    /* Deal with player's iteraction with objects in that room */
    void handleEvent(shared_ptr<Object>);

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame();

    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    void chooseAction(const vector<shared_ptr<Object>>&);

    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool checkGameLogic();

    /* Deal with the whole game process */
    void runDungeon();
};

#endif // DUNGEON_H_INCLUDED

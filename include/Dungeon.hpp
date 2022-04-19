#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <vector>
#include <memory>
#include "Object.hpp"
#include "Player.hpp"
#include "Room.hpp"

class Dungeon {
public:
    Dungeon();

    /* Create a new player, and give him/her basic status */
    void createPlayer();

    /* Create a map, which include several different rooms */
    void createMap();

    void drawScreen();

    /* Deal with player's moveing action */
    void handleMenu();

    /* Deal with player's iteraction with objects in that room */
    void handleEvent(Object_ptr);

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame();

    /* Deal with the player's action     */
    /* including showing the action list */
    /* that player can do at that room   */
    /* and dealing with player's input   */
    void chooseAction(const Objects_map&);

    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool checkGameLogic();

    /* Deal with the whole game process */
    void runDungeon();

private:
    std::shared_ptr<Player> player;
    std::vector<Room> rooms;
};

#endif // DUNGEON_H_INCLUDED

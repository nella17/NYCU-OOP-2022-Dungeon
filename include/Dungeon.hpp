#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <vector>
#include <memory>
#include "Object.hpp"
#include "Player.hpp"
#include "Room.hpp"

class Dungeon {
    friend class Record;
public:
    Dungeon();

    /* Create a new player, and give him/her basic status */
    void create_player();
    /* Create a map, which include several different rooms */
    void create_map();

    void create_game();
    void load_game();
    void save_game();

    void draw_screen();

    /* Deal with player's action */
    void handle_menu();

    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void start_game();

    /* Check whether the game should end or not */
    /* Including player victory, or he/she dead */
    bool check_game_logic();

    /* Deal with the whole game process */
    void run();

private:
    bool quit;
    PlayerPtr player;
    std::vector<RoomPtr> rooms;
};

#endif // DUNGEON_H_INCLUDED

#include "Dungeon.hpp"

#include <iostream>
#include <string>
#include <exception>
#include "helper.hpp"

#include "Room.hpp"
// GameCharacter
#include "Player.hpp"
#include "Monster.hpp"
#include "NPC.hpp"
// Item
#include "Item.hpp"
#include "Equip.hpp"
#include "Potion.hpp"
#include "Key.hpp"
// Record
#include "Record.hpp"

Dungeon::Dungeon(): quit(false), player(nullptr), rooms() {}

void Dungeon::create_player() {
    std::string name;
    std::cout << "Please enter your name: ";
    std::cin >> name;
    std::cout << "Hello " << name << "!" << std::endl;
    player = std::make_shared<Player>(name, 100, 10, 5);
}

void Dungeon::create_map() {
    std::cout << "Generating map..." << std::endl;
    rooms.clear();

    /*
           [2] - [3]
            |     🔒
     [0] - [1]   [8] - [exit]
            |
           [4] - [6] - [7]
            |
           [5]
    */
    int sz = 9;
    rooms.resize(sz);
    for(int i = 0; i < sz; i++)
        rooms[i].set_index(i);
    rooms[8].set_isExit(true);
    LINK_ROOM(&rooms[0], DIRECTION::LEFT, &rooms[1], DIRECTION::RIGHT);
    LINK_ROOM(&rooms[1], DIRECTION::DOWN, &rooms[2], DIRECTION::UP   );
    LINK_ROOM(&rooms[1], DIRECTION::UP  , &rooms[4], DIRECTION::DOWN );
    LINK_ROOM(&rooms[2], DIRECTION::LEFT, &rooms[3], DIRECTION::RIGHT);
    LINK_ROOM(&rooms[4], DIRECTION::UP  , &rooms[5], DIRECTION::DOWN );
    LINK_ROOM(&rooms[4], DIRECTION::LEFT, &rooms[6], DIRECTION::RIGHT);
    LINK_ROOM(&rooms[6], DIRECTION::LEFT, &rooms[7], DIRECTION::RIGHT);
    LINK_ROOM(&rooms[3], DIRECTION::UP  , &rooms[8], DIRECTION::DOWN );

    // TODO: add items
    rooms[6].push_object('M', std::make_shared<Monster>(std::string("Monster"), 10, 5, 2));
    auto [key, lock] = Key::generate_key_pair();
    rooms[7].push_object('K', key);
    rooms[8].push_object('L', lock);

    sleep(1);
    std::cout << "Map generated!" << std::endl;
}

void Dungeon::draw_screen() {
    clearScreen();

    std::cout << "Player's Status:\n";
    player->print_status();
    std::cout << '\n';

    std::cout << "Map:\n";
    player->get_currentRoom()->draw_neighbors(player->get_previousRoom());
    std::cout << '\n';

    std::cout << "Actions:\n";
    std::cout << "[W][A][S][D] Movement\n";
    player->get_currentRoom()->print_menu();
    std::cout << "[Q] Quit\n";

    std::cout << std::endl;
}

void Dungeon::handle_menu() {
    draw_screen();
    int key = read_char_no_buffer_echo();
    if (key == 'Q') {
        quit = true;
        return;
    }
    player->handle_key(key);
}

void Dungeon::start_game() {
    clearScreen();
    create_player();
    create_map();
    player->changeRoom(&rooms[0]);
}

bool Dungeon::check_game_logic() {
    if (player != nullptr)
        if (player->check_is_dead() || player->get_currentRoom()->get_isExit())
            return true;
    return false;
}

void Dungeon::run() {
    start_game();

    while (!quit && !check_game_logic())
        handle_menu();

    if (quit)
        std::cout << "Goodbye!" << std::endl;
    else if (player->check_is_dead())
        std::cout << "You died :(" << std::endl;
    else if (player->get_currentRoom()->get_isExit())
        std::cout << "You won!" << std::endl;
    else
        assert(0 && "unknown error");
}

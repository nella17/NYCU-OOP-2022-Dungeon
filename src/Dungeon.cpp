#include "Dungeon.hpp"

#include <iostream>
#include <string>
#include <exception>
#include "helper.hpp"

// GameCharacter
#include "Monster.hpp"
#include "NPC.hpp"
// Item
#include "Equipment.hpp"
#include "Potion.hpp"
#include "Key.hpp"
// Record
#include "Record.hpp"

Dungeon::Dungeon(): player(nullptr), rooms() {}

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
            |
     [0] - [1]
            |
           [4] - [6] - [7] - [exit]
            |
           [5]
    */
    int sz = 8;
    rooms.resize(sz);
    for(int i = 0; i < sz; i++)
        rooms[i].set_index(i);
    rooms[7].set_isExit(true);
    LINK_ROOM(&rooms[0], DIRECTION::LEFT, &rooms[1], DIRECTION::RIGHT);
    LINK_ROOM(&rooms[1], DIRECTION::DOWN, &rooms[2], DIRECTION::UP   );
    LINK_ROOM(&rooms[1], DIRECTION::UP  , &rooms[4], DIRECTION::DOWN );
    LINK_ROOM(&rooms[2], DIRECTION::LEFT, &rooms[3], DIRECTION::RIGHT);
    LINK_ROOM(&rooms[4], DIRECTION::UP  , &rooms[5], DIRECTION::DOWN );
    LINK_ROOM(&rooms[4], DIRECTION::LEFT, &rooms[6], DIRECTION::RIGHT);
    LINK_ROOM(&rooms[6], DIRECTION::LEFT, &rooms[7], DIRECTION::RIGHT);

    // TODO: add items

    sleep(1);
    std::cout << "Map generated!" << std::endl;
}

void Dungeon::draw_screen() {
    clearScreen();
    player->print_status();
    player->get_currentRoom()->draw_neighbors();
}

// TODO
void Dungeon::handle_menu() {
    player->print_menu();
    set_no_buffer_mode(); set_no_echo_mode();
    int key = read_char();
    set_buffer_mode(); set_echo_mode();
    player->handle_menu(key);
}

// TODO
void Dungeon::handle_event(ObjectPtr) {
}

void Dungeon::start_game() {
    clearScreen();
    create_player();
    create_map();
    player->changeRoom(&rooms[0]);
}

// TODO
void Dungeon::choose_action(const ObjectsMap&) {
}

// TODO
bool Dungeon::check_game_logic() {
    if (player && (player->check_is_dead() || player->get_currentRoom()->get_isExit()))
        return true;
    return false;
}

// TODO
void Dungeon::run() {
    start_game();

    while (!check_game_logic()) {
        draw_screen();
        handle_menu();
    }
}

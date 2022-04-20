#include "Dungeon.hpp"

#include <iostream>
#include <string>
#include <exception>
#include <memory>
#include "helper.hpp"
#include "ASCII_Art.hpp"

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

Dungeon::Dungeon(): quit(false), msg(""), player(nullptr), rooms() {}

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
           [2] 🔒[3]
            |     |
     [0] - [1]   [8] - [exit]
            |
           [4] - [6] - [7]
            |
           [5]
    */
    int sz = 10;
    rooms.resize(sz);
    for(int i = 0; i < sz; i++)
        rooms[i] = std::make_shared<Room>(i, i+1==sz);
    LINK_ROOM(rooms[0], DIRECTION::LEFT, rooms[1], DIRECTION::RIGHT);
    LINK_ROOM(rooms[1], DIRECTION::DOWN, rooms[2], DIRECTION::UP   );
    LINK_ROOM(rooms[1], DIRECTION::UP  , rooms[4], DIRECTION::DOWN );
    LINK_ROOM(rooms[2], DIRECTION::LEFT, rooms[3], DIRECTION::RIGHT);
    LINK_ROOM(rooms[4], DIRECTION::UP  , rooms[5], DIRECTION::DOWN );
    LINK_ROOM(rooms[4], DIRECTION::LEFT, rooms[6], DIRECTION::RIGHT);
    LINK_ROOM(rooms[6], DIRECTION::LEFT, rooms[7], DIRECTION::RIGHT);
    LINK_ROOM(rooms[3], DIRECTION::UP  , rooms[8], DIRECTION::DOWN );
    LINK_ROOM(rooms[8], DIRECTION::LEFT, rooms[9], DIRECTION::RIGHT);

    // TODO: add items
    rooms[6]->push_object('M', std::make_shared<Monster>(std::string("GPA"), 43, 20, 10));
    rooms[8]->push_object('M', std::make_shared<Monster>(std::string("Diploma"), 128, 30, 30));
    auto [key, lock] = Key::generate_key_pair();
    rooms[7]->push_object('K', key);
    rooms[3]->push_object('L', lock);

    sleep(1);
    std::cout << "Map generated!" << std::endl;
}

void Dungeon::draw_screen() {
    clearScreen();

    std::cout << "Player's Status:\n";
    player->print_status();
    std::cout << '\n';

    auto interact = player->get_interact();
    if (interact->get_type() == Object::Type::Room)
        std::cout << "Map:\n";
    else
        std::cout << enum_name(interact->get_type()) << "'s Status:\n";
    interact->print_status(player);
    std::cout << '\n';

    std::cout << "Actions:\n";
    player->print_menu();
    std::cout << "---- game menu ----\n"
              << "  [Q] Quit\n";

    if (!msg.empty()) {
        std::cout << '\n' << msg << '\n';
        msg = "";
    }

    std::cout << std::endl;
}

void Dungeon::handle_menu() {
    int key = read_char_no_buffer_echo();
    if (key == 'Q') {
        quit = true;
        return;
    }
    player->handle_key(key);
}

void Dungeon::start_game() {
    clearScreen();
    std::cout << welcome << '\n'
            << "Press any key to start..." << std::endl;
    read_char_no_buffer_echo();

    clearScreen();
    create_player();
    create_map();
    player->changeRoom(rooms[0]);
}

bool Dungeon::check_game_logic() {
    if (player != nullptr)
        if (player->check_is_dead() || player->get_currentRoom()->get_isExit())
            return true;
    return false;
}

void Dungeon::run() {
    start_game();

    while (!quit && !check_game_logic()) {
        draw_screen();
        try {
            handle_menu();
        } catch (std::runtime_error& e) {
            msg = e.what();
        }
    }

    if (quit)
        std::cout << goodbye << std::endl;
    else if (player->check_is_dead())
        std::cout << you_died << std::endl;
    else if (player->get_currentRoom()->get_isExit())
        std::cout << you_won << std::endl;
    else
        assert(0 && "unknown error");
}

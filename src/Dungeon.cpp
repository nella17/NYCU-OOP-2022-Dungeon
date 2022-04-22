#include "Dungeon.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
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
// helper
#include "MsgBox.hpp"
#include "Record.hpp"

Dungeon::Dungeon(): quit(false), player(nullptr), rooms() {}

void Dungeon::create_player() {
    std::string name;
    std::cout << "Please enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Hello " << name << "!" << std::endl;
    player = std::make_shared<Player>(name, 50, 10, 5);
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
    LINK_ROOM(rooms[0], Direction::LEFT, rooms[1], Direction::RIGHT);
    LINK_ROOM(rooms[1], Direction::DOWN, rooms[2], Direction::UP   );
    LINK_ROOM(rooms[1], Direction::UP  , rooms[4], Direction::DOWN );
    LINK_ROOM(rooms[2], Direction::LEFT, rooms[3], Direction::RIGHT);
    LINK_ROOM(rooms[4], Direction::UP  , rooms[5], Direction::DOWN );
    LINK_ROOM(rooms[4], Direction::LEFT, rooms[6], Direction::RIGHT);
    LINK_ROOM(rooms[6], Direction::LEFT, rooms[7], Direction::RIGHT);
    LINK_ROOM(rooms[3], Direction::UP  , rooms[8], Direction::DOWN );
    LINK_ROOM(rooms[8], Direction::LEFT, rooms[9], Direction::RIGHT);

    // Monster
    rooms[6]->push_object('M', std::make_shared<Monster>(std::string("GPA"), 43, 20, 5));
    rooms[8]->push_object('M', std::make_shared<Monster>(std::string("Diploma"), 128, 50, 50));

    // Key
    auto [key, lock] = Key::generate_key_pair();
    rooms[3]->push_object('L', lock);

    // NPC
    rooms[0]->push_object('N', std::make_shared<NPC>("Starter", "Hello, I am an NPC for starter\nHere are some gift for you.", ItemsSet{
        std::make_shared<Equip>("Cap", Equip::Type::Head, 1, 0, 1),
        std::make_shared<Equip>("Shirt", Equip::Type::Body, 1, 0, 1),
        std::make_shared<Equip>("Watch", Equip::Type::LeftHand, 1, 0, 1),
        std::make_shared<Equip>("Ring", Equip::Type::RightHand, 1, 0, 1),
        std::make_shared<Equip>("Shoes", Equip::Type::Feet, 1, 0, 1),
    }));

    rooms[7]->push_object('N', std::make_shared<NPC>("Medium", "Wow, you are a good player!\nHere are some gift for you.", ItemsSet{
        std::make_shared<Equip>("Helmet", Equip::Type::Head, 10, 0, 5),
        std::make_shared<Equip>("Armor", Equip::Type::Body, 10, 0, 5),
        std::make_shared<Equip>("Shield", Equip::Type::LeftHand, 5, 0, 20),
        std::make_shared<Equip>("Sword", Equip::Type::RightHand, 0, 20, 2),
        std::make_shared<Equip>("Boots", Equip::Type::Feet, 10, 5, 2),
        key,
    }));

    // Equip
    rooms[5]->push_object('G', std::make_shared<Equip>("Gloves", Equip::Type::LeftHand, 10, 0, 10));

    // Potion
    rooms[2]->push_object('P', std::make_shared<Potion>("Soup", Potion::Type::Heal, 30));
    rooms[6]->push_object('P', std::make_shared<Potion>("Toxicant", Potion::Type::Damage, 50));
    rooms[7]->push_object('P', std::make_shared<Potion>("Beer", Potion::Type::Weaken, 20));

    sleep(1);
    std::cout << "Map generated!" << std::endl;
}

void Dungeon::create_game() {
    std::cout << "Creating new game..." << std::endl;
    create_player();
    create_map();
    player->changeRoom(rooms[0]);
}

void Dungeon::load_game() {
    std::cout << "Loading game..." << std::endl;
    if (!Record::load(this))
        create_game();
}

void Dungeon::save_game() {
    std::cout << "Saving game..." << std::endl;
    Record::save(this);
    sleep(1);
    if (quit)
        std::cout << "Game saved!" << std::endl;
    else
        MsgBox::add("Game saved!");
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
    std::cout << "--------- Game Menu ---------\n"
              << "  [S] Save\n"
              << "  [Q] Quit\n";

    std::cout << MsgBox() << std::endl;
}

void Dungeon::handle_menu() {
    int key = read_char_no_buffer_echo();
    switch (key) {
        case 'S':
            save_game();
            break;
        case 'Q':
            quit = true;
            return;
        default:
            player->handle_key(key);
    }
}

void Dungeon::start_game() {
    clearScreen();
    std::cout << welcome << '\n'
            << "Press [L] to load game or [N] to start a new game." << std::endl;
    char c;
    do c = read_char_no_buffer_echo(); while (c != 'L' && c != 'N');

    clearScreen();
    if (c == 'L')
        load_game();
    else
        create_game();
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
            MsgBox::add(e.what());
        }
    }

    if (quit) {
        std::cout << "Do you want to save your game? Y/[N]" << std::endl;
        char c = read_char_no_buffer_echo();
        if (c == 'Y') save_game();
        std::cout << goodbye << std::endl;
    } else if (player->check_is_dead()) {
        std::cout << you_died << std::endl;
    } else if (player->get_currentRoom()->get_isExit()) {
        std::cout << you_won << std::endl;
     } else {
        assert(0 && "unknown error");
     }
}

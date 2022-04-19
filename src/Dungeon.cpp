#include "Dungeon.hpp"

#include <iostream>
#include <string>
#include <exception>
#include "helper.hpp"

#include "Monster.hpp"
#include "NPC.hpp"
#include "Record.hpp"

Dungeon::Dungeon(): player(nullptr), rooms() {}

void Dungeon::createPlayer() {
    std::string name;
    std::cout << "Please enter your name: ";
    std::cin >> name;
    std::cout << "Hello " << name << "!" << std::endl;
    player = std::make_shared<Player>(name, 100, 10, 5);
}

void Dungeon::createMap() {
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
        rooms[i].setIndex(i);
    rooms[7].setIsExit(true);
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

void Dungeon::drawScreen() {
    clearScreen();
    player->drawStatus();
    player->getCurrentRoom()->drawNeighbors();
}

// TODO
void Dungeon::handleMenu() {
    player->printMenu();
    set_no_buffer_mode(); set_no_echo_mode();
    int key = read_char();
    set_buffer_mode(); set_echo_mode();
    player->handleMenu(key);
}

// TODO
void Dungeon::handleEvent(Object_ptr object) {
}

void Dungeon::startGame() {
    clearScreen();
    createPlayer();
    createMap();
    player->changeRoom(&rooms[0]);
}

// TODO
void Dungeon::chooseAction(const Objects_map& actions) {
}

// TODO
bool Dungeon::checkGameLogic() {
    if (player && (player->checkIsDead() || player->getCurrentRoom()->getIsExit()))
        return true;
    return false;
}

// TODO
void Dungeon::runDungeon() {
    startGame();

    while (!checkGameLogic()) {
        drawScreen();
        handleMenu();
    }
}

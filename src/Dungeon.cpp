#include "Dungeon.hpp"

Dungeon::Dungeon(): player(nullptr), rooms() {}

void Dungeon::createPlayer() {
    string name;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Hello " << name << "!" << endl;
    player = make_shared<Player>(name, 100, 10, 5);
}

void Dungeon::createMap() {
    cout << "Generating map..." << endl;
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
    cout << "Map generated!" << endl;
}

void Dungeon::drawScreen() {
    clearScreen();
    player->drawStatus();
    player->getCurrentRoom()->drawNeighbors();
}

// TODO
void Dungeon::handleMovement() {
}

// TODO
void Dungeon::handleEvent(Object_ptr object) {
}

void Dungeon::startGame() {
    clearScreen();
    createPlayer();
    createMap();
}

// TODO
void Dungeon::chooseAction(const Objects_map& actions) {
}

// TODO
bool Dungeon::checkGameLogic() {
    return false;
}

// TODO
void Dungeon::runDungeon() {
    startGame();

    while (!checkGameLogic()) {
        drawScreen();
    }
}

#include "Dungeon.hpp"

Dungeon::Dungeon(): player(nullptr), rooms() {}

void Dungeon::createPlayer() {
    string name;
    cout << "Please enter your name: ";
    cin >> name;
    cout << "Hello " << name << "!" << endl;
    player = make_shared<Player>(name, 100, 10, 5);
}

// TODO
void Dungeon::createMap() {
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
    }
}

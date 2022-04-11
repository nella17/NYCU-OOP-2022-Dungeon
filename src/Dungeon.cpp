#include "Dungeon.hpp"

Dungeon::Dungeon(): player(nullptr), rooms() {}

void Dungeon::createPlayer() {
    string name;
    cout << "Please enter your name: " << endl;
    cin >> name;
    cout << name << endl;
    player = make_shared<Player>(name, 100, 10, 5);
}

// TODO
void Dungeon::createMap() {
}

// TODO
void Dungeon::handleMovement() {
}

// TODO
void Dungeon::handleEvent(shared_ptr<Object>) {
}

void Dungeon::startGame() {
    createPlayer();
    createMap();
}

// TODO
void Dungeon::chooseAction(const vector<shared_ptr<Object>>&) {
}

// TODO
bool Dungeon::checkGameLogic() {
    return true;
}

// TODO
void Dungeon::runDungeon() {
    startGame();
    while (!checkGameLogic()) {
    }
}

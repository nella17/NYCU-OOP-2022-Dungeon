#include "Record.hpp"

// TODO
void savePlayer(const shared_ptr<Player>, ofstream&) {}

// TODO
void loadPlayer(shared_ptr<Player>&, ifstream&) {}

// TODO
void saveRooms(const vector<Room>&, ofstream&) {}
// TODO
void loadRooms(vector<Room>&, ifstream&) {}

void Record::saveToFile(const shared_ptr<Player> player, const vector<Room>& rooms) {
    savePlayer(player, *make_shared<ofstream>("data/player.txt"));
    saveRooms(rooms, *make_shared<ofstream>("data/rooms.txt"));
}
void Record::loadFromFile(shared_ptr<Player>& player, vector<Room>& rooms) {
    loadPlayer(player, *make_shared<ifstream>("data/player.txt"));
    loadRooms(rooms, *make_shared<ifstream>("data/rooms.txt"));
}

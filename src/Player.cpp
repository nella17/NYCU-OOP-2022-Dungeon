#include "Player.hpp"

Player::Player(string _name, int _maxHealth, int _attack, int _defense):
        GameCharacter(_name, Object::Type::Player, _maxHealth, _attack, _defense) {}

// TODO
void Player::addItem(Item_ptr item) {
    inventory.emplace(item);
}

// TODO
void increaseStates(int, int, int) {}

void Player::changeRoom(Room* room) {
    previousRoom = currentRoom;
    currentRoom = room;
}

void Player::printMenu() {
    cout << "   [W]   " << endl
         << "[A]   [D]" << endl
         << "   [S]   " << endl;
    for(auto [key, object]: currentRoom->getObjects())
        cout << "[" << key << "] " << object->getName() << endl;
    cout << endl;
}

bool Player::handleMenu(int key) {
    if (is_dir_key(key)) {
        auto dir = key_to_dir(key);
        if (currentRoom->getRoom(dir) == nullptr) {
            return false;
        }
        changeRoom(currentRoom->getRoom(dir));
    } else {
        auto object = currentRoom->getObject(key);
        if (object == nullptr) {
            return false;
        }
        if (object->triggerEvent(shared_from_this()))
            assert(currentRoom->popObject(key));
    }
    return true;
}

// TODO
bool Player::triggerEvent(Object_ptr obj) {
    if (obj->getType() == Object::Type::Item) {
        shared_ptr<Item> item = dynamic_pointer_cast<Item>(obj);
        addItem(item);
        return true;
    }
    return false;
}

void Player::setCurrentRoom(Room* room) { currentRoom = room; }
void Player::setPreviousRoom(Room* room) { previousRoom = room; }
void Player::setInventory(Items_set items) { inventory = items; }
Room* Player::getCurrentRoom() { return currentRoom; }
Room* Player::getPreviousRoom() { return previousRoom; }
Items_set Player::getInventory() { return inventory; }

#include "Player.hpp"

#include <iostream>
#include <map>
#include <memory>

Player::Player(std::string _name, int _maxHealth, int _attack, int _defense):
        GameCharacter(_name, Object::Type::Player, _maxHealth, _attack, _defense) {}

// TODO
void Player::addItem(Item_ptr item) {
    inventory.emplace(item);
}

// TODO
void Player::increaseStates(int, int, int) {}

void Player::changeRoom(Room* room) {
    previousRoom = currentRoom;
    currentRoom = room;
}

void Player::printMenu() {
    std::cout << "   [W]   \n"
              << "[A]   [D]\n"
              << "   [S]   \n";
    for(auto [key, object]: currentRoom->getObjects())
        std::cout << "[" << key << "] " << object->getName() << '\n';
    std::cout << std::endl;
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
        auto item = std::dynamic_pointer_cast<Item>(obj);
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

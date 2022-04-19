#include "Player.hpp"

#include <iostream>
#include <map>
#include <memory>

Player::Player(std::string _name, int _maxHealth, int _attack, int _defense):
        GameCharacter(_name, Object::Type::Player, _maxHealth, _attack, _defense) {}

// TODO
void Player::add_item(ItemPtr item) {
    inventory.emplace(item);
}

// TODO
void Player::increase_status(int, int, int) {}

void Player::changeRoom(Room* room) {
    previousRoom = currentRoom;
    currentRoom = room;
}

void Player::print_status() {
    std::cout << "Player's Status\n"
              << "Name\t: " << get_name() << '\n'
              << "Health\t: " << get_currentHealth() << " / " << get_maxHealth() << '\n'
              << "Attack\t: " << get_attack() << '\n'
              << "Defense\t: " << get_defense() << '\n';
    if (!inventory.empty()) {
        std::cout << "Items\t:";
        for (auto& item: inventory)
            std::cout << " " << item->get_name();
        std::cout << '\n';
    }
    std::cout << std::endl;
    currentRoom->draw_neighbors(previousRoom);
}

bool Player::handle_menu(int key) {
    if (is_dir_key(key)) {
        auto dir = key_to_dir(key);
        auto room = currentRoom->get_neighbor(dir, previousRoom);
        if (room == nullptr)
            return false;
        changeRoom(room);
    } else {
        if (currentRoom->trigger_object_event(key, shared_from_this()))
            assert(currentRoom->pop_object(key) && "Object not found");
    }
    return true;
}

// TODO
bool Player::trigger_event(ObjectPtr obj) {
    if (obj->get_type() == Object::Type::Item) {
        auto item = std::dynamic_pointer_cast<Item>(obj);
        add_item(item);
        return true;
    }
    return false;
}

void Player::set_currentRoom(Room* room) { currentRoom = room; }
void Player::set_previousRoom(Room* room) { previousRoom = room; }
void Player::set_inventory(ItemsSet items) { inventory = items; }
Room* Player::get_currentRoom() const { return currentRoom; }
Room* Player::get_previousRoom() const { return previousRoom; }
ItemsSet Player::get_inventory() const { return inventory; }

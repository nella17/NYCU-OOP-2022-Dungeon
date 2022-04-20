#include "Player.hpp"

#include <iostream>
#include <map>
#include <memory>
#include <exception>
#include "helper.hpp"
#include "Room.hpp"

Player::Player(std::string _name, int _maxHealth, int _attack, int _defense):
        GameCharacter(_name, Object::Type::Player, _maxHealth, _attack, _defense) {}

// TODO
void Player::add_item(ItemPtr item) {
    inventory.emplace(item);
}

bool Player::equip_item(ItemPtr item) {
    if (inventory.find(item) == inventory.end())
        return false;
    if (item->get_type() != Object::Type::Equip)
        return false;
    auto equip = std::dynamic_pointer_cast<Equip>(item);
    auto it = equips.find(equip->get_equip_type());
    if (it != equips.end())
        inventory.emplace(it->second);
    inventory.erase(item);
    equips.emplace(equip->get_equip_type(), equip);
    return true;
}

// TODO
void Player::increase_status(int, int, int) {}

void Player::changeRoom(RoomPtr room) {
    previousRoom = currentRoom;
    currentRoom = room;
}

void Player::print_status() {
    GameCharacter::print_status();
    if (!equips.empty()) {
        std::cout << "  Equipments\t:\n";
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        for (auto [_type, equip] : equips) {
            std::cout << "    ";
            std::cout.width(20);
            std::cout << enum_name(equip->get_equip_type());
            std::cout.width(16);
            std::cout << equip->get_name() << ": " << *equip << '\n';
        }
    }
    if (!inventory.empty()) {
        std::cout << "  Inventory\t:\n";
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        for (auto& item: inventory) {
            std::cout << "    ";
            std::cout.width(20);
            std::cout << item->name_of_type();
            std::cout.width(16);
            std::cout << item->get_name()
                    << ": " << *item << '\n';
        }
    }
}

void Player::print_menu() {
    std::cout << "---- user menu ----\n"
              << "  [W][A][S][D] \tMovement\n";
    for(const auto& [key, menu] : menus)
        std::cout << "  [" << char(key) << "] " << menu.name << '\n';
    currentRoom->print_menu();
}

bool Player::handle_key(int key) {
    if (is_dir_key(key)) {
        auto dir = key_to_dir(key);
        auto room = currentRoom->get_neighbor(dir, previousRoom);
        if (room == nullptr)
            return false;
        changeRoom(room);
    } else if (menus.find(key) != menus.end()) {
        auto menu = menus.at(key);
        if (menu.func == nullptr)
            return false;
        return (this->*menu.func)();
    } else {
        if (currentRoom->trigger_event(key, shared_from_this()))
            assert(currentRoom->pop_object(key) && "Object not found");
    }
    return true;
}

// TODO
bool Player::trigger_event(int, ObjectPtr obj) {
    if (obj->get_type() == Object::Type::Item) {
        auto item = std::dynamic_pointer_cast<Item>(obj);
        add_item(item);
        return true;
    }
    return false;
}

void Player::set_currentRoom(RoomPtr room) { currentRoom = room; }
void Player::set_previousRoom(RoomPtr room) { previousRoom = room; }
void Player::set_inventory(ItemsSet items) { inventory = items; }
InteractablePtr Player::get_interact() const { return interact; }
RoomPtr Player::get_currentRoom() const { return currentRoom; }
RoomPtr Player::get_previousRoom() const { return previousRoom; }
ItemsSet Player::get_inventory() const { return inventory; }

// TODO
bool Player::handle_func() {
    std::cerr << "Player::handle_func() not implemented" << std::endl;
    return false;
}

    // Player::menus.emplace('E', Menu{std::string("Equip"), &Player::handle_func});
    // menus.emplace('P', Menu(std::string("Potion"), &Player::handle_func));
    // menus.emplace('I', Menu(std::string("Inventory"), &Player::handle_func));

const Player::MenuMap Player::menus{
    { 'E', Menu{std::string("Equip"), &Player::handle_func} },
    { 'I', Menu{std::string("Inventory"), &Player::handle_func} },
};

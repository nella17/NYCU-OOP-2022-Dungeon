#include "Player.hpp"

#include <iostream>
#include <iomanip>
#include <map>
#include <memory>
#include <exception>
#include "helper.hpp"
#include "Room.hpp"

Player::Player(std::string _name, int _maxHealth, int _attack, int _defense):
        GameCharacter(_name, Object::Type::Player, _maxHealth, _attack, _defense),
        inventory(std::make_shared<Inventory>("Inventory")) {}

void Player::add_item(ItemPtr item) {
    inventory->emplace(item);
}

bool Player::equip_item(ItemPtr item) {
    if (inventory->find(item) == inventory->end())
        return false;
    if (item->get_item_type() != Item::Type::Equip)
        return false;
    auto equip = std::dynamic_pointer_cast<Equip>(item);
    auto eq_type = equip->get_equip_type();
    auto it = equips.find(eq_type);
    if (it != equips.end()) {
        auto ptr = it->second;
        decrease_status(ptr->get_health(), ptr->get_attack(), ptr->get_defense());
        inventory->emplace(ptr);
    }
    equips[eq_type] = equip;
    increase_status(equip->get_health(), equip->get_attack(), equip->get_defense());
    inventory->erase(item);
    return true;
}

void Player::changeRoom(RoomPtr room) {
    previousRoom = currentRoom;
    currentRoom = room;
    interacts.clear();
}

void Player::print_status(InteractablePtr) {
    GameCharacter::print_status();

    if (!equips.empty()) {
        std::cout << "  Equipments\t:\n";
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        for(auto&& [_type, equip] : equips) {
            std::cout << "    "
                << std::setw(20) << enum_name(equip->get_equip_type())
                << std::setw(16) << equip->get_name()
                << ": " << *equip << '\n';
        }
    }

    if (!inventory->empty()) {
        std::cout << "  Inventory\t:\n";
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        for(auto&& item: *inventory) {
            std::cout << "    "
                << std::setw(20) << item->name_of_type()
                << std::setw(16) << item->get_name()
                    << ": " << *item << '\n';
        }
    }

    std::cout << " Current Status\t: " << *currentRoom;
    for(auto&& it: interacts)
        std::cout << " > " << *it;
    std::cout << '\n';
}

void Player::print_menu() {
    std::cout << "--------- User Menu ---------\n";
    for(const auto& [key, menu] : menus)
        if ((this->*menu.func)(false))
            std::cout << "  [" << char(key) << "] " << menu.name << '\n';
    get_interact()->print_menu();
}

bool Player::handle_key(int key, ObjectPtr) {
    bool run = false;
    if (menus.find(key) != menus.end()) {
        auto menu = menus.at(key);
        run = (this->*menu.func)(true);
    }
    if (!run) {
        try {
            if (get_interact()->handle_key(key, shared_from_this()))
                handle_leave(true);
        } catch (InteractablePtr obj) {
            add_interact(obj);
        } catch (RoomPtr room) {
            changeRoom(room);
        }
    }
    return false;
}

void Player::add_interact(InteractablePtr interact) { interacts.emplace_back(interact); }
InteractablePtr Player::get_interact() const { return interacts.empty() ? currentRoom : interacts.back(); }
RoomPtr Player::get_currentRoom() const { return currentRoom; }
RoomPtr Player::get_previousRoom() const { return previousRoom; }
InventoryPtr Player::get_inventory() const { return inventory; }

bool Player::handle_inventory(bool run) {
    bool available = get_interact() != inventory && !inventory->empty();
    if (!run || !available) return available;
    add_interact(std::dynamic_pointer_cast<Interactable>(inventory));
    return true;
}

bool Player::handle_leave(bool run) {
    bool available = !interacts.empty();
    if (!run || !available) return available;
    interacts.pop_back();
    return true;
}

const Player::MenuMap Player::menus{
    { 'I', Menu{std::string("Inventory"), &Player::handle_inventory} },
    { 'L', Menu{std::string("Leave"), &Player::handle_leave} },
};

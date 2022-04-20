#include "Player.hpp"

#include <iostream>
#include <iomanip>
#include <map>
#include <memory>
#include <exception>
#include "helper.hpp"
#include "Room.hpp"

Player::Player(std::string _name, int _maxHealth, int _attack, int _defense):
        GameCharacter(_name, Object::Type::Player, _maxHealth, _attack, _defense) {}

void Player::add_item(ItemPtr item) {
    inventory.emplace(item);
}

bool Player::equip_item(ItemPtr item) {
    if (inventory.find(item) == inventory.end())
        return false;
    if (item->get_item_type() != Item::Type::Equip)
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
    interacts.clear();
    interacts.emplace_back(room);
}

void Player::print_status(InteractablePtr) {
    GameCharacter::print_status();

    if (!equips.empty()) {
        std::cout << "  Equipments\t:\n";
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        for (auto [_type, equip] : equips) {
            std::cout << "    "
                << std::setw(20) << enum_name(equip->get_equip_type())
                << std::setw(16) << equip->get_name()
                << ": " << *equip << '\n';
        }
    }

    if (!inventory.empty()) {
        std::cout << "  Inventory\t:\n";
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        for (auto& item: inventory) {
            std::cout << "    "
                << std::setw(20) << item->name_of_type()
                << std::setw(16) << item->get_name()
                    << ": " << *item << '\n';
        }
    }

    std::cout << " Current Status\t: ";
    for(auto it = interacts.begin(); it != interacts.end(); it++) {
        if (it != interacts.begin())
            std::cout << " > ";
        std::cout << enum_name((*it)->get_type()) << '(' << (*it)->get_name() << ')';
    }
    std::cout << '\n';
}

void Player::print_menu() {
    std::cout << "---- user menu ----\n";
    for(const auto& [key, menu] : menus)
        if ((this->*menu.func)(false))
            std::cout << "  [" << char(key) << "] " << menu.name << '\n';
    get_interact()->print_menu();
}

bool Player::handle_key(int key, ObjectPtr) {
    if (menus.find(key) != menus.end()) {
        auto menu = menus.at(key);
        if (menu.func == nullptr)
            return false;
        return (this->*menu.func)(true);
    } else {
        try {
            if (get_interact()->handle_key(key, shared_from_this())) {
                if (get_interact()->get_type() == Object::Type::Room) {
                    assert(currentRoom->pop_object(key) && "Object not found");
                } else {
                    assert(currentRoom->pop_object(get_interact()) && "Object not found");
                    handle_leave(true);
                }
            }
        } catch (InteractablePtr obj) {
            interacts.emplace_back(obj);
        } catch (RoomPtr room) {
            changeRoom(room);
        }
    }
    return true;
}

// TODO
bool Player::trigger_event(ObjectPtr) {
    return false;
}

InteractablePtr Player::get_interact() const { return interacts.back(); }
RoomPtr Player::get_currentRoom() const { return currentRoom; }
RoomPtr Player::get_previousRoom() const { return previousRoom; }

bool Player::handle_leave(bool run) {
    bool available = interacts.size() > 1;
    if (!run || !available) return available;
    interacts.pop_back();
    return true;
}

const Player::MenuMap Player::menus{
    { 'L', Menu{std::string("Leave"), &Player::handle_leave} },
};

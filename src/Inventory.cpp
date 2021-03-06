#include "Inventory.hpp"

#include <iostream>
#include <iomanip>
#include "Player.hpp"

Inventory::Inventory(std::string _name, ItemsSet _items):
        Interactable(_name, Object::Type::Inventory), ItemsSet(_items) {}

void Inventory::print_status(InteractablePtr) {
    if (empty()) {
        std::cout << "  Inventory is empty.\n";
    } else {
        std::cout << "  Inventory\t:\n";
        std::cout.setf(std::ios::left, std::ios::adjustfield);
        for(auto&& item: *this) {
            std::cout << "    "
                << std::setw(20) << item->name_of_type()
                << std::setw(16) << item->get_name()
                    << ": " << *item << '\n';
        }
    }
}

void Inventory::print_menu() {
    if (empty()) return;
    std::cout.setf(std::ios::right, std::ios::adjustfield);
    std::cout << std::setfill('-') << std::setw(14-get_name().size()) << ' '
        << std::setfill(' ') << get_name() << " Menu ---------\n";
    char c = '0';
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    for(const auto& item : *this) {
        std::cout << "  [" << c++ << "] "
                << std::setw(20) << item->name_of_type()
                << item->get_name() << '\n';
    }
}

bool Inventory::handle_key(int key, ObjectPtr obj) {
    if (key == LEAVE_KEY && obj == nullptr)
        return false;

    auto player = std::dynamic_pointer_cast<Player>(obj);
    if (player == nullptr)
        return false;
    bool is_in_player = shared_from_this() == player->get_inventory();

    char c = '0';
    ItemPtr item = nullptr;
    for(auto&& it: *this)
        if (key == c++) {
            item = it;
            break;
        }
    if (item == nullptr)
        return false;

    if (!is_in_player) {
        player->add_item(item);
        erase(item);
    } else {
        if (item->trigger_event(player))
            erase(item);
    }
    return empty();
}

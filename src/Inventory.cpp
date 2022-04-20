#include "Inventory.hpp"

#include <iostream>
#include <iomanip>
#include "Player.hpp"

Inventory::Inventory(std::string _name, ItemsSet _items):
        Interactable(_name, Object::Type::Inventory), ItemsSet(_items) {}

void Inventory::print_status(InteractablePtr) {}

void Inventory::print_menu() {
    if (empty()) return;
    std::cout << "---- inventory menu ---------\n";
    char c = '0';
    std::cout.setf(std::ios::left, std::ios::adjustfield);
    for(const auto& item : *this) {
        std::cout << "  [" << c++ << "] "
                << std::setw(20) << item->name_of_type()
                << item->get_name() << '\n';
    }
}

bool Inventory::handle_key(int key, ObjectPtr obj) {
    auto player = std::dynamic_pointer_cast<Player>(obj);
    if (player == nullptr)
        return false;
    bool is_in_player = shared_from_this() == player->get_inventory();

    char c = '0';
    for(auto& item : *this)
        if (key == c++)
            {
                if (!is_in_player) {
                    player->add_item(item);
                    erase(item);
                    return empty();
                } else {
                    return item->trigger_event(player);
                }
            }

    return false;
}

bool Inventory::trigger_event(ObjectPtr) {
    return false;
}

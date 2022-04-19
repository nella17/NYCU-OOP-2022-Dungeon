#include "Item.hpp"

#include "Player.hpp"

Item::Item(std::string _name, Object::Type _type): Object(_name, _type) {}

bool Item::trigger_event(ObjectPtr obj) {
    if (obj->get_type() == Object::Type::Player) {
        auto player = std::dynamic_pointer_cast<Player>(obj);
        return player->trigger_event(shared_from_this());
    }
    return false;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    return item.show_info(os);
}

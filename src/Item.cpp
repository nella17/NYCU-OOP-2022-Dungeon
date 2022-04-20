#include "Item.hpp"

#include "Player.hpp"
#include "helper.hpp"

Item::Item(std::string _name, Object::Type _type): Object(_name, _type) {}

bool Item::trigger_event(int key, ObjectPtr obj) {
    if (obj->get_type() == Object::Type::Player) {
        auto player = std::dynamic_pointer_cast<Player>(obj);
        return player->trigger_event(key, shared_from_this());
    }
    return false;
}

std::string Item::name_of_type() const {
    return enum_name(get_type());
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    return item.show_info(os);
}

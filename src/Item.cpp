#include "Item.hpp"

#include "Player.hpp"
#include "helper.hpp"

Item::Item(std::string _name, Object::Type _type): Object(_name, _type) {}

bool Item::trigger_event(ObjectPtr obj) {
    if (obj->get_type() == Object::Type::Player) {
        auto player = std::dynamic_pointer_cast<Player>(obj);
        auto item = std::dynamic_pointer_cast<Item>(shared_from_this());
        player->add_item(item);
        return true;
    }
    return false;
}

std::string Item::name_of_type() const {
    return enum_name(get_type());
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    return item.show_info(os);
}

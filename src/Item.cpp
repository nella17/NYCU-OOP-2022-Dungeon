#include "Item.hpp"

#include "Player.hpp"
#include "helper.hpp"

Item::Item(std::string _name, Item::Type _type): Object(_name, Object::Type::Item), type(_type) {}

bool Item::trigger_event(ObjectPtr obj) {
    return false;
}

std::string Item::name_of_type() const {
    return enum_name(type);
}

Item::Type Item::get_item_type() const {
    return type;
}

std::ostream& operator<<(std::ostream& os, const Item& item) {
    return item.show_info(os);
}

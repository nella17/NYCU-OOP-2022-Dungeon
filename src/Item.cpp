#include "Item.hpp"

#include "Player.hpp"

Item::Item(std::string _name, Object::Type _type): Object(_name, _type) {}

bool Item::triggerEvent(Object_ptr obj) {
    if (obj->getType() == Object::Type::Player) {
        auto player = std::dynamic_pointer_cast<Player>(obj);
        return player->triggerEvent(shared_from_this());
    }
    return false;
}

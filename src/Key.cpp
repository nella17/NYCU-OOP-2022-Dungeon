#include "Key.hpp"

#include <iostream>
#include <string>
#include <stdexcept>
#include "helper.hpp"

#include "Player.hpp"

Key::Key(uint32_t _id, Item::Type _type, Object::Type _obj_type):
        Item(std::to_string(_id), _type, _obj_type), isLocked(true), id(_id) {}

bool Key::trigger_event(ObjectPtr obj) {
    auto player = std::dynamic_pointer_cast<Player>(obj);
    if (player == nullptr)
        return false;

    if (!isLocked)
        throw std::runtime_error(enum_name(get_item_type()) + " is already unlocked !?");

    switch (get_item_type()) {
        case Item::Type::Key:
            for(auto&& [k,o]: player->get_currentRoom()->get_objects())
                if (o->get_type() == Object::Type::Lock) {
                    auto lock = std::dynamic_pointer_cast<Key>(o);
                    auto key = std::dynamic_pointer_cast<Key>(shared_from_this());
                    if (lock->unlock(key)) {
                        player->get_currentRoom()->pop_object(k);
                        return false;
                    }
                }
            throw std::runtime_error("No lock found in this room !");
        case Item::Type::Lock:
            for(auto&& item: *player->get_inventory())
                if (item->get_item_type() == Item::Type::Key) {
                    auto key = std::dynamic_pointer_cast<Key>(item);
                    if (unlock(key)) {
                        return true;
                    }
                }
            throw std::runtime_error("You don't have the key to unlock this lock !");
        default:
            throw std::runtime_error("Unsupported key type: " + enum_name(get_item_type()));
    }
}

std::ostream& Key::show_info(std::ostream& os) const {
    return os
        << (isLocked ? "locked" : "unlocked");
}

bool Key::unlock(KeyPtr key) {
    if (key == shared_from_this())
        return false;
    if (get_item_type() != Item::Type::Lock)
        return false;
    if (key->get_item_type() != Item::Type::Key)
        return false;
    if (id != key->id)
        return false;
    assert(isLocked && key->isLocked && "Key is already unlocked");
    isLocked = key->isLocked = false;
    return true;
}

KeyPair Key::generate_key_pair() {
    uint32_t id = rng();
    auto key  = new Key(id, Item::Type::Key, Object::Type::Item);
    auto lock = new Key(id, Item::Type::Lock, Object::Type::Lock);
    return KeyPair(key, lock);
}

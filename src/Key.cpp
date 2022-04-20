#include "Key.hpp"

#include <iostream>
#include <string>
#include "helper.hpp"

Key::Key(uint32_t _id, Item::Type _type):
        Item(std::to_string(_id), _type), isLocked(true), id(_id) {}

std::ostream& Key::show_info(std::ostream& os) const {
    return os
        << (isLocked ? "locked" : "unlocked");
}

bool Key::unlock(KeyPtr key) {
    if (get_item_type() != Item::Type::Key || key->get_item_type() == Item::Type::Key)
        return false;
    if (id != key->id)
        return false;
    assert(isLocked && key->isLocked && "Key is already unlocked");
    isLocked = key->isLocked = false;
    return true;
}

KeyPair Key::generate_key_pair() {
    uint32_t id = rng();
    auto key  = new Key(id, Item::Type::Key);
    auto lock = new Key(id, Item::Type::Lock);
    return KeyPair(key, lock);
}

#include "Key.hpp"

#include <string>
#include "helper.hpp"

Key::Key(uint32_t _id, Object::Type _type):
        Item(std::to_string(_id), _type), isLocked(true), id(_id) {}

bool Key::unlock(KeyPtr key) {
    if (getType() != Object::Type::Key || key->getType() == Object::Type::Key)
        return false;
    if (id != key->id)
        return false;
    assert(isLocked && key->isLocked && "Key is already unlocked");
    isLocked = key->isLocked = false;
    return true;
}

KeyPair Key::generate_key_pair() {
    uint32_t id = rng();
    auto key  = new Key(id, Object::Type::Key);
    auto lock = new Key(id, Object::Type::Lock);
    return KeyPair(key, lock);
}

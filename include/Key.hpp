#ifndef KEY_H_INCLUDED
#define KEY_H_INCLUDED

#include <string>
#include <memory>
#include <utility>
#include "Item.hpp"

class Key;
using KeyPtr = std::shared_ptr<Key>;
using KeyPair = std::pair<KeyPtr, KeyPtr>;

class Key: public Item {
public:
    static KeyPair generate_key_pair();
    bool unlock(KeyPtr key);

private:
    bool isLocked;
    const uint32_t id;
    Key(uint32_t, Object::Type);
};

#endif // KEY_H_INCLUDED
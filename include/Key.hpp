#ifndef KEY_H_INCLUDED
#define KEY_H_INCLUDED

#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include "Item.hpp"

class Key;
using KeyPtr = std::shared_ptr<Key>;
using KeyPair = std::pair<KeyPtr, KeyPtr>;

class Key: public Item {
    friend class Record;
public:
    static KeyPair generate_key_pair();
    bool unlock(KeyPtr key);

    bool trigger_event(ObjectPtr);
    std::ostream& show_info(std::ostream&) const;

private:
    bool isLocked;
    const uint32_t id;
    Key(uint32_t, Item::Type, Object::Type);
};

#endif // KEY_H_INCLUDED

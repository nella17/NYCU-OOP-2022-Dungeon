#include "Item.hpp"

Item::Item(string _name, int _health, int _attack, int _defense):
        Object(_name, "Item"), health(_health), attack(_attack), defense(_defense) {}

bool Item::triggerEvent(Object_ptr obj) {
    if (obj->getTag() == "Player") {
        shared_ptr<Player> player = dynamic_pointer_cast<Player>(obj);
        return player->triggerEvent(shared_from_this());
    }
    return false;
}

int Item::getHealth() { return health; }
int Item::getAttack() { return attack; }
int Item::getDefense() { return defense; }
void Item::setHealth(int _health) { health = _health; }
void Item::setAttack(int _attack) { attack = _attack; }
void Item::setDefense(int _defense) { defense = _defense; }

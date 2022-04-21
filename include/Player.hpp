#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "GameCharacter.hpp"
#include "Room.hpp"
#include "Equip.hpp"
#include "Inventory.hpp"
class Record;

class Player;
using PlayerPtr = std::shared_ptr<Player>;

class Player: public GameCharacter {
    friend class Record;
public:
    Player(std::string, int, int, int);
    void add_item(ItemPtr);
    bool equip_item(ItemPtr);
    void changeRoom(RoomPtr);

    void print_status(InteractablePtr = nullptr);
    void print_menu();
    bool handle_key(int, ObjectPtr = nullptr);

    /* Set & Get function*/
    void add_interact(InteractablePtr);
    InteractablePtr get_interact() const;
    RoomPtr get_currentRoom() const;
    RoomPtr get_previousRoom() const;
    InventoryPtr get_inventory() const;

private:
    std::vector<InteractablePtr> interacts;
    RoomPtr currentRoom, previousRoom;
    InventoryPtr inventory;
    std::map<Equip::Type, std::shared_ptr<Equip>> equips;

    bool handle_inventory(bool);
    bool handle_leave(bool);

    using menu_func = bool (Player::*)(bool);
    struct Menu {
        std::string name;
        menu_func func;
    };
    using MenuMap = std::map<int, Menu>;
    const static MenuMap menus;
};

#endif // PLAYER_H_INCLUDED

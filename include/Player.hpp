#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
#include <vector>
#include <map>
#include <memory>
#include "GameCharacter.hpp"
#include "Room.hpp"
#include "Item.hpp"
#include "Equip.hpp"
class Record;

class Player: public GameCharacter {
    friend class Record;
public:
    Player(std::string, int, int, int);
    void add_item(ItemPtr);
    bool equip_item(ItemPtr);
    void increase_status(int, int, int);
    void changeRoom(RoomPtr);

    void print_status(InteractablePtr = nullptr);
    void print_menu();
    bool handle_key(int, ObjectPtr = nullptr);
    bool trigger_event(ObjectPtr);

    /* Set & Get function*/
    InteractablePtr get_interact() const;
    RoomPtr get_currentRoom() const;
    RoomPtr get_previousRoom() const;
    ItemsSet get_inventory() const;

private:
    std::vector<InteractablePtr> interacts;
    RoomPtr currentRoom, previousRoom;
    ItemsSet inventory;
    std::map<Equip::Type, std::shared_ptr<Equip>> equips;

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

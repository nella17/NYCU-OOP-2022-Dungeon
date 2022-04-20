#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <string>
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
    void changeRoom(Room*);

    void print_status();
    void print_menu();
    bool handle_key(int);

    /* Virtual function that you need to complete   */
    /* In Player, this function should show the     */
    /* status of player.                            */
    bool trigger_event(ObjectPtr);

    /* Set & Get function*/
    void set_currentRoom(Room*);
    void set_previousRoom(Room*);
    void set_inventory(ItemsSet);
    Room* get_currentRoom() const;
    Room* get_previousRoom() const;
    ItemsSet get_inventory() const;

private:
    Room *currentRoom, *previousRoom;
    ItemsSet inventory;
    std::map<Equip::Type, std::shared_ptr<Equip>> equips;

    bool handle_func();

    using menu_func = bool (Player::*)(void);
    struct Menu {
        std::string name;
        menu_func func;
    };
    using MenuMap = std::map<int, Menu>;
    const static MenuMap menus;
};

#endif // PLAYER_H_INCLUDED

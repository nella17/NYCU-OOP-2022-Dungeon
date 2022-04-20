#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <string>
#include "GameCharacter.hpp"
#include "Item.hpp"
#include "Object.hpp"
class Record;

class NPC: public GameCharacter {
    friend class Record;
public:
    NPC(std::string, std::string, ItemsSet = {});
    void list_commodity(); /*print all the Item in this NPC*/

    void print_status(InteractablePtr = nullptr);
    void print_menu();
    bool handle_key(int, ObjectPtr);

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool trigger_event(ObjectPtr);

    /* Set & Get function*/
    std::string get_script() const;
    ItemsSet get_commodity() const;

private:
    std::string script;
    ItemsSet commodity;
};

#endif // NPC_H_INCLUDED

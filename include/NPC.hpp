#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <string>
#include "GameCharacter.hpp"
#include "Item.hpp"
#include "Object.hpp"

class NPC: public GameCharacter {
public:
    NPC(std::string, std::string, ItemsSet = {});
    void list_commodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool trigger_event(ObjectPtr);

    /* Set & Get function*/
    void set_script(std::string);
    void set_commodity(ItemsSet);
    std::string get_script() const;
    ItemsSet get_commodity() const;

private:
    std::string script;
    ItemsSet commodity;
};

#endif // NPC_H_INCLUDED

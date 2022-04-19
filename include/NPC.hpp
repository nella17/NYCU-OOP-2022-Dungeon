#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <string>
#include "GameCharacter.hpp"
#include "Item.hpp"
#include "Object.hpp"

class NPC: public GameCharacter {
public:
    NPC(std::string, std::string, Items_set = {});
    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool triggerEvent(Object_ptr);

    /* Set & Get function*/
    void setScript(std::string);
    void setCommodity(Items_set);
    std::string getScript();
    Items_set getCommodity();

private:
    std::string script;
    Items_set commodity;
};

#endif // NPC_H_INCLUDED

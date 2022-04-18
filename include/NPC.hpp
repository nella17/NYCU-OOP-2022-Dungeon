#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

#include "GameCharacter.hpp"
#include "Player.hpp"
#include "Item.hpp"

class NPC: public GameCharacter {
private:
    string script;
    Items_set commodity;

public:
    NPC(string, string, Items_set = {});
    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool triggerEvent(Object_ptr);

    /* Set & Get function*/
    void setScript(string);
    void setCommodity(Items_set);
    string getScript();
    Items_set getCommodity();
};

#endif // NPC_H_INCLUDED

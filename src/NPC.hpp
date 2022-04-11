#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "GameCharacter.hpp"
#include "Player.hpp"
#include "Item.hpp"

using namespace std;

class NPC: public GameCharacter {
private:
    string script;
    vector<Item> commodity;

public:
    NPC(string, string, vector<Item>);
    void listCommodity(); /*print all the Item in this NPC*/

    /* Virtual function that you need to complete   */
    /* In NPC, this function should deal with the   */
    /* transaction in easy implementation           */
    bool triggerEvent(const shared_ptr<Object>);

    /* Set & Get function*/
    void setScript(string);
    void setCommodity(vector<Item>);
    string getScript();
    vector<Item> getCommodity();
};

#endif // NPC_H_INCLUDED

#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <memory>
#include "helper.hpp"
using namespace std;

#include "Item.hpp"
#include "Monster.hpp"
#include "NPC.hpp"
#include "Player.hpp"

/* This is the record system. Get the information of the  */
/* player and rooms then save them to (a) file(s). Notice */
/* that using pass by reference can prevent sending the   */
/* whole vector to the function.                          */

namespace Record {
    void saveToFile(const shared_ptr<Player>, const vector<Room>&);
    void loadFromFile(shared_ptr<Player>&, vector<Room>&);
};

#endif // RECORD_H_INCLUDED

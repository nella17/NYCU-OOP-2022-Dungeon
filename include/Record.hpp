#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <vector>
#include "Player.hpp"
#include "Room.hpp"

/* This is the record system. Get the information of the  */
/* player and rooms then save them to (a) file(s). Notice */
/* that using pass by reference can prevent sending the   */
/* whole vector to the function.                          */

namespace Record {
    void saveToFile(const std::shared_ptr<Player>, const std::vector<Room>&);
    void loadFromFile(std::shared_ptr<Player>&, std::vector<Room>&);
};

#endif // RECORD_H_INCLUDED

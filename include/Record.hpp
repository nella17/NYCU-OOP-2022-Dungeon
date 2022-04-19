#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <vector>
#include <memory>

class Player;
class Room;

/* This is the record system. Get the information of the  */
/* player and rooms then save them to (a) file(s). Notice */
/* that using pass by reference can prevent sending the   */
/* whole vector to the function.                          */

class Record {
public:
    static void save_to_file(const std::shared_ptr<Player>, const std::vector<Room>&);
    static void load_from_file(std::shared_ptr<Player>&, std::vector<Room>&);
private:
    static void save_player(const std::shared_ptr<Player>, std::ofstream&&);
    static void load_player(std::shared_ptr<Player>&, std::ifstream&&);
    static void save_rooms(const std::vector<Room>&, std::ofstream&&);
    static void load_rooms(std::vector<Room>&, std::ifstream&&);
};

#endif // RECORD_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.hpp"
#include "Item.hpp"
#include "Monster.hpp"
#include "NPC.hpp"
#include "Player.hpp"
#include "helper.hpp"

int main() {
    Dungeon dungeon = Dungeon();
    dungeon.run();

    return 0;
}

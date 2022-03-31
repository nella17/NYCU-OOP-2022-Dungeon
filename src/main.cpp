#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <vector>
#include "Dungeon.hpp"
#include "Item.hpp"
#include "Monster.hpp"
#include "NPC.hpp"
#include "Player.hpp"


using namespace std;

void set_no_buffer_mode(int fd) {
    struct termios tty;
    tcgetattr(fd, &tty);
    tty.c_lflag &= ~(ICANON|ECHO);
    tcsetattr(fd, TCSANOW, &tty);
}

int main(){
    set_no_buffer_mode(STDIN_FILENO);

    /*Dungeon dungeon = Dungeon();
    dungeon.runDungeon();*/
    cout << "meow" << endl;
    return 0;
}

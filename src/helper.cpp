#include "helper.hpp"

mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());

void set_no_buffer_mode(int fd) {
    struct termios tty;
    tcgetattr(fd, &tty);
    tty.c_lflag &= ~ICANON;
    tcsetattr(fd, TCSANOW, &tty);
}

void set_buffer_mode(int fd) {
    struct termios tty;
    tcgetattr(fd, &tty);
    tty.c_lflag |= ICANON;
    tcsetattr(fd, TCSANOW, &tty);
}

void set_no_echo_mode(int fd) {
    struct termios tty;
    tcgetattr(fd, &tty);
    tty.c_lflag &= ~ECHO;
    tcsetattr(fd, TCSANOW, &tty);
}

void set_echo_mode(int fd) {
    struct termios tty;
    tcgetattr(fd, &tty);
    tty.c_lflag |= ECHO;
    tcsetattr(fd, TCSANOW, &tty);
}

set<int> special_char = { 0x1B, 0x1B5B };
map<int,DIRECTION> key_to_dir = {
    { 0x1B5B41, DIRECTION::UP },
    { 0x1B5B42, DIRECTION::DOWN },
    { 0x1B5B43, DIRECTION::RIGHT },
    { 0x1B5B44, DIRECTION::LEFT },
};

char getchar(int fd) {
    char c;
    read(fd, &c, 1);
    return c;
}

int read_char(int fd) {
    int r = getchar(fd);
    while (special_char.find(r) != special_char.end())
        r = (r << 8) | getchar(fd);
    return r;
}

void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

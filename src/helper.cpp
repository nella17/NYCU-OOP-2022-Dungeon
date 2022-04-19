#include "helper.hpp"

#include <fcntl.h>
#include <termios.h>
#include <chrono>
#include <iostream>
#include <set>
#include <map>

std::mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());

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

namespace {
const auto key2dir = std::map<int,DIRECTION>{
    { 'W', DIRECTION::UP },
    { 'S', DIRECTION::DOWN },
    { 'D', DIRECTION::RIGHT },
    { 'A', DIRECTION::LEFT },
    { 0x1B5B41, DIRECTION::UP },
    { 0x1B5B42, DIRECTION::DOWN },
    { 0x1B5B43, DIRECTION::RIGHT },
    { 0x1B5B44, DIRECTION::LEFT },
};
}
DIRECTION key_to_dir(int key) {
    auto it = key2dir.find(key);
    if (it == key2dir.end())
        return DIRECTION::None;
    return it->second;
}
bool is_dir_key(int key) {
    return key2dir.find(key) != key2dir.end();
}

namespace {
inline char getchar(int fd) {
    char c;
    read(fd, &c, 1);
    return c;
}
const auto special_char = std::set<int>{ 0x1B, 0x5B };
}

int read_char(int fd) {
    int r = getchar(fd);
    while (special_char.find(r & 0xff) != special_char.end())
        r = (r << 8) | getchar(fd);
    return toupper(r);
}
int read_char_no_buffer_echo(int fd) {
    set_no_buffer_mode(fd);
    set_no_echo_mode(fd);
    int r = read_char(fd);
    set_buffer_mode(fd);
    set_echo_mode(fd);
    return r;
}

void clearScreen() {
    std::cout << "\033[2J\033[1;1H\n";
}

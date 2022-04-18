#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <random>
#include <chrono>
#include <iostream>
#include <set>
#include <map>
using namespace std;

extern mt19937 rng;

#define DEFAULT_FD STDIN_FILENO

void set_no_buffer_mode(int fd = DEFAULT_FD);
void set_buffer_mode(int fd = DEFAULT_FD);

void set_no_echo_mode(int fd = DEFAULT_FD);
void set_echo_mode(int fd = DEFAULT_FD);

enum class DIRECTION {
    UNKNOWN = 0,
    UP, DOWN, RIGHT, LEFT,
};
extern map<DIRECTION,string> dir_to_str;

extern map<int,DIRECTION> key_to_dir;
inline bool is_dir_key(int key);

extern set<int> special_char;
int read_char(int fd = DEFAULT_FD);

void clearScreen();

#endif // HELPER_H_INCLUDED

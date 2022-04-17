#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <random>
#include <chrono>
#include <iostream>

using namespace std;

extern mt19937 rng;

#define DEFAULT_FD STDIN_FILENO

void set_no_buffer_mode(int fd = DEFAULT_FD);
void set_buffer_mode(int fd = DEFAULT_FD);

void set_no_echo_mode(int fd = DEFAULT_FD);
void set_echo_mode(int fd = DEFAULT_FD);

enum class DIRECTION {
    UNKNOWN = 0,
    LEFT, RIGHT, UP, DOWN,
};

void clearScreen();

#endif

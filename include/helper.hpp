#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <unistd.h>
#include <random>
#include <string>

#include "magic_enum.hpp"
template<typename T>
inline std::string enum_name(T e) { return std::string{magic_enum::enum_name(e)}; }

extern std::mt19937 rng;

constexpr int DEFAULT_FD = STDIN_FILENO;

void set_no_buffer_mode(int fd = DEFAULT_FD);
void set_buffer_mode(int fd = DEFAULT_FD);

void set_no_echo_mode(int fd = DEFAULT_FD);
void set_echo_mode(int fd = DEFAULT_FD);

enum class DIRECTION {
    None = 0,
    UP, DOWN, RIGHT, LEFT,
};

DIRECTION key_to_dir(int);
bool is_dir_key(int);

int read_char(int fd = DEFAULT_FD);
int read_char_no_buffer_echo(int fd = DEFAULT_FD);

void clearScreen();

#endif // HELPER_H_INCLUDED

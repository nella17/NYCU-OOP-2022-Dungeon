#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>

#define DEFAULT_FD STDIN_FILENO

void set_no_buffer_mode(int fd = DEFAULT_FD);
void set_buffer_mode(int fd = DEFAULT_FD);

void set_no_echo_mode(int fd = DEFAULT_FD);
void set_echo_mode(int fd = DEFAULT_FD);

#endif

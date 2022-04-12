#include "helper.hpp"

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

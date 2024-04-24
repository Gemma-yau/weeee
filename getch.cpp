#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "getch.h"

int getch() {
    struct termios oldTermios, newTermios;
    tcgetattr(STDIN_FILENO, &oldTermios);
    newTermios = oldTermios;
    newTermios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
    int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);
    return ch;
}

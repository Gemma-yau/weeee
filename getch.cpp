/// to receive keyboard input from the users without displaying/printing the input on screen
///return the ASCII value of the input
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

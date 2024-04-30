#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "getch.h"

/// to receive keyboard input from the player without displaying/printing it on the screen
/// return the ASCII value of the input
int getch() {
    struct termios old, newone ;
    tcgetattr(STDIN_FILENO, &old) ;      //store the old one
    newone = old ;
    newone.c_lflag &= ~(ICANON | ECHO);       
    tcsetattr(STDIN_FILENO, TCSANOW, &newone);    //use the new one
    int value = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old);           //switch back
    return value;
}

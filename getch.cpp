#include <iostream>
#include <termios.h>
#include <unistd.h>
#include "getch.h"

/// to receive keyboard input from the player without displaying/printing it on the screen
/// return the ASCII value of the input
int getch() {
    struct termios oldtermios, newtermios ;
    tcgetattr(STDIN_FILENO, &oldtermios) ;      //store the old one
    newtermios = oldtermios ;
    newtermios.c_lflag &= ~(ICANON | ECHO);        //change it
    tcsetattr(STDIN_FILENO, TCSANOW, &newtermios);    //use the new one
    int value = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldtermios);           //switch back the old one
    return value;
}

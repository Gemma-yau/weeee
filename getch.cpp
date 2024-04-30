#include <iostream>
#include <termio.h>
#include "getch.h"

/// to receive keyboard input from the player without displaying/printing it on the screen
/// return the ASCII value of the input
int getch() {
  struct termios old,newone;
  tcgetattr(0, &old) ;
  newone=old;
  cfmakeraw(&newone);
  tcsetattr(0,TCSANOW,&newone);
  int value=getchar();
  tcsetattr(0,TCSANOW,&old);
  return value;
}

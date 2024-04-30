#include <iostream>
#include <termio.h>

int getch() {
  struct termios old,newone;
  tcgetattr(STDIN_FILENO, &old) ;
  newone=old;
  
}

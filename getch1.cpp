#include <iostream>
#include <termio.h>

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

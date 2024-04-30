#ifndef PC_H
#define PC_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include "getch.h"
using namespace std;

using namespace std;
struct coord{
    int first;
    int second;
};

void printdot(coord point, vector<coord> used, coord present);

int printmainpage();

#endif

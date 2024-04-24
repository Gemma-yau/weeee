#ifndef PC_H
#define PC_H

#include <iostream>
#include <vector>
using namespace std;

struct coord{
    int first;
    int second;
};

void printdot(coord point, vector<coord> used, coord present);

#endif

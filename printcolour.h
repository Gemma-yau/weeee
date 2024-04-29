#ifndef PC_H
#define PC_H


struct coord{
    int first;
    int second;
};

void printdot(coord point, vector<coord> used, coord present);

int printmainpage();

#endif

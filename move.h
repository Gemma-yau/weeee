#ifndef MOVE_H
#define MOVE_H

#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>     //for clear screen
#include "getch.h"
#include "printcolour.h"            //for struct coord
#include "findcoord.h"

using namespace std;

bool findcoord(coord point,vector<coord> used);
bool canconnect(int next, vector< vector<int> > lst, coord present,coord previous,string &status);
void popup_page();
void move (vector<coord> &used, coord &present,int &next, vector< vector<int> > lst, string &status);

#endif

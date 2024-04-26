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

bool canconnect(int next, vector< vector<int> > lst, coord present,string &status, vector<coord> used, int seq[20]);
void popup_page();
void move (vector<coord> &used, coord &present,int &next, vector< vector<int> > lst, string &status, int seq[20]);

#endif

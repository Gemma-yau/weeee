#ifndef PRINTBG_H
#define PRINTBG_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <string>
#include "printcolour.h" 
using namespace std;

bool canconnect(int next, vector< vector<int> > lst, coord present,coord previous,string &status);
void popup_page();
void move (vector<coord> &used, coord &present,int &next, vector< vector<int> > lst, string &status);

#endif

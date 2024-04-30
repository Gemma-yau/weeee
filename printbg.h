#ifndef PRINTBG_H
#define PRINTBG_H


#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <string>
#include "printcolour.h" 
using namespace std;

void printbg(string status,coord present,vector<coord> used,int next, vector < vector<int>> lst, int mode );

#endif

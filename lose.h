#ifndef LOSE_H
#define LOSE_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "move.h"

using namespace std;

void lose(string &status, int next, int size, coord present, vector<vector<int>> board, vector<coord> used);

#endif

///to find if the coord is used or not, return true if used.

#include <iostream>
#include <vector>
#include "findcoord.h"
#include "printcolour.h"
using namespace std;

struct coord{
    int first;
    int second;
};

bool findcoord(coord point,vector<coord> used){
 for (int i=0;i<used.size();i++){
  if (used[i].first == point.first && used[i].second == point.second)
   return true;}
   return false;
 }


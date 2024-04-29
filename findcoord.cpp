///to check if the dot has been used or not, return true if used.
///input: the coordinates of dot you want to check, the vector storung all dots that have been used

#include <iostream>
#include <vector>
#include "findcoord.h"
#include "printcolour.h"   //for struct coord
using namespace std;


bool findcoord(coord point,vector<coord> used){
 for (int i=0;i<used.size();i++){
  if (used[i].first == point.first && used[i].second == point.second)
   return true;}
   return false;
 }


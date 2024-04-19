///to find if the coord is used ir not, return true if used.

#include <iostream>
#include <vector>
#include "findcoord.h"

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

 int main(){
  vector<coord> used={{0,0},{1,0}};
  if (findcoord({1,1},used))
  cout<<"yes";
  else cout<<"no";
  cout<<endl;

  if (findcoord({0,0},used))
  cout<<"yes";
  else cout<<"no";
  cout<<endl;
 }

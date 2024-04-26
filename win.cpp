#include <iostream>
#include <vector>
#include <string>
#include "win.h"
#include "printcolour.h"
using namespace std;

void win(string &status, vector<coord> used){
  if (used.size() == 16)
   status="win";
}

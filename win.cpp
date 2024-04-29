#include <iostream>
#include <vector>
#include <string>
#include "win.h"
#include "printcolour.h"
using namespace std;

/// to determine if the player has won or not
/// it can change the status to "win" 
void win(string &status, vector<coord> used){
  if (used.size() == 16)
   status="win";
}

#include <iostream>
#include <vector>
#include <string>
#include "win.h"
#include "printcolour.h"
using namespace std;

/// to determine if the player has won or not
/// it will change the status to "win" when all the dots have been used 
void win(string &status, vector<coord> used){
  if (used.size() == 16)
   status="win";
}

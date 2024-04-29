#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "findcoord.h"
#include "lose.h"

using namespace std;

/// to check if the player has lost or not
/// it can change the status to "lose" 
void lose(string &status, int next, int size, coord present, vector<vector<int>> board, vector<coord> used, int seq[20]) {
  for ( int i = 0; i < size; i++ ){
    if ( i != present.first ) {            //## not the same row as present ##
      for ( int j = 0; j < size; j++ ){          //## for every element in that row ##
        coord step = {i,j};
        if ( !findcoord(step,used) && board[i][j] == seq[next] ){      //## if not in used and value == next
          return;
        }
      }
    }
  }
  status = "lose";
  return;
}


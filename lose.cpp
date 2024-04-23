#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void lose(string &status, int next, int size = 4, coord present, <vecotr<vecotr<int>> board, vector<coord> used) {
  for ( int i = 0; i < size; i++ ){
    if ( present.fisrt != board[i] ) {            //## not the same row as present ##
      for ( int j = 0; j < size; j++ ){          //## for every element in that row ##
        coord step = {i,j};
        if ( !find(used.begin(),used.end(),step) && board[i][j] == next ){      //## if not in used and value == next
          status == normal;
          return;
        }
      }
    }
  }
  status == lose;
  return;


}

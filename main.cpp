#include <iostream>
#include <vector>
#include <string>
#include "getch.h"
#include "findcoord.h"
#include "lose.h"
#include "move.h"
#include "printbg.h"
#include "printcolour.h"
#include "printresult.h"
#include "setBoard.h"
#include "win.h"

using namespace std;

int main() {

while (true) { 
  string status="normal";
  int next=1;
  coord present={0,0} ;
  vector<coord> used = { {0,0} };
  system("clear");
  int mode = printmainpage();      //print the main page of the game
                           //receive the enter button

  int seq[20] = {1,2,3,4,3,2,1,2,3,4,3,2,1,2,3,4,1};
  if (mode == 2){
    int c = 0;
    while (c < 16){
      for ( int i = 1; i < 6; i++){
        seq[c] = i;
	      c++ ;}
      for ( int i = 6; i > 1; i--){
      	seq[c] = i;
	      c++ ;}
    }
  }

  vector<vector<int>> board = setBoard(seq);           //generate number 
  printbg(status, present, used, next, board, mode);

  while (status !="end" && status !="lose" && status!="win") {
    status="normal" ;     //reset_the_content_of_status 
    move(used, present, next, board, status, seq);
    printbg(status, present, used, next, board, mode);
    win(status, used);
    if (status == "connect")
     lose(status, next, 4, present, board, used, seq) ;
  }

  printresult(status);
}
}


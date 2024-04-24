#include <iostream>
#include <vector>
#include <string>
#include "findcoord.h"
#include "lose.h"
#include "move.h"
#include "printbg.h"
#include "printcolour"
#include "printresult.h"
#include "setBoard.h"
#include "win.h"

using namespace std;

int main() {

while (true) {
  vector<vector<int>> board = setboard()；           //generate number  
  string status=“normal” ;
  int next=1;
  coord present={0,0} ;
  vector<coord> used = { {0,0} };

//print the main page of the game
//receive the enter button

  printbg(status, present, used, next, board);

  while (status !=“end” && status !=“lose” && status!="win") {
     status=“normal” ;     #reset_the_content_of_status 
     move(used, present, next, board, status);
     printbg(status, present, used, next, board);
     win(status, used);
     lose(status, next, 4, present, board, used) ;
  }

  printresult(status);
}

}


#include <iostream>
#include <>
#using namespace std;


int main() {

while (true) {
  setboard()；           //generate number  
  string status=“normal” ;
  int next=1;
  coord present={0,0} ;
  vector<coord> used = { {0,0} };

//print the main page of the game
//receive the enter button

  printbg();

  while (status !=“end” && status !=“lose” && status!="win") {
     status=“normal” ;     #reset_the_content_of_status 
     move();
     printbg();
     win();
     lose() ;
  }

  printresult(status);
}

}


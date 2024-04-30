#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "printresult.h"
#include "getch.h"
using namespace std;

/// to print the ending screen (win/lose/end)
void printresult(string status){
  system("clear");
  ifstream fin;
  string line;
  if (status=="end"){
   cout<<endl<<endl<<endl<<endl<<endl;
   fin.open("end.txt");
  }

  else if (status=="lose"){
   cout<<endl<<endl<<endl<<endl<<endl;
   fin.open("lose.txt");
  }

  else {
   cout<<endl<<endl<<endl<<endl<<endl;
   fin.open("win.txt");
  }

  while ( getline(fin,line) ){
     cout << line << endl;}
  cout<<endl;
  fin.close();
  int get=getch();
  while (get != 10)
    get=getch();
}

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unistd.h>
#include "printcolour.h"
#include "getch.h"
using namespace std;

#define reset  "\033[0m"
#define Green   "\033[32m"  
#define Red   "\033[31m"      
#define Yellow  "\033[33m"   


void printdot(coord point,vector<coord> used,coord present){
   for (int i=0;i<used.size();i++){
       if (used[i].first==point.first && used[i].second==point.second){
	    if (point.first == present.first && point.second==present.second)
                      cout<<Red<<"◙"<<reset;
            else cout<<Red<<"•"<<reset;
           return;
       }
   }
    if (point.first == present.first && point.second==present.second){
        cout<<Yellow<<"◙"<<reset;
        return;
    }
       cout<<Green<<"•"<<reset;
       return;
    } 

void printmainpage() {
  system("clear");
  cout<<endl<<endl<<endl;
  cout<<"     "<<"       "<<Yellow<<"•                                            "<<endl;
  cout<<"     "<<"        \\                                            "<<reset<<endl;
  cout<<"     "<<"   CCCCC "<<Yellow<<"\\"<<reset<<"OOOOO  N   N  N   N  EEEEE  CCCCC  TTTTT   "<<endl;
  cout<<"     "<<"   C      O   O  NN  N  NN  N  E      C        T     "<<endl;
  cout<<"     "<<"   C      O"<<Yellow<<"\\"<<reset<<"  O  N N N  N N N  EEEEE  C        T     "<<endl;
  cout<<"     "<<"   C      O "<<Yellow<<"\\"<<reset<<" O  N  NN  N  NN  E      C        T     "<<endl;
  cout<<"     "<<"   CCCCC  OOOOO  N   N  N   N  EEEEE  CCCCC    T   "<<Yellow<<"• "<<endl;
  cout<<"     "<<"              \\                                   /  "<<reset<<endl;
  cout<<"     "<<"  the          "<<Yellow<<"\\                                 /   "<<reset<<endl;
  cout<<"     "<<"         D D    "<<Yellow<<"\\"<<reset<<"OOOOO  TTTTT  SSSSS            "<<Yellow<<"/"<<reset<<"    "<<endl;
  cout<<"     "<<"         D   D   O   O    T    S               "<<Yellow<<"/     "<<reset<<endl;
  cout<<"     "<<"         D    D  O"<<Yellow"\\"<<reset<<"  O    T    SSSSS          "<<Yellow<<"/      "<<reset<<endl;
  cout<<"     "<<"         D   D   O "<<Yellow<<"\\"<<reset<<" O    T        S         "<<Yellow<<"/       "<<reset<<endl;
  cout<<"     "<<"         D D     OOOOO    T    SSSSS        "<<Yellow<<"/        "<<endl;
  cout<<"     "<<"                     \\                     /         "<<endl;
  cout<<"     "<<"                      •                   •         "<<reset<<endl<<endl<<endl;
  usleep(1000000);
  cout<<"                                     [ PRESS ENTER TO START ]"<<endl;
 int check=getch();
 while (check !=10)
	 check = getch();

}

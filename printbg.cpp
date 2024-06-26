#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
#include <string>
#include "printcolour.h" 
#include "printbg.h"
using namespace std;

#define reset  "\033[0m"
#define Green   "\033[32m"  
#define Red   "\033[31m"      
#define Yellow  "\033[33m"   
#define Black   "\033[30m"

// to print the whole game, including the progress line and the board
void printbg(string status,coord present,vector<coord> used,int next, vector < vector<int>> lst, int mode) {
   if (status=="end")
      return;
   system("clear");
   string process=(mode == 1)?"1234321234321234":"123456543212345654321234";
   
   cout<<endl;        
   cout<<"   Progress : ";              //printing progress
   for (int i=0;i<next;i++)
     cout<<Black<<process[i]<<reset;
     cout<<' '<<Yellow<<process[next]<<reset<<' '; 
    if (next<15){
        for (int i=next+1;i<16;i++)
          cout<<process[i];
    }
    cout<<endl<<endl;
    
    cout<<"     ";   
    for (int i=0;i<4;i++){       
        cout<<"      ";
        cout<<lst[0][i];}
        
    cout<<endl;
    cout<<"     ";
   for (int i=0;i<4;i++) {  
   coord p;
   p.first=0;
   p.second=i;
   cout<<"  __  ";
   printdot(p,used,present);}
   cout<<"  __"<<endl;
 
 if (status=="normal" || status=="connect"){
    for (int j=0;j<4;j++){
    coord p1,p2;
    p1.first=1;
    p1.second=j;
    p2.first=3;
    p2.second=j;
    cout<<"     ";
    cout<<"|"<<setw(33)<<"|"<<endl;
    cout<<"  "<<lst[3][j]<<"  ";
    printdot(p2,used,present);
    cout<<setw(37);
    printdot(p1,used,present);
    cout<<"  "<<lst[1][j];
    cout<<endl;
    }
 }

 else {                           //print the message box
       cout<<"     ";
       cout<<"|"<<setw(33)<<"|"<<endl;
       cout<<"  "<<lst[3][0]<<"  ";
       printdot({3,0},used,present);
       cout<<setw(37);
       printdot({1,0},used,present);
       cout<<"  "<<lst[1][0];
       cout<<endl;
       cout<<"     ";
       cout<<"|"<<setw(33)<<"|"<<endl;
       cout<<"  "<<lst[3][1]<<"  ";
       printdot({3,1},used,present);
       cout<<"     "<<"#####################"<<"      ";
       printdot({1,1},used,present);
       cout<<"  "<<lst[1][1];
       cout<<endl;   
       
// print the message accordingly to the status
              
    if (status=="connect fail-same line") {
        cout<<"     ";
         cout<<"|"<<"     "<<"#"<<"   Connect Failed  "<<"#"<<"      "<<"|"<<endl;
         cout<<"  "<<lst[3][2]<<"  ";
         printdot({3,2},used,present);
         cout<<"     "<<'#'<<"   [ Same Side ]   "<<'#'<<"      "; }
         
    else if (status=="connect fail-number") {
        cout<<"     ";
         cout<<"|"<<"     "<<"#"<<"   Connect Failed  "<<"#"<<"      "<<"|"<<endl;
         cout<<"  "<<lst[3][2]<<"  ";
         printdot({3,2},used,present);
         cout<<"     "<<'#'<<" [Incorrect Number]"<<'#'<<"      "; }
    
    else if (status=="invalid movement"){
        cout<<"     ";
        cout<<"|"<<"     "<<"#"<<"      Invalid      "<<"#"<<"      "<<"|"<<endl;
        cout<<"  "<<lst[3][2]<<"  ";
         printdot({3,2},used,present);
         cout<<"     "<<'#'<<"      Movement     "<<'#'<<"      ";
    }

       printdot({1,2},used,present);
       cout<<"  "<<lst[1][2];
       cout<<endl;
       cout<<"     ";
       cout<<"|"<<"     "<<"#####################"<<"      "<<"|"<<endl;
       cout<<"  "<<lst[3][3]<<"  ";
       printdot({3,3},used,present);
       cout<<setw(37);
       printdot({1,3},used,present);
       cout<<"  "<<lst[1][3];
       cout<<endl;

 }
 
   cout<<"     ";
   cout<<"|"<<setw(33)<<"|"<<endl;
   
   cout<<"     ";
   for (int i=0;i<4;i++){
   coord p;
   p.first=2;
   p.second=i;
   cout<<"  __  ";
   printdot(p,used,present);}
   cout<< "  __ " <<endl;

    cout<<"     ";
    for (int i=0;i<4;i++){
        cout<<"      ";
        cout<<lst[2][i];}
        cout<<endl;
}

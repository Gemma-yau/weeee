#include <iostream>
#include <iomanip>
#include <vector>
#include <stdlib.h>
// #include "printcolour.h"
using namespace std;

#define reset  "\033[0m"
#define Green   "\033[32m"  
#define Red   "\033[31m"      
#define Yellow  "\033[33m"   
#define Black   "\033[30m"

struct coord{
    int first;
    int second;
};

void print(coord point,vector<coord> used,coord present){
   for (int i=0;i<used.size();i++){
       if (used[i].first==point.first && used[i].second==point.second){
	    if (point.first == present.first && point.second==present.second)
                      cout<<Red<<"⦾"<<reset;
            else cout<<Red<<"•"<<reset;
           return;
       }
   }
    if (point.first == present.first && point.second==present.second){
        cout<<Yellow<<"⦾"<<reset;
        return;
    }
       cout<<Green<<"•"<<reset;
       return;
    } 


void printbg(string status,coord present,vector<coord> used,int next, vector < vector<int>> lst ) {
   
   system("clear");
   string process="1234321234321234";
   
   cout<<endl;        
   cout<<"   Process : ";             //printing process
   for (int i=0;i<next;i++)
     cout<<Black<<process[i]<<reset;
     cout<<' '<<Yellow<<process[next]<<reset<<' '; 
    if (next<15){
        for (int i=next+1;i<16;i++)
          cout<<process[i];
    }
    cout<<endl<<endl;
    
    cout<<"     ";   
    for (int i=0;i<4;i++){     //printing numbers corresponding to dots
        cout<<"      ";
        cout<<lst[0][i];}
        
    cout<<endl;
    cout<<"     ";
   for (int i=0;i<4;i++) {  
   coord p;
   p.first=0;
   p.second=i;
   cout<<"  __  ";
   print(p,used,present);}
   cout<<"  __"<<endl;
 
 if (status=="normal"){
    for (int j=0;j<4;j++){
    coord p1,p2;
    p1.first=1;
    p1.second=j;
    p2.first=3;
    p2.second=j;
    cout<<"     ";
    cout<<"|"<<setw(33)<<"|"<<endl;
    cout<<"  "<<lst[3][j]<<"  ";
    print(p2,used,present);
    cout<<setw(37);
    print(p1,used,present);
    cout<<"  "<<lst[1][j];
    cout<<endl;
    }
 }

 else {                        //print the message frame
       cout<<"     ";
       cout<<"|"<<setw(33)<<"|"<<endl;
       cout<<"  "<<lst[3][0]<<"  ";
       print({3,0},used,present);
       cout<<setw(37);
       print({1,0},used,present);
       cout<<"  "<<lst[1][0];
       cout<<endl;
       cout<<"     ";
       cout<<"|"<<setw(33)<<"|"<<endl;
       cout<<"  "<<lst[3][1]<<"  ";
       print({3,1},used,present);
       cout<<"     "<<"#####################"<<"      ";
       print({1,1},used,present);
       cout<<"  "<<lst[1][1];
       cout<<endl;   
       
/////print msg here
              
    if (status=="connect fail-same line") {
        cout<<"     ";
         cout<<"|"<<"     "<<"#"<<"   Connect Failed  "<<"#"<<"      "<<"|"<<endl;
         cout<<"  "<<lst[3][2]<<"  ";
         print({3,2},used,present);
         cout<<"     "<<'#'<<"   [ Same Side ]   "<<'#'<<"      "; }
         
    else if (status=="connect fail-number") {
        cout<<"     ";
         cout<<"|"<<"     "<<"#"<<"   Connect Failed  "<<"#"<<"      "<<"|"<<endl;
         cout<<"  "<<lst[3][2]<<"  ";
         print({3,2},used,present);
         cout<<"     "<<'#'<<" [Incorrect Number]"<<'#'<<"      "; }
    
    else if (status=="invalid movement"){
        cout<<"     ";
        cout<<"|"<<"     "<<"#"<<"      Invalid      "<<"#"<<"      "<<"|"<<endl;
        cout<<"  "<<lst[3][2]<<"  ";
         print({3,2},used,present);
         cout<<"     "<<'#'<<"      Movement     "<<'#'<<"      ";
    }



       print({1,2},used,present);
       cout<<"  "<<lst[1][2];
       cout<<endl;
       cout<<"     ";
       cout<<"|"<<"     "<<"#####################"<<"      "<<"|"<<endl;
       cout<<"  "<<lst[3][3]<<"  ";
       print({3,3},used,present);
       cout<<setw(37);
       print({1,3},used,present);
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
   print(p,used,present);}
   cout<< "  __ " <<endl;

    cout<<"     ";
    for (int i=0;i<4;i++){
        cout<<"      ";
        cout<<lst[2][i];}
        cout<<endl;
}


int main(){
  string status="invalid movement";
  coord present={1,1};
  vector<coord> used={{0,2},{1,1}};
  int next=2;
  vector < vector<int>> lst ={ {1,3,3,1},{4,1,3,4},{2,2,2,3},{3,4,2,2} };
  
  printbg(status,present,used,next,lst);
}

#include <iostream>
#include <iomanip>
#include <vector>
#include "printcolour.h"
using namespace std;

int main() {  
   vector<coord> used ={{0,1},{3,2},{1,3}};
   coord present={2,2};

   for (int i=0;i<4;i++) {
   coord p;
   p.first=0;
   p.second=i;
   cout<<" __ ";
   print(p,used,present);}
   cout<<" __"<<endl;
    
    for (int j=0;j<4;j++){
    coord p1,p2;
    p1.first=1;
    p1.second=j;
    p2.first=3;
    p2.second=j;
    cout<<"|"<<setw(23)<<"|"<<endl;
    print(p1,used,present);
    cout<<setw(27);
    print(p2,used,present);
    cout<<endl;
    }
    
    cout<<"|"<<setw(23)<<"|"<<endl;
    
   for (int i=0;i<4;i++){
   coord p;
   p.first=2;
   p.second=i;
   cout<<" __ ";
   print(p,used,present);}
   cout<<" __"<<endl;
}

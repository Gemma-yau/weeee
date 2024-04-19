#include <iostream>
#include <vector>
using namespace std;

#define Green   "\033[32m"  
#define Red   "\033[31m"      
#define Yellow  "\033[33m"   

struct coord{
    int first;
    int second;
};

void print(coord point,vector<coord> used,coord present){
    if (point.first == present.first && point.second==present.second){
        cout<<Yellow<<".";
        return;
    }
    if (used.size()==0){
        cout<<Green<<".";
        return;}
        
    else{
      for (int i=0;i<used.size();i++)
       if (used[i].first==point.first && used[i].second==point.second){
           cout<<Red<<".";
           return;
       }
       cout<<Green<<".";
       return;
    } 
}

int main(){
  vector<coord> used = {{1,1},{2,0}};
  coord present = {3,4};
  print({1,1},used,present);
  print({5,4},used,present);
  print({3,4},used,present);
}

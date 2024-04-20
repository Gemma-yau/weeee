#include <iostream>
#include <vector>
#include "printcolour.h"
using namespace std;

#define reset  "\033[0m"
#define Green   "\033[32m"  
#define Red   "\033[31m"      
#define Yellow  "\033[33m"   


void print(coord point,vector<coord> used,coord present){
    if (point.first == present.first && point.second==present.second){
        cout<<Yellow<<"(•)"<<reset;
        return;
    }
    if (used.size()==0){
        cout<<Green<<"•"<<reset;
        return;
	}
        
    else{
      for (int i=0;i<used.size();i++)
       if (used[i].first==point.first && used[i].second==point.second){
           cout<<Red<<"•"<<reset;
           return;
       }
       cout<<Green<<"•"<<reset;
       return;
    } 
}

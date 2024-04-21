#include <iostream>
#include <vector>
#include "printcolour.h"
using namespace std;

#define reset  "\033[0m"
#define Green   "\033[32m"  
#define Red   "\033[31m"      
#define Yellow  "\033[33m"   


void print(coord point,vector<coord> used,coord present){
   for (int i=0;i<used.size();i++){
       if (used[i].first==point.first && used[i].second==point.second){
	    if (point.first == present.first && point.second==present.second)
                      cout<<Red<<"◉"<<reset;
            else cout<<Red<<"•"<<reset;
           return;
       }
   }
    if (point.first == present.first && point.second==present.second){
        cout<<Yellow<<"◉"<<reset;
        return;
    }
       cout<<Green<<"•"<<reset;
       return;
    } 
}

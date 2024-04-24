#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "setBoard.h"

using namespace std;

vector<vector<int>> setBoard(){
  int size = 4;
  int num = 1;
  int Number[25] = {1,2,3,4,3,2,1,2,3,4,3,2,1,2,3,4,3,2,1,2,3,4,3,2,1};
  srand(time(NULL));

  vector < vector <int> > lst;
  lst.resize(size,vector<int>(size));

  lst[0][0] = 1;
  int pos[2] = {0,0};

  //## add num into lst ##
  while (true){
    int iPos = pos[0];
    int que[20], queCount = 0;

    for (int i = 0; i < size; i++){
      if ( i != pos[0] ){                                 
        int x = count(lst[i].begin(), lst[i].end(), 0);

        if (x > 1){   			//## see if that row have enough space for adding a num ##
	  que[queCount] = i;
          queCount++;
	}
      }
    }  
    
    if (queCount == 0){
    	for (int i = 0; i < size; i++){
	  if ( i != pos[0] && count(lst[i].begin(), lst[i].end(), 0) != 0){
	    que[queCount] = i;
	    queCount++;
	  }
        }
    }
    if (queCount == 0){
    	break;
    }
    else if (queCount > 1){
    	iPos = que[rand() % (queCount)];          //## set the first pos for adding new num ##
    }
    else if (queCount == 1){
	iPos = que[0];
    }

    queCount = 0;

    for (int i = 0; i < size; i++){
      if (lst[iPos][i] == 0){                //## if the pos is empty ##
	que[queCount] = i;
        queCount++;
      }
    }
    
    int iPos2 = que[rand() % (queCount)];    //## set the second pos for adding new num ##
    lst[iPos][iPos2] = Number[num];
    num++;

    pos[0] = iPos;
    pos[1] = iPos2;
}

  //## print the board ##
  // for (int i = 0; i < size; i++){
  //   for (int j = 0; j < size; j++){
  //     cout << lst[i][j] << " ";
  //   }
  //   cout << endl;
  // }

//## return lst ##
return lst;
}

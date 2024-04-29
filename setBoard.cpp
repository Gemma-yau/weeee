#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "setBoard.h"

using namespace std;

/// to generate the position of integers randomly
/// input: array of integers (1-4 for easy mode, 1-6 for hard mode)
vector<vector<int>> setBoard(int Number[20]){
  int size = 4;
  int num = 1;
  srand(time(NULL));

  vector < vector <int> > lst;
  lst.resize(size,vector<int>(size));

  lst[0][0] = 1;
  int pos[2] = {0,0};

  //## add num into lst ##
  while (true){
    int iPos = pos[0]; 			//## iPos = the row of the previous num
    int que[20], queCount = 0;		//## que[20] = storing candidate; queCount = num of possible row/cell

    // deciding the which row to add
    for (int i = 0; i < size; i++){
      if ( i != pos[0] ){                                 
        int x = count(lst[i].begin(), lst[i].end(), 0);			//## count the empty space in a row

        if (x > 1){   			//## if that row has more than 1 space for adding a num 
	  que[queCount] = i;		//## add to candidate
          queCount++;
	}
      }
    }  
    
    if (queCount == 0){			//## if none of the rows have more than one space
    	for (int i = 0; i < size; i++){	
	  if ( i != pos[0] && count(lst[i].begin(), lst[i].end(), 0) != 0){		//## if that row is not the same as the previous num and is not full
	    que[queCount] = i;
	    queCount++;
	  }
        }
    }
    if (queCount == 0){			//## queCount still = 0 --> all rows are full
    	break;
    }
    else if (queCount > 0){
    	iPos = que[rand() % (queCount)];          //## set the first position (row)
    }

    // deciding the which cell to add
    queCount = 0;

    for (int i = 0; i < size; i++){
      if (lst[iPos][i] == 0){                //## if the cell is empty ##
	que[queCount] = i;
        queCount++;
      }
    }
    
    int iPos2 = que[rand() % (queCount)];    //## set the second pos (cell)
    lst[iPos][iPos2] = Number[num];		//## add the number into that cell
    num++;

    pos[0] = iPos;
    pos[1] = iPos2;
}

//return a 2D vector which stores the numbers of the board
return lst;
}

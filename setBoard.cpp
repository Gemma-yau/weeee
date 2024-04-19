#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

void setBoard(int size=4){
  int num;
  srand(time(NULL));

  vector < vector <int> > lst;
  lst.resize(size,vector<int>(size));

  lst = {{1,2,3,4},{2,2,3,4},{3,3,3,4},{4,4,4,4}};

  for (int i = 0; i < size; i++){
    for (int j = 0; j < size; j++){
      cout << lst[i][j] << " ";
    }
    cout << endl;
}

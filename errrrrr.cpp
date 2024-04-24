#include <iostream>
#include <vector>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <algorithm>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
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

bool findcoord(coord point,vector<coord> used){
 for (int i=0;i<used.size();i++){
  if (used[i].first == point.first && used[i].second == point.second)
   return true;}
   return false;
 }

 int getch() {
    struct termios oldTermios, newTermios;
    tcgetattr(STDIN_FILENO, &oldTermios);
    newTermios = oldTermios;
    newTermios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newTermios);
    int ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldTermios);
    return ch;
}

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

int printmainpage() {
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
 system("clear");	
  cout<<"mode: [ easy (1) / hard (2) ] ";
  int mode=getch();                  //mode=1(easy), mode=2(hard)
  while (mode != 1 && mode != 2)
    int mode=getch();
 return mode;	 
}


void printbg(string status,coord present,vector<coord> used,int next, vector < vector<int>> lst,int mode) {
   if (status=="end")
    return;
   system("clear");
   string process=(mode == 1)?"1234321234321234":"123456543212345654321234";
   
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

 else {                        //print the message frame
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
       
/////print msg here
              
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

bool canconnect(int next, vector< vector<int> > lst, coord present,string &status,vector<coord >used, int seq[20]){
  int lent=used.size();
  coord previous=used[lent-1];
 if (present.first == previous.first){
   status= "connect fail-same line";   // cant work cuz they lie on same line
   return false;}
  else {
      if ( lst[present.first][present.second] == seq[next] )
        return true;
      else {
      status="connect fail-number";              //say cant cuz this isnt the next number
      return false;
      }
  }
}

void popup_page(){
  system("clear");
  cout<<endl<<endl<<endl;
  cout<<"     ";
  cout<<"#################################"<<endl;
  cout<<"     "<<"#"<<"                               "<<"#"<<endl;
  cout<<"     "<<"#"<<"   [      Return  (Q)      ]   "<<"#"<<endl;
  cout<<"     "<<"#"<<"                               "<<"#"<<endl;
  cout<<"     "<<"#"<<"                               "<<"#"<<endl;
  cout<<"     "<<"#"<<"   [      Restart (R)      ]   "<<"#"<<endl;
  cout<<"     "<<"#"<<"                               "<<"#"<<endl;
  cout<<"     "<<"#"<<"                               "<<"#"<<endl;
  cout<<"     "<<"#"<<"   [  Start a New Game (N) ]   "<<"#"<<endl;
  cout<<"     "<<"#"<<"                               "<<"#"<<endl;
  cout<<"     "<<"#################################"<<endl;
  cout<<endl;
  }

void move (vector<coord> &used, coord &present,int &next, vector< vector<int> > lst, string &status, int Number[20]) {

 int input=getch();
   if (input==68 || input==100){

      if(present.first==1){
         status="invalid movement";
         return;}              // or show "u cant move like that"
      
      if (present.first==3){
        if (!findcoord({1,present.second},used)){
	   present.first=1;
	   return;}

	 else {                  //opposite dot is used
	   if (present.second==0){
	     for (int i=1;i<4;i++){
                 if (!findcoord({1,i},used)){
                     present.first=1;
		     present.second=i;
		     return;}
	     }
	   }

	   else if (present.second==1 || present.second==2){
             if (!findcoord({1,present.second-1},used)){
	        present.first=1;
		present.second=present.second-1;
                return;}

	     if (!findcoord({1,present.second+1},used)){
	        present.first=1;
		present.second=present.second+1;
		return;}

	    if (present.second==1){              //check 3
               if (!findcoord({1,3},used)){
                  present.first=1;
		  present.second=3;
		  return; }
	    }
	    else {                    //present.second==2(check 0)
               if (!findcoord({1,0},used)){
                  present.first=1;
		  present.second=0;
		  return; }
	    }
	   }

	   else {             //present.second=3
	       for (int i=2;i>0;i--){
	         if (!findcoord({1,i},used)){
		   present.first=1;
		   present.second=i;
		   return; }
	       }
	   }}
	   status="invalid movement"; 
	 return;
      }

        int n=present.second;
         while (n<3){
	 if (!findcoord({present.first,n+1},used)){
	 present.second=n+1;
	 return ;}
	 else n+=1;
         }
	 if (present.first==0){
            for (int i=0;i<4;i++) {
             if (!findcoord({1,i},used)){
                present.first=1;
	        present.second=i;
	        return;
	     }
	    }
	  }
	else {           //when present.first==2
           for (int i=3;i>=0;i--){
              if (!findcoord({1,i},used)){
	      present.first=1;
	      present.second=i;
	      return;
	      }
	   }
	}
	status="invalid movement";       ///the whole line is used -> error
	return;            //what to do? or print "u cant move like that"
      }


   else if (input==65 || input==97){

        if(present.first==3){
	 status="invalid movement";
         return;}
	 // or show "u cant move like that"
        if (present.first==1){
	   if (!findcoord({3,present.second},used)){
	   present.first=3;
	   return;}

	 else {                  //opposite dot is used
	   if (present.second==0){
	     for (int i=1;i<4;i++){
                 if (!findcoord({3,i},used)){
                     present.first=3;
		     present.second=i;
		     return;}
	     }
	   }

	   else if (present.second==1 || present.second==2){
             if (!findcoord({3,present.second-1},used)){
	        present.first=3;
		present.second=present.second-1;
                return;}

	     if (!findcoord({3,present.second+1},used)){
	        present.first=3;
		present.second=present.second+1;
		return;}

	    if (present.second==1){              //check 3
               if (!findcoord({3,3},used)){
                  present.first=3;
		  present.second=3;
		  return; }
	    }
	    else {                    //present.second==2(check 0)
               if (!findcoord({3,0},used)){
                  present.first=3;
		  present.second=0;
		  return; }
	    }
	   }

	   else {             //present.second=3
	       for (int i=2;i>0;i--){
	         if (!findcoord({3,i},used)){
		   present.first=3;
		   present.second=i;
		   return; }
	       }
	   }}
	   status="invalid movement";
	 return;}

         int n=present.second;
         while (n>0){
	 if (!findcoord({present.first,n-1},used)){
	 present.second=n-1;
	 return;}
	 else n-=1;
         }
	 if (present.first==0){
            for (int i=0;i<4;i++) {
             if (!findcoord({3,i},used)){
                present.first=3;
	        present.second=i;
	        return;
	     }
	    }
	  }
	else {           //when present.first==2
           for (int i=3;i>=0;i--){
              if (!findcoord({3,i},used)){
	      present.first=3;
	      present.second=i;
	      return;
	      }
	   }
	}
	status="invalid movement";      ///the whole line is used -> error
	return; //what to do? or print "u cant move like that"

   }



   else if (input==87 || input==119){

        if(present.first==0){
         status="invalid movement";
	 return;} // or show "u cant move like that"

      if (present.first==2){
              if (!findcoord({0,present.second},used)){
	   present.first=0;
	   return;}

	 else {                  //opposite dot is used
	   if (present.second==0){
	     for (int i=1;i<4;i++){
                 if (!findcoord({0,i},used)){
                     present.first=0;
		     present.second=i;
		     return;}
	     }
	   }

	   else if (present.second==1 || present.second==2){
             if (!findcoord({0,present.second-1},used)){
	        present.first=0;
		present.second=present.second-1;
                return;}

	     if (!findcoord({0,present.second+1},used)){
	        present.first=0;
		present.second=present.second+1;
		return;}

	    if (present.second==1){              //check 3
               if (!findcoord({0,3},used)){
                  present.first=0;
		  present.second=3;
		  return; }
	    }
	    else {                    //present.second==2(check 0)
               if (!findcoord({0,0},used)){
                  present.first=0;
		  present.second=0;
		  return; }
	    }
	   }

	   else {             //present.second=3
	       for (int i=2;i>0;i--){
	         if (!findcoord({0,i},used)){
		   present.first=0;
		   present.second=i;
		   return; }
	       }
	   }}
	   status="invalid movement";
	 return; }

        int n=present.second;
         while (n>0){
	 if (!findcoord({present.first,n-1},used)){
	 present.second=n-1;
	 return;}
	 else n-=1;
         }

	 if (present.first==3){
            for (int i=0;i<4;i++) {
             if (!findcoord({0,i},used)){
                present.first=0;
	        present.second=i;
	        return;
	     }
	    }
	  }
	else {           //when present.first==1
           for (int i=3;i>=0;i--){
              if (!findcoord({0,i},used)){
	      present.first=0;
	      present.second=i;
	      return;
	      }
	   }
	}
	status="invalid movement";       ///the whole line is used -> error
	return; //what to do? or print "u cant move like that"
   }

   else if (input==83 || input==115){

	 if(present.first==2){
           status="invalid movement";
	   return;} // or show "u cant move like that"
        
	 if (present.first==0){
	   if (!findcoord({2,present.second},used)){
	   present.first=2;
	   return;}

	 else {                  //opposite dot is used
	   if (present.second==0){
	     for (int i=1;i<4;i++){
                 if (!findcoord({2,i},used)){
                     present.first=2;
		     present.second=i;
		     return;}
	     }
	   }

	   else if (present.second==1 || present.second==2){
             if (!findcoord({2,present.second-1},used)){
	        present.first=2;
		present.second=present.second-1;
                return;}

	     if (!findcoord({2,present.second+1},used)){
	        present.first=2;
		present.second=present.second+1;
		return;}

	    if (present.second==1){              //check 3
               if (!findcoord({2,3},used)){
                  present.first=2;
		  present.second=3;
		  return; }
	    }
	    else {                    //present.second==2(check 0)
               if (!findcoord({2,0},used)){
                  present.first=2;
		  present.second=0;
		  return; }
	    }
	   }

	   else {             //present.second=3
	       for (int i=2;i>0;i--){
	         if (!findcoord({2,i},used)){
		   present.first=2;
		   present.second=i;
		   return; }
	       }
	   }}
	   status="invalid movement";
	 return;}

        int n=present.second;
         while (n<3){
	 if (!findcoord({present.first,n+1},used)){
	 present.second=n+1;
	 return;}
	 else n+=1;
         }

	 if (present.first==3){
            for (int i=0;i<4;i++) {
             if (!findcoord({2,i},used)){
                present.first=2;
	        present.second=i;
	        return;
	     }
	    }
	  }
	else {           //when present.first==1
           for (int i=3;i>=0;i--){
              if (!findcoord({2,i},used)){
	      present.first=2;
	      present.second=i;
	      return;
	      }
	   }
	}
        status="invalid movement";     ///the whole line is used -> error
        return ; //what to do? or print "u cant move like that"
   }

   else if (input== 10){              //input=enter
      //create a previous point,so if present and previous lie on same line-> dont allow
       if (canconnect(next,lst,present,status,used, Number)){
         used.push_back(present);
	 next+=1;
	 status="connect";
       }
	return;}


   else if (input==81 || input==113){           //input='Q' or 'q' ->quit
     /////HV TO PRINT THE BG ONCE, TO SHOW THE LIST OF CHOICES !
      popup_page();      ///choose: restart(R) / new game(N) / return(Q)

      int choice=getch();
      while (choice != 81 && choice !=113 && choice !=82 && choice !=114 && choice !=78 && choice !=110 ){      //reload until they click specific buttons
            choice=getch();
      }

      if (choice == 81 || choice == 113)       //Q-> return to game, nth happen
           return;

      else if (choice == 82 || choice == 114){       //R -> restart, play again with the same map
           present.first=0;
	   present.second=0;
	   used.clear();
	   used.push_back({0,0});    //clear the used list-> all dots become unused
	   next=1;               //crestart the process
           return;
      }

      else if (choice == 78 || choice == 110){             ///N -> start a new game
            status="end";
            /////generate a new map
	    return;
      }
  }

else {                               //input= sth else-> retype
      return;
 }

}

void lose(string &status, int next, int size, coord present, vector<vector<int>> board, vector<coord> used, int seq[20]) {
  for ( int i = 0; i < size; i++ ){
    if ( i !=  present.first ) {            //## not the same row as present ##
      for ( int j = 0; j < size; j++ ){          //## for every element in that row ##
        coord step = {i,j};
        if ( !findcoord(step,used) && board[i][j] == seq[next] ){      //## if not in used and value == next
          return;
        }
      }
    }
  }
  status = "lose";
  return;
}

void win(string &status, vector<coord> used){
  if (used.size() == 16)
   status="win";
}
void printresult(string status){
  system("clear");
  if (status=="end"){
   cout<<endl<<endl<<endl;
   cout<<"     "<<"######################################"<<endl;
   cout<<"     "<<"#"<<"                                    "<<"#"<<endl;
   cout<<"     "<<"#"<<"    EEEEEE    N     N    D D        "<<"#"<<endl;
   cout<<"     "<<"#"<<"    E         NN    N    D   D      "<<"#"<<endl;
   cout<<"     "<<"#"<<"    E         N N   N    D    D     "<<"#"<<endl;
   cout<<"     "<<"#"<<"    EEEEEE    N  N  N    D     D    "<<"#"<<endl;
   cout<<"     "<<"#"<<"    E         N   N N    D    D     "<<"#"<<endl;
   cout<<"     "<<"#"<<"    E         N    NN    D   D      "<<"#"<<endl;
   cout<<"     "<<"#"<<"    EEEEEE    N     N    D D        "<<"#"<<endl;
   cout<<"     "<<"#"<<"                                    "<<"#"<<endl;
   cout<<"     "<<"######################################"<<endl;
   cout<<endl;
  }

  else if (status=="lose"){
   cout<<endl<<endl<<endl;
   cout<<"     "<<"######################################"<<endl;
   cout<<"     "<<"#"<<"                                    "<<"#"<<endl;
   cout<<"     "<<"#"<<"   L        O      SSSSS    EEEEE   "<<"#"<<endl;
   cout<<"     "<<"#"<<"   L       O O     S        E       "<<"#"<<endl;
   cout<<"     "<<"#"<<"   L      O   O    S        E       "<<"#"<<endl;
   cout<<"     "<<"#"<<"   L     O     O   SSSSS    EEEEE   "<<"#"<<endl;
   cout<<"     "<<"#"<<"   L      O   O        S    E       "<<"#"<<endl;
   cout<<"     "<<"#"<<"   L       O O         S    E       "<<"#"<<endl;
   cout<<"     "<<"#"<<"   LLLLL    O      SSSSS    EEEEE   "<<"#"<<endl;
   cout<<"     "<<"#"<<"                                    "<<"#"<<endl;
   cout<<"     "<<"######################################"<<endl;
   cout<<endl;
  }

  else {
   cout<<endl<<endl<<endl;
   cout<<"       "<<"🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉"<<endl;
   cout<<"     "<<"  "<<"                                    "<<"  "<<endl;
   cout<<"     "<<"🎉"<<"    W       W   IIIII    N     N    "<<"🎉"<<endl;
   cout<<"     "<<"  "<<"    W       W     I      NN    N    "<<"  "<<endl;
   cout<<"     "<<"🎉"<<"    W       W     I      N N   N    "<<"🎉"<<endl;
   cout<<"     "<<"  "<<"    W   W   W     I      N  N  N    "<<"  "<<endl;
   cout<<"     "<<"🎉"<<"    W  W W  W     I      N   N N    "<<"🎉"<<endl;
   cout<<"     "<<"  "<<"     WW   WW      I      N    NN    "<<"  "<<endl;
   cout<<"     "<<"🎉"<<"      W   W     IIIII    N     N    "<<"🎉"<<endl;
   cout<<"     "<<"  "<<"                                    "<<"  "<<endl;
   cout<<"       "<<"🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉 🎉"<<endl;
   cout<<endl;
  }
  int get=getch();
  while (get != 10)
    get=getch();
}

int main() {
  while (true){
  string status= "normal";
  int next=1;
  coord present={0,0};
  vector<coord> used = { {0,0} };
  system("clear");
  int mode=printmainpage();      //print the main page of the game
                             //receive the enter button and also determine the mode
  int array[20] = {1,2,3,4,3,2,1,2,3,4,3,2,1,2,3,4,1};
  if(mode == 2){
    int c = 0;
    while (c < 16){
      for ( int i = 1; i < 6; i++){
        array[c] = i;
        c++}
      for ( int i = 6; i > 1; i--){
      	array[c] = i;
      	c++;}}}
  vector<vector<int>> board = setBoard(array);
  printbg(status, present, used, next, board, mode);
  
  while (status != "end" && status != "lose" && status != "win") {
     status="normal" ;                    //reset_the_content_of_status
     move(used, present, next, board, status, array);
     printbg(status, present, used, next, board, mode);
     win(status, used);
     if (status=="connect")
      lose(status, next, 4, present, board, used, array) ;
  }
  printresult(status);
}
}

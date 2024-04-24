#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>     //for clear screen
#include "getch.h"
#include "printcolour.h"            //for struct coord
#include "findcoord.h"
#include "move.h"
using namespace std;


bool findcoord(coord point,vector<coord> used){              //to check if the dot has been used or not
 for (int i=0;i<used.size();i++){
  if (used[i].first == point.first && used[i].second == point.second)
   return true;}
   return false;
 }

bool canconnect(int next, vector< vector<int> > lst, coord present,coord previous,string &status){           
 if (present.first == previous.first){
   status= "connect fail-same line";   // cant work cuz they lie on same line
   return false;}
  else {
      string seq="1234321234321234";
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

void move (vector<coord> &used, coord &present,int &next, vector< vector<int> > lst, string &status) {       
 coord previous=present;

 int input=getch();
   if (input==68 || input==100){
     
      if(present.first==1){
         status="invalid movement";
         return;}              // or show "u cant move like that"
      if (present.first==3){
        if findcoord({1,present.second},used)
	  status="invalid movement";                    /// this point is used alr! u cant move like this
	 else 
           present.first=1;
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
         return;}         // or show "u cant move like that"
        if (present.first==1){
          if findcoord({3,present.second},used)
	    status="invalid movement";     /// this point is used alr! u cant move like this
	  else 
             present.first=3;
	  return;
        }
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
        if findcoord({0,present.second},used)
	  status="invalid movement";           /// this point is used alr! u cant move like this
	 else 
           present.first=0;
	 return;
      }
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
	break; //what to do? or print "u cant move like that"
   }

   else if (input==83 || input==115){
        
	 if(present.first==2){
           status="invalid movement";
	   return;} // or show "u cant move like that"
         if (present.first==0){
         if findcoord({2,present.second},used)
	  status="invalid movement";         /// this point is used alr! u cant move like this
	 else
           present.first=2;
	 return;
      }
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
       if canconnect(next,lst,present,previous,status){
         used.push_back(present);
	 next+=1;
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

	// endwin();  // End ncurses??
}


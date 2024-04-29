#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>     //for clearing screen
#include "getch.h"
#include "printcolour.h"            //for struct coord
#include "findcoord.h"
#include "move.h"
using namespace std;

/// to check if the connection is feasible when the player presses 'enter' key and attempts to connect two dots
/// return false if the connection is not feasible, and also changes the string status so as to enable the printing of pop-up message box accordingly
bool canconnect(int next, vector< vector<int> > lst, coord present, string &status, vector<coord> used, int seq[20]){           
	int lent=used.size();
	coord previous=used[lent-1];
if (present.first == previous.first){
	status= "connect fail-same line";   // cant work cuz the 2 dots are on the same line
	return false;}
  else {
      if ( lst[present.first][present.second] == seq[next] )
        return true;
      else {
      status="connect fail-number";              //cant work cuz the integer doesnt match
      return false;
      }
  }
}

/// print a table when the player presses the 'Q' key
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

/// to receive the player's input (kepboard pressing) and changes the player's position accordingly (moving up/down/left/right)
/// it also changes the string status to "invalid movement" if the player moves wrongly
/// e.g. attempting to move to the right even if he/she is on the rightest line already

/// to facilitate reading : struct coord is defined in printcolour.h.
/// coord.first represents line, top line=0,right line=1, bottom line=2, left line=3
/// coord.second represents position, range: 0-3, starts at the left/top
void move (vector<coord> &used, coord &present,int &next, vector< vector<int> > lst, string &status, int seq[20]) {

 int input=getch();
   if (input==68 || input==100){

      if(present.first==1){   
         status="invalid movement";
         return;}              
      
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
	       for (int i=2;i>-1;i--){
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
	       for (int i=2;i>-1;i--){
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
	       for (int i=2;i>-1;i--){
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
	       for (int i=2;i>-1;i--){
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
       if (canconnect(next,lst,present,status,used,seq)){
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

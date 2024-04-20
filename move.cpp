#include <ncurses.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

bool canconnect(int next, vector< vector<int> > lst, coord present,coord previous){
 if (present.first == previous.first)
   // cant work cuz they lie on same line
   return false;
  else {
      string seq="1234321234321234";
      if ( lst[present.first][present.second] == seq[next] )
        return true;
      else {
      //say cant cuz this isnt the next number
      return false;
      }
  }
}


void move (vector<coord> &used, coord &present,int &next, vector< vector<int> > lst) {       /////UNDONE!!, FILL IN THE ARGUMENTS
 initscr();
 keypad(stdscr,TRUE);
 coord previous=present;

 input=getch();
   if (input==KEY_RIGHT){
     
      if(present.first==1)
         break; // or show "u cant move like that"
      if (present.first==3){
        if findcoord({1,present.second},used)
	  /// this point is used alr! u cant move like this
	 else 
           present.first=1;
	 break;
      }
        int n=present.second;
         while (n<3){
	 if (!findcoord({present.first,n+1},used)){
	 present.second=n+1;
	 break;}
	 else n+=1;
         }
	 if (present.first==0){
            for (int i=0;i<4;i++) {
             if (!findcoord({1,i},used)){
                present.first=1;
	        present.second=i;
	        break;
	     }
	    }
	  }
	else {           //when present.first==2
           for (int i=3;i>=0;i--){
              if (!findcoord({1,i},used)){
	      present.first=1;
	      present.second=i;
	      break;
	      } 
	   }
	}
	///the whole line is used -> error
	break; //what to do? or print "u cant move like that"
      }
  

   else if (input==KEY_LEFT){

        if(present.first==3)
         break; // or show "u cant move like that"
        if (present.first==1){
          if findcoord({3,present.second},used)
	     /// this point is used alr! u cant move like this
	  else 
             present.first=3;
	  break;
        }
         int n=present.second;
         while (n>0){
	 if (!findcoord({present.first,n-1},used)){
	 present.second=n-1;
	 break;}
	 else n-=1;
         }
	 if (present.first==0){
            for (int i=0;i<4;i++) {
             if (!findcoord({3,i},used)){
                present.first=3;
	        present.second=i;
	        break;
	     }
	    }
	  }
	else {           //when present.first==2
           for (int i=3;i>=0;i--){
              if (!findcoord({3,i},used)){
	      present.first=3;
	      present.second=i;
	      break;
	      }
	   }
	}
	///the whole line is used -> error
	break; //what to do? or print "u cant move like that"

   }



   else if (input==KEY_UP){

        if(present.first==0)
         break; // or show "u cant move like that"
      if (present.first==2){
        if findcoord({0,present.second},used)
	  /// this point is used alr! u cant move like this
	 else 
           present.first=0;
	 break;
      }
        int n=present.second;
         while (n>0){
	 if (!findcoord({present.first,n-1},used)){
	 present.second=n-1;
	 break;}
	 else n-=1;
         }

	 if (present.first==3){
            for (int i=0;i<4;i++) {
             if (!findcoord({0,i},used)){
                present.first=0;
	        present.second=i;
	        break;
	     }
	    }
	  }
	else {           //when present.first==1
           for (int i=3;i>=0;i--){
              if (!findcoord({0,i},used)){
	      present.first=0;
	      present.second=i;
	      break;
	      } 
	   }
	}
	///the whole line is used -> error
	break; //what to do? or print "u cant move like that"
   }

   else if (input==KEY_DOWN){
        
	 if(present.first==2)
           break; // or show "u cant move like that"
         if (present.first==0){
         if findcoord({2,present.second},used)
	  /// this point is used alr! u cant move like this
	 else
           present.first=2;
	 break;
      }
        int n=present.second;
         while (n<3){
	 if (!findcoord({present.first,n+1},used)){
	 present.second=n+1;
	 break;}
	 else n+=1;
         }

	 if (present.first==3){
            for (int i=0;i<4;i++) {
             if (!findcoord({2,i},used)){
                present.first=2;
	        present.second=i;
	        break;
	     }
	    }
	  }
	else {           //when present.first==1
           for (int i=3;i>=0;i--){
              if (!findcoord({2,i},used)){
	      present.first=2;
	      present.second=i;
	      break;
	      }
	   }
	}
	///the whole line is used -> error
	break; //what to do? or print "u cant move like that"
   }

   else if (input== 10){  //input=enter
      //create a previous point,so if present and previous lie on same line-> dont allow
       if canconnect(next,lst,present,previous){
         used.push_back(present);
	 next+=1;
       }
        else {
           ///cant connect
	}
	break;
	}

   else if (input==81 || input==113)   //input='Q' or 'q' ->quit


   else     //input= sth else-> error, retype


  }

    endwin();  // End ncurses
    return 0;
}

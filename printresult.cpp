#include <iostream>
#include <stdlib.h>
#include "printresult.h"
#include "getch.h"
using namespace std;

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
   cout<<endl<<endl<<endl<<endl<<endl;
   cout<<"     "<<"######################################"<<endl;
   cout<<"     "<<"#"<<"                                    "<<"#"<<endl;
   cout<<"     "<<"#"<<"   L       OOOOO   SSSSS    EEEEE   "<<"#"<<endl;
   cout<<"     "<<"#"<<"   L       O   O   S        E       "<<"#"<<endl;
   cout<<"     "<<"#"<<"   L       O   O   S        E       "<<"#"<<endl;
   cout<<"     "<<"#"<<"   L       O   O   SSSSS    EEEEE   "<<"#"<<endl;
   cout<<"     "<<"#"<<"   L       O   O       S    E       "<<"#"<<endl;
   cout<<"     "<<"#"<<"   L       O   O       S    E       "<<"#"<<endl;
   cout<<"     "<<"#"<<"   LLLLL   OOOOO   SSSSS    EEEEE   "<<"#"<<endl;
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


#ifndef AXSML_H_INCLUDED
#define AXSML_H_INCLUDED
/*
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <unistd.h>
#include <string>
#include <cstring>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <errno.h>
#include <iostream>
*/
#define AXSMZd    729
#define AXSMZi    729

#define MAX_RETRIES 10

union semun {

};

int AXSMIDd;
char *AXSHMd;
char *AXSMSd;

int AXSMIDi;
char *AXSHMi;
char *AXSMSi;



char AXSM [729];

int ISMD (){
// INITIALIZE SHARED MEMORY INPUT






return AXSMIDd;
// END INITIALIZE SHARED MEMORY INPUT

}

int ISMI (){
// INITIALIZE SHARED MEMORY INPUT


return AXSMIDi;
// END INITIALIZE SHARED MEMORY INPUT

}

int ISE (){


return 2;
//END INITIALIZE SEMAPHORES
}

char *RSMI(int siid, int seid){

return AXSM ;
}

char *RSMD(int sdid, int seid){


return AXSM ;
}

void WSMI(char data[729],int siid, int seid){

        

//END AXIS SHARED  WRITE
}

void WSMD(char data[729],int sdid, int seid){


//END AXIS SHARED  WRITE
}

int DSM (){
	return 1;
}

int DSE (){
	return 1;
}


#endif // AXSML_H_INCLUDED

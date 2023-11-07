#include "stdio.h"
#include "stdlib.h"
#include "./../Data/Retireds.h"
#if !defined(_OPTION_)
#define _OPTION_

enum {
    QUIT ,
    PUSH , 
    REMOVE  , 
    CHANGE  
    
} ; 


#endif // _OPTION_



void PrintOption(  ) ;
int GetOption(int * option) ; 


void UI_PUSH(PGconn * conn) ; 
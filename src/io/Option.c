#include"Option.h" 
#include".\..\Data\Retireds.h" 



void PrintOption(  ) {

    puts("THE OPTION YOU HAVE ARE "); 
    printf("\t-%d-  QUIT " , QUIT ); 
    printf("\t-%d-  PUSH " , PUSH ); 
    printf("\t-%d-  REMOVE " , REMOVE ); 
    printf("\t-%d-  CHANGE " , CHANGE ); 
    printf(">> " );
  

}

int GetOption(int * option) {
    PrintOption(); 
    scanf("%d", option);
    return option ;
} 
void UI_PUSH(PGconn * conn ) {
    Retired   retired ; 
    ScanRetired(&retired); 
    puts("THEIS IS YOUR RETIRED");
} 
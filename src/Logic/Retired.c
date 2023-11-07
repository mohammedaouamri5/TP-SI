#include "Retired.h"
#include "Person.h"
#include ".\..\Logic\Calculate.h"
#ifndef min
#define min(a,b) (((a) < (b)) ? (a) : (b))
#endif 
void PrintRetired(Retired *retired, const char *fmt)
{

    PrintPerson(&retired->person, " \n");
    SPMMPrintArray(retired->spmm, 5);
    printf("Money tha he gets: %f\n", retired->Money);
    printf("Number Dossier: %f\n", retired->ID);
    printf(fmt);
}
int ErrorOfTyping()
{
    int error ; 
    printf("Dose the error just typing problem. (0 for no anything for yes ) \n\t>>> ");
    scanf("%d", &error);
    return error;
}
int PersonTestForRetired(Person*  person  )
{
    if (person->age < (60 - ( !person->gender * (5 + min( person->NumberOfKids , 3) ))))
    {
         
        printf(" [ Error ] : the age not in the requered age to retired  \n " );
        int error = ErrorOfTyping() ;
        return error;
    }else if( 15 > person->yearofwork   ) {  

        printf(" [ Error ] : becaus of thelower {");
        // printf(person->name);
        printf(" } is not in the requered age to retired \n  \n ");


        int error = ErrorOfTyping() ;
        return error;
    }

    return 0;
}
void ScanRetired(Retired *retired)
{

    do
    {

        ScanPerson(&retired->person );


        retired->CanGetMoney = PersonTestForRetired(&retired->person);
    } while (retired->CanGetMoney);
     SPMM_array_scan(retired->spmm, 5);
    retired->ID = -1; 
    retired->CanGetMoney = 1 ; 
    printf("Number Dossier: %d\n", retired->ID);
    Calculate(retired); 
    printf("Money tha he gets: %f\n", retired->Money);
}
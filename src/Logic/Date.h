



#pragma once 


typedef struct Date {
    int year;
    int month;
    int day;
} Date;
 
// ?  testting the input

short DateTest(Date *date)  ; 
void PrintData(Date * date,  const char * __Forme) ;  
void ScanData(Date * date ) ;  

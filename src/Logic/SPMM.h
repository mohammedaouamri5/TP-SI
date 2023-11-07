#pragma once

#include <stdio.h>


typedef struct SPMM
{
    float AverageSalaries;
    unsigned short Year;
} SPMM;
 
#ifndef N_SPMM_
#define N_SPMM_ 5
#endif
  

float CalculateSPMM(SPMM spmm[] );  
void SPMM_array_scan(SPMM spmm[], const int size) ; 
int SPMMTestTheYear(unsigned short Year , SPMM spmm[], const int size ); 
int SPMMTestTheAverageSalaries(float AverageSalaries ); 
void SPMMPrintArray(SPMM spmm[] , size_t size ) ;
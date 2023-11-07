#include "SPMM.h"

void SPMM_array_scan(SPMM spmm[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        do
        {
            printf("Give me the AverageSalaries of Year %d: ", i + 1);
            scanf("%f", &spmm[i].AverageSalaries);
        } while ( SPMMTestTheAverageSalaries(spmm[i].AverageSalaries) );
        do
        {
            printf("What's the Year : ");
            scanf("%d", &spmm[i].Year);
        } while (SPMMTestTheYear(spmm[i].Year, spmm, i));
    }
}

int SPMMTestTheAverageSalaries(float AverageSalaries)
{
    if (AverageSalaries <= 0)
    {
        printf(" [ERROR]  :  Average Salaries should not be less or equal than 0 :\n");
        return 1;
    }
    return 0; 
}

int SPMMTestTheYear(unsigned short Year, SPMM spmm[], const int size)
{
    for (size_t i = 0; i < size; i++)
        if (Year == spmm[i].Year)
        {
            printf(" [ERROR]  :  you alrady make it  :\n");
            return 1;
        }

    // | TODO : test if the yere befor hes even start working of even born

    // & TODO : make this with the time API
    if (Year > 2023)
    {
        printf(" [ERROR]  :  Year > 2023 :\n");
        return 1;
    }
    return 0;
}

void SPMMPrintArray(SPMM spmm[] , size_t size ) {
    printf("SPMM : \n"); 
    for (size_t i = 0; i < size; i++)
        printf("\tin %d get %f \n" , spmm[i].Year , spmm[i].AverageSalaries) ; 
    
}

float CalculateSPMM(SPMM spmm[] ){
    float sum = 0.0f  ; 
    for (size_t i = 0; i < N_SPMM_; i++)
        sum += spmm[i].AverageSalaries ;
    return sum / N_SPMM_;
}
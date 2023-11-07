#pragma once
 
#include "Person.h"
#include "SPMM.h"

typedef struct Retired
{
	
	SPMM spmm[N_SPMM_];
	short YearOfWork;
	float Money;
	int ID;
	int CanGetMoney;
	Person person;

} Retired;

void PrintRetired(Retired *This, const char *fmt);
void ScanRetired(Retired *This);
int PersonTestForRetired(Person *person );
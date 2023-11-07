#pragma once
#include "Retired.h"
#include "stdlib.h"

#ifndef SNMG
#define SNMG 20000.0f
#endif
#ifndef CanntGetMoney
#define CanntGetMoney 0x0001
#endif

float MIN(float x, float y);
float MAX(float x, float y);
float IRG(float AverageSalaries);
float Normalize(float AverageSalaries);
void Calculate(Retired *retired);
float AS(float AverageSalaries);
float CalculateYearOfWork(short Calculate);
float CalculateMajorationConjoint(Person person);
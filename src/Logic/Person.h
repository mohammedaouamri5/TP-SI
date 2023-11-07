#pragma once
#include "Date.h"

typedef struct Person
{
    int age;
    int yearofwork;
    int gender; // 0 for female any thing for male
    Date Birthday;
    int Mired;
    int NumberOfKids;
    int ThePartnerHaveJob;
    char   name[200] ;

} Person;
void PrintPerson(Person *person, const char *fmt);
void ScanPerson(Person *person);
int TestPerson(Person *person);



 
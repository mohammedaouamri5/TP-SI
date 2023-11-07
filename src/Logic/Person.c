#include "Person.h"
#include <stdio.h>

void PrintPerson(Person *person, const char *fmt)
{
    printf("name :  %s\n", person->name);

    printf("age :  %d\n", person->age);

    printf("Years of work :  %d\n", person->yearofwork);

    printf("Number Of Kids : %d\n", person->gender);

    if (person->Mired)
        printf("the Partner Have Job : %d\n", person->ThePartnerHaveJob);

    if (person->gender)
        puts("Gender : Male");
    else
        puts("Gender : Female");

    PrintData(&(person->Birthday), "\n");

    printf(fmt);

    return;
}

int TestPerson(Person *person)
{

    // ! returns 1 <=> Error
    // * returns 0 <=> OK
    if (person->age <= 0)
    {
        puts(" [ Error ] : it's imposable for the age to be ( age <= 0) ");
        return 1;
    }
    else if (person->NumberOfKids <= 0)
    {
        puts(" [ Error ] : it's imposable for the Number Of Kids to be ( Number Of Kids <= 0) ");
        return 1;
    }
    
    return 0;

}

void ScanPerson(Person *person)
{
    do
    {
        printf("name : "); !
        scanf("%s", &(person->name));
        
        
        // person->name[0] = 'D';
        // person->name[1] = 'e';
        // person->name[2] = 'f';
        // person->name[3] = 'u';
        // person->name[4] = 'a';
        // person->name[4] = 'l';
        // person->name[4] = 't';
 
        
        printf("age : ");
        scanf_s("%d", &(person->age));

        printf("Years of work :   ");
        scanf("%d", &person->yearofwork);

        printf("Gender :  are Male (0 for no any thing for yes) : ");
        scanf("%d", &person->gender);

        printf("Number Of Kids : ");
        scanf("%d", &person->NumberOfKids);

        printf("Mired :   are Mired (0 for no any thing for yes) : ");
        scanf("%d", &person->Mired);

        if (person->Mired)
        {
            printf("the Partner Have Job : ");
            scanf("%d", &person->ThePartnerHaveJob);
        }

        ScanData(&person->Birthday);

    } while (TestPerson(person));
}
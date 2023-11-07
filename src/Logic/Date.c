
#include "Date.h"

short DateTest(Date *date)
{

    // ! returns 1 <=> Error
    // * returns 0 <=> OK

    
    static const int _30[4] = {4, 6, 9, 11};


    if (date->month > 12 || date->month < 0)
    {
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1;31m! the month is wrong  we dont have a month number %d\033[0m", date->month);
        return 1;
    }


    if (date->day > 31 || date->day < 0)
    {
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1;31m! the day is wrong  we dont have a day number %d\033[0m", date->day);
        return 1;
    }

    if (date->year < 0)
    {
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1;31m! the day is wrong  we dont have a year number %d\033[0m", date->year);
        return 1;
    }
    if (date->month == 2 &&
     (date->day > 28 + (date->year % 4 == 0 && (date->year % 100 != 0 || date->year % 400 == 0))) 
    )
    {
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1A\033[2K");
        printf("\033[1;31m! the day is wrong  we dont have a day number %d in feb%d  \033[0m", date->day, date->year);
        return 1;

        // printf("\033[1;31m! the day is wrong  we dont have a day number %d in feb%d\033[0m",
        //        date->day, date->year);
        // return 1;
    }
    for (int i = 0; i < 4; i++)
    {
        if (date->month == _30[i] && date->day == 31)
        {
            printf("\033[1A\033[2K");
            printf("\033[1A\033[2K");
            printf("\033[1A\033[2K");
            printf("\033[1A\033[2K");
            printf("\033[1;31m! the day is wrong  we dont have 31 in %d\033[0m", date->month);
            return 1;
        }
    }
    return 0;
}

void PrintData(Date *date, const char *__Forme)
{
    printf("{%02d , %d , %d }", date->year, date->month, date->day);
    printf(__Forme);
}
void ScanData(Date * date )  
{
    do
    {
        printf("Give Me Date :\n");
        printf("\tGive Me AAAA :");
        scanf("%d", &(*date).year);
        printf("\tGive Me MM :");
        scanf("%d", &(*date).month);
        printf("\tGive Me JJ :");
        scanf("%d", &(*date).day);

    } while (DateTest(date));
    
    
}
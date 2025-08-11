/* Exercise 5-9. Rewrite the routines day_of_year and month_day with pointers instead of indexing.*/
#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
int main() 
{
    int dayOfYear, month, day;
  
    dayOfYear = day_of_year(2024,4,12);
    
    printf("\nDay of year is: %d\n",dayOfYear);
    month_day(2024,dayOfYear,&month,&day);

    return 0;
}


static char daytab[2][13] = 
{
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

/* day_of_year:  set day of year from month & day */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; i < month; i++)
        //day += daytab[leap][i]; commenting out the original K & R code
        day += *(*(daytab + leap) + i);
        //printf("\nDay is %d",*(*(daytab + leap) + i));
  
        /* Note that:
        Because we are dealing with 2D arrays, daytab[leap] is equivalent to *(daytab + leap)
        which is a pointer to the address of daytab[leap],
        in this case the address of the 0th element.
        To point to the next address of the same string constant,
        we must increment; i.e (daytab[leap] + i) OR *(daytab + leap) + i.
        And to see the content of that address, then we must dereference it.
        This would be *(daytab[leap]+i) OR *(*(daytab + leap) + i)
        */
  
    return day;
}

/* month_day:  set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > *(daytab[leap] + i); i++)
        //yearday -= (daytab[leap][i]); commenting out the original K & R code
        yearday -= *(*(daytab + leap) + i);
    *pmonth = i;
    *pday = yearday;
    printf("While date is: %d-%d-%d\n",*pday,*pmonth,year);
}

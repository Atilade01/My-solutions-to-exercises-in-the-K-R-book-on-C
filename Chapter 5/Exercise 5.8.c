/*  Exercise 5-8. There is no error checking in day_of_year or month_day. Remedy this defect.  */
#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);
int main() 
{
    int dayOfYear, month, day;
  
    dayOfYear = day_of_year(2024,4,12);

    /* We are intentionally leaving the printf() function below as is 
    without checking the returned value(s) from the called function -– day_of_year().
    In your own code, please check the returned value and act accordingly! */
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
    if( 0 < month && month <= 12)
    {
        if(0 < day && day <= 31)
        {
            int i, leap;
            leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
            for (i = 1; i < month; i++)
                day += daytab[leap][i];
            return day;
        }
        else
        { 
            printf("ERROR: Day cannot be %d", day);
            return -1;
        }
    }
    else 
    { 
        printf("ERROR: Month cannot be %d", month);
        return -1;
    }
    
}

/* month_day:  set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
  if( 0 < yearday && yearday <= 366)
  {
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
    for (i = 1; yearday > *(daytab[leap] + i); i++)
        yearday -= (daytab[leap][i]);
    *pmonth = i;
    *pday = yearday;
    printf("While date is: %d-%d-%d\n",*pday,*pmonth,year);
  }
  else 
    { 
        printf("ERROR: year day cannot be %d", yearday);
        return;
    }
}

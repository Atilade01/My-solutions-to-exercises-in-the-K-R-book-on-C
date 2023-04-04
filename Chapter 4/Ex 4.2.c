/* QUESTION: Extend atof to handle scientific notation of the form 123.45e-6 
where a floating-point number may be followed by e or E and an optionally signed exponent. */

#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define MAXLINE 100

/* atof: function to convert string s to double */
double atof(char s[])
{
    double val, power;
    int i, sign;
    double powerOfTen = 1.0;
    for (i = 0; isspace(s[i]); i++)  /* skip white space */
    ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        {i++;}
    for (val = 0.0; isdigit(s[i]); i++)
        {val = 10.0 * val + (s[i] - '0');}
    if (s[i] == '.')
        {i++;}
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10; 
    }
  // BEGIN extension
    if((s[i]=='E' || s[i]=='e'))
    {
        i++;
        if(s[i] == '-')
        {
            i++;
            for(int j=0; j< (s[i]-'0'); j++)
            {powerOfTen = powerOfTen/10;}
        }
        else
            powerOfTen = pow(10.0,(s[i]-'0'));
    }
    printf("The string in floating point notation is ");
  // END extension
    return (sign * val / power)*powerOfTen;
   }
   
int getline(char s[],int lim)
{
    int c, i;
    for (i=0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        {s[i] = c;}
    if (c == '\n') 
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

int main()
{
    double sum, atof(char []);
    char line[MAXLINE];
    int getline(char line[], int max);
    sum = 0;
    while (getline(line, MAXLINE) > 0)
        { printf("\t%g\n", sum += atof(line));}
    return 0;
}

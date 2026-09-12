/* 
    Exercise 5-2. Write getfloat, the floating-point analog of getint. What type does getfloat return as its function value?
    getfloat() will also return an int. 
*/

#include <stdio.h>
#include <ctype.h>
#include <math.h>

int getfloat(double *);
double power(double base, int n);
int main() 
{
    // Write C code here
    double a;
    printf("The returned value is: %d",getfloat(&a));

    return 0;
}

#define BUFSIZE 100
char buf[BUFSIZE];    // buffer for ungetch
int bufp = 0;         // next free position in buf
int getch(void)  // get a (possibly pushed-back) character
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)   // push character back on input
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

/* power: raise base to n-th power; n >= 0 */
double power(double base, int n)
{ 
    int i;
    double p;
    p = 1;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}

/* getfloat:  get next integer from input into *pn */
int getfloat(double *pn)
{
    int c, count;
    double sign;
    count = 0;
    while (isspace(c = getch()))   /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.')
    {
        ungetch(c);  /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1.0 : 1.0;
    if (c == '+' || c == '-')
    {
        c = getch();
        if(!isdigit(c) && c != '.')
        {
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0.0; isdigit(c); c = getch())
    {
        *pn = 10.0 * *pn + (c - '0');
    }
    if (c != EOF)
    {
        if(c == '.')
        {
            c = getch();
            if(isdigit(c))
            {
                for (*pn = *pn; isdigit(c; c = getch())
                {
                    *pn = 10.0 * *pn + (c - '0');
                    count++;
                }
            }
            else
            {
                ungetch(c);
                return 0;
            }
        }
        else return 0;
    }
    double val = power(10.0, count); //Here, we're assuming the standard library does not provide a pow() function.
    *pn /= val;
    *pn *= sign;

    return c;
}

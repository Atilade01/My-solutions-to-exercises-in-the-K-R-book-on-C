#include <stdio.h>
#include <ctype.h>

int getint(int *);
int main() 
{
    // Write C code here
    int a = 0;
    printf("The value is: %d ",getint(&a));
    printf("\nFinally,the value of a is set to: %d ",a);

    return 0;
}

/* getint:  get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getchar()))   /* skip white space */
        ;
    printf("Begin, c is: %d\n",c);
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetc(c,stdin);  /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getchar();
        if(!isdigit(c))
        {
            printf("In if() func, c is: %d\n",c);
            ungetc(c,stdin);
            return 0;
        }
    }
    for (*pn = 0;isdigit(c); c = getchar())
    {
        printf("In for() loop, c is: %d\n",c);
        *pn = 10 * *pn + (c - '0');
        printf("In for() loop, pn is: %d\n",*pn);
    }
    *pn *= sign;
    if (c != EOF)
    {
        printf("We have not reached EOF\n");
        ungetc(c,stdin);
    }
    else
    {
        printf("We have reached EOF\n");
    }
    return c;
}

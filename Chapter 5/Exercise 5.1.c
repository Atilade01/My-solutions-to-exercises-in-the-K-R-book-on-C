/*
I have written the code below in two forms. The first uses the same functions (getch() and ungetch() )in the K & R  book.
These functions are provided as part of the conio.h library. They are not provided in stdio.h. Hence, they are not portable.
The second uses the stdio functions getchar() and ungetc(). Note that we could also use getc(FILE *) instead of getchar()
*/

/* VERSION 1 */
#include <stdio.h>
#include <ctype.h>

int getint(int *);
int main() 
{
    // Write C code here
    int a;
    printf("The value is: %d ",getint(&a));
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

/* getint:  get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))   /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);  /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getch();
        if(!isdigit(c) || c != EOF)  /* if c is neither a digit nor the end of file, then send it back to input */
        {
            ungetch(c);
            return 0;
        }
    }
    for (*pn = 0;isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}



/* VERSION 2 */
#include <stdio.h>
#include <ctype.h>

int getint(int *);
int main() 
{
    // Write C code here
    int a;
    return 0;
}

/* getint:  get next integer from input into *pn */
int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getchar()))   /* skip white space */
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetc(c,stdin);  /* it is not a number */
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        c = getchar(); // the above could also be written as c = getc(stdin)
        if(!isdigit(c) || c != EOF)  /* if c is neither a digit nor the end of file, then send it back to input */
        {
            ungetc(c,stdin);
            return 0;
        }
    }
    for (*pn = 0;isdigit(c); c = getchar())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF)
    {
        ungetc(c,stdin);
    }
    return c;
}

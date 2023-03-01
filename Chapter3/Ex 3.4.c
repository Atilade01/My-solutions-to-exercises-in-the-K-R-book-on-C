/* QUESTION– In a two's complement number representation, our version of itoa does not handle the largest negative number;
that is, the value of n equal to -(2wordsize-1). 
Explain why not. Modify it to print that value correctly, regardless of the machine on which it runs.

<b> WHY NOT? </b>
In my opinion, this is because n was not declared to be an int large enough to hold values in both limits.
By limits I mean largest negative number and largest nonnegative number in a 2's complement system.
Thus, rather than use a 'short int' datatype, we would prefer to declare our variable 'n' using a 'long int'.

In my solution below, I declare the variable n as a long int.
*/


#include <stdio.h>
#include <string.h>

void itoa(long n, char s[]);
void reverse(char[]);

/* itoa: convert n to characters in s */
int main() 
{
    char s2[1000];
    long n;
    printf("\nPlease input the integers to convert\n");
    scanf("%ld",&n);
    printf("\n The n you entered is %ld\n", n);
    printf("\nThe integers to characters is \n");
    itoa(n,s2);

    return 0;
}
/* reverse:  reverse string s in place */
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
    printf("%s\n", s);
}


/* itoa: convert n to character in s */
void itoa(long n, char s[])
{
    int i, sign;
    if((sign = n)<0)
    n=-n;
    i = 0;
    do {
        s[i++] = (n % 10) + '0';
    } while ((n /= 10) != 0);

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

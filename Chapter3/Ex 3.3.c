//Please note that this code is still a work-in-progress, and updates/ deletions will definitely be made



#include <stdio.h>
#define MAXLETTER 26
#define MAXNUMBER 10

char alphaOne[MAXLETTER] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char alphaTwo[MAXLETTER] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
char numbers [MAXNUMBER] = {'0','1','2','3','4','5','6','7','8','9'};

void expand(char s1[], char s2[]);

int main() 
{
    char s1[MAXLETTER];
    char s2[MAXLETTER];
    int i;
    printf("Please enter a string of characters in shorthand form e.g a-f \n");
    scanf("%s",s1);
    printf("You entered %s\n", s1);
    expand(s1,s2);
    return 0;
}

void expand(char s1[], char s2[])
{
    int i,j,k,l,p,q,r,s;
    char m,n;
    char c;
    for (i=0,j=0; s1[i]!= '\0'; i++)
    {
        if ((s1[i] == '-') || (s1[i++] == '-'))
        break;
        else
        s2[j++] = s1[--i];
    }
    printf("i is %d\n",i);
    if (s1[i] == '-')
    {
        if(i != 0)
        {
            m = s1[--i];
            i++;
            n = s1[++i];
        }
        else
        {
            m = s1[++i];
            i++;
            n = s1[++i];
        }
        k=l=r=0;
        while(m != alphaOne[k] && m != alphaTwo[k] && m != numbers[k])
        {
            k++;
        }
        while(n != alphaOne[l] && n != alphaTwo[l] && n != numbers[l])
        {
            l++;
        }
        printf("m is %c and n is %c\n",m,n);
        printf("k is %d and l is %d\n",k,l);
        if(k<l)
        {
        for(p=k; p <= l; p++)
        {
            if(m == alphaOne[k] && n == alphaOne[l])
            {
                s2[r++] = alphaOne[p];
            }
            else if(m == alphaTwo[k] && n == alphaTwo[l])
            {
                s2[r++] = alphaTwo[p];
            }
            else if(m == numbers[k] && n == numbers[l])
            {
                s2[r++] = numbers[p];
            }
            else 
            {
                printf("Invalid combination of characters!");
                return;
            }
        }
            
        }
        else 
            {
                printf("Invalid combination of characters!");
                return;
            }
    }
    printf("The string above expands to ==> %s",s2);
}

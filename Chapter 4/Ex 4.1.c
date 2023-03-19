#include <stdio.h>
#include <string.h>
int strindex( char s[], char t[]);
int main() 
{
    char s[] = "It should not matter whether or not she could have done it. The truth is she wouldn't do it";
    char t[] = "ould";
    if(strindex(s,t) > 0)
    printf("The rightmost occurence of the string 'OULD' is at position %d", strindex(s,t));
    else
    printf("The string 'OULD' does not appear in string S");

    return 0;
}

int strindex(char s[], char t[])
{
int i, j, k, l=0;
    for (i = 0; s[i] != '\0'; i++) 
    {
        for (j=i, k=0; s[j]==t[k] && t[k] != '\0'; j++, k++)
        {;}
        if (k>0 && t[k] == '\0')
        { l = i; }
    }
    if (l > 0)
    { return l; }
    else
    return -1; 
}

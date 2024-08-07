/* Exercise 5-6. Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing. 
 * Good possibilities include getline (Chapters 1 and 4), atoi, itoa, and their variants (Chapters 2, 3, and 4), 
 * reverse (Chapter 3), and strindex and getop (Chapter 4).
 */

#include <stdio.h>
#define MAXLINE 1000   /* maximum input line length */
int getLine(char *s, int maxline);

int main()
{
    int len;
    char line[MAXLINE];
    len = getLine(line, MAXLINE);
    printf("%d\n", len);
    return 0;
}
/* getline:  read a line into s, return length  */
int getLine(char *s, int maxline)
{
    int c, i;
    for (i=0; i < maxline-1 && (c=getchar())!=EOF && c!='\n'; i++)
           *(s+i) = c;
    if (c == '\n') 
    {
        *(s+i) = c;
        i++;
    }
    *(s+i) = '\0';
    return i;
}

/*
 * Exercise 5-3. Write a pointer version of the function strcat
 * that we showed in Chapter 2.
 * strcat(s,t) copies the string t to the end of s.
*/

/* Below, I show two ways to write strcat. I used different names
 * for strcat. They are sstrcat and _strcat_. I do this so that they don't clash
 * with libray names. The _strcat_ version is better to use */

void sstrcat(char* s, char* t);
void _strcat_(char* s, char* t);

int main()
{
    char a[50] = "My name";
    char b[] = "is Khan";
    _strcat_(a,b);
    //sstrcat(a,b);
    printf("The concatenated string is: %s\n",a);
}

/* In this case, we read beyond the null character and push the pointer back by a character */
void sstrcat(char* s, char* t)
{
    while(*s++ != '\0')
        ;
    if(*s == '\0')
    {
        s--; //pushing the pointer back
        *s++ = ' '; //I added a space so the 2 strings won't be muddled up
    }
    while((*s++ = *t++))
    {;}
}
/* OR */
/* Here we read the string s until a null character is reached. This prevents from reading beyond the null */
void _strcat_(char* s, char* t)
{
    while(*s != '\0')
        s++;
    if(*s == '\0')
        *s++ = ' ';
    while((*s++ = *t++))
    {;}
}

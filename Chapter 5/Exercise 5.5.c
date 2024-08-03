/*
 * Exercise 5-5. Write versions of the library functions:
 * strncpy, strncat, and strncmp,
 * which operate on at most the first n characters of their argument strings.
 * For example, strncpy(s,t,n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B.
 */
//function prototypes are written below:
int strncopy(char* s, char* t, int n);
int strn_cat(char* s, char* t, int n); 
int strn_cmp(char* s, char* t, int n);
int main()
{
  //for strncpy()
    char c[50];
    char d[50] = "Battle of the bastards!!";
    if(strncopy(c,d,6))
        printf("String successfully copied!\n");
    else
        printf("\nString copying failed!\n");
    printf("string C is: %s\n",c);

  //for strncat()
    char a[100] = "It is beautiful beneath the sea but if you stay too long you will drown...";
    char b[] = "The 3-eyed raven";
    if(strn_cat(a,b,16))
        printf("String successfully concatenated!\n");
    else
        printf("\nString concatenation failed!\n");
    printf("The concatenated string is: %s\n",a);
//for strncmp()
  char e[] = "Billy the bull";
    char f[] = "Bill the bully";

    if(strn_cmp(e,f,14) > 0)
        printf("string E is greater than string F\n");
    else if(strn_cmp(e,f,14) < 0)
        printf("string E is less than string F\n");
    else
        printf("string E is equal to string F\n");
  
}

int strncopy(char* s, char* t, int n)
{
    int i;
    for(i = 0; i < n; i++)
    { *(s+i) = *(t+i);}; //I still don't understand why *s++ = *t++ doesn't work correctly
    if((*s = *t) && (i == n))
        return 1;
    else
        return 0;
}

int strn_cat(char* s, char* t, int n)
{
    int i = 0;
    while(*s != '\0')
    {
        s++;
        i++;
    }
    if(*s == '\0')
        *s = ' ';
    printf("i is: %d\n",i);
    if(strncopy(s,t,n)) //using the current address of s in our created strncopy function
        return 1;
    return 0; //else statement
    printf("string S is: %s\n",s);
}

int strn_cmp(char* s, char* t, int n) //compare 2 strings lexicographically  up until n
{
    int i;
    for(i=1; *s == *t ; s++,t++,i++)
        if((*s == '\0') || (i == n))
            return 0;
    return *s - *t;
}

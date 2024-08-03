/* Exercise 5-4. Write the function strend(s,t),
 * which returns 1 if the string t occurs at the end of the string s
 * and zero otherwise. */

int strend(char *s, char *t); //funtion prototype

int main()
{
    char c[50] = "Sizwe Bansi is dead";
    char d[50] = "is dead";
    if(strend(c,d))
        printf("The second string occurs at the end of the first\n");
    else
        printf("\nThe second string does not occur at the end of the first\n");
}

int strend(char *s, char *t)
{
    int j= 0;
    int count =0;
    while(*s != '\0') //move pointer to end of string
        s++;
    while(*t != '\0') //move pointer to end of string
    {
        t++;
        j++;
    }
    while(*s-- == *t--) //checking both strings from the end
        count++;
    if(count >= j) //count must equal length of string t or be greater than it by 1 more character which should be a space
        return 1;
    else
        return 0;
}

/* 
  Exercise 2-3. Write a function htoi(s),
  which converts a string of hexadecimal digits (including an optional 0x or 0X) into its equivalent integer value. 
  The allowable digits are 0 through 9, a through f, and A through F.

  The program below also include a main function to test the program
*/


int _htoi( char *s)
{
    int i,n;
    int j = 0;
    int k =0;
    i=0;
    if(s[i] == '0') //excluding optional '0' from hex
        i++;
    if(s[i] == 'x' || s[i] == 'X') //excluding optional 'x' or 'X' from hex
        i++;
    n = (strlen(s) - i); //setting 'n' as string length of string s
    for ( ;(s[i] != '\0') && s[i] != EOF; i++)
    {
        if(isalpha(s[i]))
        {
            if(s[i] == 'a' || s[i] == 'A')
                k= s[i] = 10;
            else if (s[i] == 'b' || s[i] == 'B')
                k = s[i] = 11;
            else if (s[i] == 'c' || s[i] == 'C')
                k = s[i] = 12;
            else if (s[i] == 'd' || s[i] == 'D')
                k = s[i] = 13;
            else if (s[i] == 'e' || s[i] == 'E')
                k = s[i] = 14;
            else if (s[i] == 'f' || s[i] == 'F')
                k = s[i] = 15;
            else printf("Invalid hex character %c \n", s[i]);
        }
        else
        { k = 10 * 0 + (s[i] - '0');}
        printf("the value of k is %d\n ",k);
        j = j + (k * pow(16,(n-1)));
        n--;
        printf("the value of j is %d\n ",j);
    }
    return j;
}

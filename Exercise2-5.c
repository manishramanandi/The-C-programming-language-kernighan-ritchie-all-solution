/* Write a function any(s1, s2) which the first location in the string s1 where any character from the string s2 occurs or -1 if s1 contains no characters from s2. (The standard library function strpbrk does the same job but return pointer to the location) */


int any(char s1[], char s2[])
{
        int i, j;

        for (i = 0; s1[i] != '\0'; i++)
              for (j = 0; s2[j] != '\0'; j++)
                  if (s1[i] == s2[j])  /* match founf */
                      return i;   /* location first match */
        return -1;                /* otherwise, no match */


}


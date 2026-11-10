#include <stdio.h>
#include <string.h>

int main()
{
    char s[105];

    // Read the input line, spaces included (up to 100 characters)
    if (scanf("%100[^\n]", s) != 1)
    {
        return 1;
    }

    s[strcspn(s, "\r\n")] = '\0'; // drop CR from Windows line endings

    int found = 1;

    // Each round removes every adjacent pair in one pass
    while (found)
    {
        int j = 0;
        found = 0;

        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == s[i + 1])
            {
                found = 1;
                i++; // skip both characters of the pair
            }
            else
            {
                s[j++] = s[i];
            }
        }
        s[j] = '\0';

        if (found)
        {
            printf("%s\n", s);
        }
    }

    return 0;
}

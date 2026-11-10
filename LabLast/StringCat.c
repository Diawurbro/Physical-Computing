#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main()
{
    char str[2005];
    char lower_str[2005];
 
    // Read the input string (up to 2000 characters)
    if (scanf("%[^\n]", str) == 1)
    {
        int len = strlen(str);
 
        // Create a lowercase version of the string for case-insensitive searching
        for (int i = 0; i < len; i++)
        {
            lower_str[i] = tolower((unsigned char)str[i]);
        }
        lower_str[len] = '\0';
 
        char *ptr = lower_str;
        int first = 1;
 
        // Use strstr to find all occurrences of "cat"
        while ((ptr = strstr(ptr, "cat")) != NULL)
        {
            // Calculate 1-based index based on pointer difference
            int index = (ptr - lower_str);
 
            if (!first)
            {
                printf(", ");
            }
            printf("%d", index);
            first = 0;
 
            // Move pointer forward to search for the next occurrence
            ptr++;
        }
        printf("\n");
    }
 
    return 0;
}
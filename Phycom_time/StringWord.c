#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main()
{
    char str[160];
    char words[100][160];
    int count = 0;
 
    // Read the input string
    if (scanf(" %[^\n]", str) == 1)
    {
 
        // Tokenize the string using spaces as delimiters
        char *token = strtok(str, " \t");
        while (token != NULL)
        {
            // Copy the token into our words array
            strcpy(words[count], token);
 
            // Convert the word to lowercase
            for (int i = 0; words[count][i] != '\0'; i++)
            {
                words[count][i] = tolower((unsigned char)words[count][i]);
            }
 
            count++;
            token = strtok(NULL, " \t");
        }
 
        // Print the final output according to the specification
        printf("%d words\n", count);
        printf("----\n");
        for (int i = 0; i < count; i++)
        {
            printf("%s : %d\n", words[i], (int)strlen(words[i]));
        }
    }
 
    return 0;
}
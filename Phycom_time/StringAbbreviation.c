#include <stdio.h>
 
int main()
{
    char firstname[205];
    char lastname[205];
 
    // Read the first and last name separated by space
    if (scanf("%s %s", firstname, lastname) == 2)
    {
        // Print the first character of each name followed by a dot
        printf("%c.%c.\n", firstname[0], lastname[0]);
    }
 
    return 0;
}
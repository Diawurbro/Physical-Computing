#include <stdio.h>
#include <string.h>
#include <ctype.h>
 
int main()
{
    char target;
    char str[155];
    int count = 0;
 
    // Read the target character
    scanf("%c", &target);
 
    // Consume the newline character left in the input buffer
    getchar();
 
    // Read the full sentence including spaces
    scanf("%[^\n]", str);
 
    // Convert target to lowercase for case-insensitive comparison
    target = tolower(target);
 
    // Loop through the string and count matches
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (tolower(str[i]) == target)
        {
            count++;
        }
    }
 
    // Print the final count
    printf("%d\n", count);
 
    return 0;
}
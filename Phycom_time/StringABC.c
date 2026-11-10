#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
// Comparison function for qsort to sort characters by ASCII value
int compare(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}
 
int main()
{
    char str[205];
 
    // Read the entire line including spaces
    if (scanf("%[^\n]", str) == 1)
    {
        int len = strlen(str);
 
        // Sort the string array in ascending order
        qsort(str, len, sizeof(char), compare);
 
        // Print the sorted string
        printf("%s\n", str);
    }
 
    return 0;
}
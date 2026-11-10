#include <stdio.h>
 
int main()
{
    char str[151];
    scanf(" %[^\n]", str);
 
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ' && str[i] != '\t')
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
 
    return 0;
}
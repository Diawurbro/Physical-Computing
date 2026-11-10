#include <stdio.h>
int main()
{
    char a[450];
    scanf("%[^.]", a);
    int i = 0;
    int word = 0;
    int line = 0;
    int character = 0;
    while (a[i] != '\0')
    {
        if (a[i] == ' ')
            word++;
        else if (a[i] == '\n')
        {
            line++;
            word++;
        }
        else if ((a[i] >= 'A' && a[i] <= 'Z') || (a[i] >= 'a' && a[i] <= 'z'))
            character++;
        i++;
    }
 
    printf("Char = %d, word = %d, line = %d", character, word, line);
}
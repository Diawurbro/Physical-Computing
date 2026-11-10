#include <stdio.h>
#include <string.h>
 
void print_centered(char *str, int width)
{
    int len = strlen(str);
    int total_spaces = width - 2 - len;
 
    // If the spaces cannot be divided equally (odd number),
    // shifting the text to the right by 1 means adding 1 extra space to the left.
    int left_spaces = (total_spaces + 1) / 2;
    int right_spaces = total_spaces / 2;
 
    printf("*");
    for (int i = 0; i < left_spaces; i++)
    {
        printf(" ");
    }
    printf("%s", str);
    for (int i = 0; i < right_spaces; i++)
    {
        printf(" ");
    }
    printf("*\n");
}
 
int main()
{
    int width;
    if (scanf("%d", &width) != 1)
        return 0;
 
    char s1[60];
    char s2[60];
 
    scanf(" %[^\n]", s1);
    scanf(" %[^\n]", s2);
 
    // Print top border
    for (int i = 0; i < width; i++)
    {
        printf("*");
    }
    printf("\n");
 
    // Print centered text lines
    print_centered(s1, width);
    print_centered(s2, width);
 
    // Print bottom border
    for (int i = 0; i < width; i++)
    {
        printf("*");
    }
    printf("\n");
 
    return 0;
}
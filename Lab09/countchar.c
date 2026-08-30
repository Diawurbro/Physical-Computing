#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    char *ptr;
    int lower = 0, upper = 0, digit = 0;

    str = (char *) malloc(101 * sizeof(char));

    scanf("%[^\n]s", str);

    ptr = str;
    while (*ptr != '\0') {
        if (*ptr >= 'a' && *ptr <= 'z')
            lower++;
        else if (*ptr >= 'A' && *ptr <= 'Z')
            upper++;
        else if (*ptr >= '0' && *ptr <= '9')
            digit++;
        ptr++;
    }

    printf("Lowercase letters: %d\n", lower);
    printf("Uppercase letters: %d\n", upper);
    printf("Digits: %d\n", digit);

    free(str);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    int len = 0;
    char *ptr;
    char *end;

    str = (char *) malloc(1000 * sizeof(char));

    scanf("%[^\n]s", str);

    ptr = str;
    while (*ptr != '\0') {
        len++;
        ptr++;
    }
    end = ptr - 1;

    while (end >= str) {
        printf("%c", *end);
        end--;
    }
    printf("\n");

    free(str);

    return 0;
}
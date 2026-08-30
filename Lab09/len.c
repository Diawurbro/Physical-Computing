#include <stdio.h>
#include <stdlib.h>

int main() {
    char *str;
    int len = 0;
    char *ptr;
    str = (char *) malloc(1000 * sizeof(char));

    scanf("%[^\n]s", str);
    ptr = str;
    while (*ptr != '\0') {
        len++;
        ptr++;
    }

    printf("%d\n", len);
    free(str);
    return 0;
}
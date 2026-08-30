#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    char *str;
    char *ptr;
    int count;

    scanf("%d", &n);
    scanf("%d", &m);
    str = (char *) malloc((n + 1) * sizeof(char));

    scanf(" %[^\n]s", str);

    ptr = str;
    count = 0;
    while (*ptr != '\0') {
        if (count % m == 0)
            putchar(*ptr);
        ptr++;
        count++;
    }
    putchar('\n');

    free(str);

    return 0;
}
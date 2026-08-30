#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char names[n][70];
    for (int i = 0; i < n; ++i) {
        scanf(" %[^\n]", names[i]);

        int newWord = 1;
        for (int j = 0; names[i][j] != '\0'; ++j) {
            if (names[i][j] == ' ') {
                newWord = 1;
            } else {
                if (newWord) {
                    if (names[i][j] >= 'a' && names[i][j] <= 'z')
                        names[i][j] -= 32;
                    newWord = 0;
                } else {
                    if (names[i][j] >= 'A' && names[i][j] <= 'Z')
                        names[i][j] += 32;
                }
            }
        }
    }

    char temp[70];
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }

    for (int i = 0; i < n; ++i)
        printf("%s\n", names[i]);

    return 0;
}
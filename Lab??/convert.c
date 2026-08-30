#include <stdio.h>
#include <string.h>

int main() {
    char a[110], b[110];
    scanf(" %[^\n]", a);
    scanf(" %[^\n]", b);

    int same = 1;
    if (strlen(a) != strlen(b)) same = 0;

    // สลับตัวพิมพ์ใหญ่-เล็ก
    for (int i = 0; a[i] != '\0'; ++i) {
        if (a[i] >= 'a' && a[i] <= 'z') a[i] -= 32;
        else if (a[i] >= 'A' && a[i] <= 'Z') a[i] += 32;
    }
    for (int i = 0; b[i] != '\0'; ++i) {
        if (b[i] >= 'a' && b[i] <= 'z') b[i] -= 32;
        else if (b[i] >= 'A' && b[i] <= 'Z') b[i] += 32;
    }

    // เปรียบเทียบแบบไม่สนตัวพิมพ์
    if (same) {
        for (int i = 0; a[i] != '\0'; ++i) {
            char x = a[i], y = b[i];
            if (x >= 'A' && x <= 'Z') x += 32;
            if (y >= 'A' && y <= 'Z') y += 32;
            if (x != y) { same = 0; break; }
        }
    }

    printf("*** Results ***\n");
    printf("%s\n", a);
    printf("%s\n", b);
    printf("***************\n");
    if (same)
        printf("Both strings are the same.\n");
    else
        printf("Both strings are not the same.\n");

    return 0;
}
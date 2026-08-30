#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long long a = 1, b = 1;
    for (int i = 2; i <= n; ++i) {
        long long c = a + b;
        a = b;
        b = c;
    }

    printf("method = %lld\n", b);
    return 0;
}
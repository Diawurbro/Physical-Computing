#include <stdio.h>
#include <math.h>

int main() {
    double theta, u;
    scanf("%lf", &theta);
    scanf("%lf", &u);

    double rad = (theta * 3.141592653589793) / 180;
    double s = sin(rad);
    double h = (u * u * s * s) / (2 * 9.81);

    printf("theta (degree) : %.0lf\n", theta);
    printf("u (m/s) : %.0lf\n", u);
    printf("h (m) : %.4lf\n", h);

    return 0;
}
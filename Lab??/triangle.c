#include <stdio.h>
#include <math.h>

double perimeter(double a, double b);
double area(double a, double b);

int main() {
    double a, b;
    scanf("%lf %lf", &a, &b);
    printf("Perimeter: %.2lf\n", perimeter(a, b));
    printf("Area: %.2lf\n", area(a, b));
    return 0;
}

double perimeter(double a, double b) {
    return a + b + sqrt(a * a + b * b);
}

double area(double a, double b) {
    return (a * b) / 2;
}
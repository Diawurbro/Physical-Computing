#include<stdio.h>
#include<math.h>
 
int main(){
    double x, y ,z;
    scanf(" %lf %lf", &x, &y);
    z = sqrt((x * x) + (y * y));
    printf("sqrt(%.0lf^2+%.0lf^2)=%.2lf", x, y, z);
    return 0;
}
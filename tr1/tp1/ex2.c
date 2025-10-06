#include <stdio.h>
#include <math.h>

main()
{
    int a, b, c, d;
    printf("donne a= ");
    scanf("%d", &a);
    printf("donne b= ");
    scanf("%d", &b);
    printf("donne c= ");
    scanf("%d", &c);
    printf("donne d= ");
    scanf("%d", &d);
    double res = (double)sqrt(pow(a - c, 2) + pow(b - d, 2));
    printf("res = %6.3f", res);
}

#include <stdio.h>
#include <math.h>

main()
{
    int a, b, c, delta;
    printf("donne a : ");
    scanf("%d", &a);
    printf("donne b : ");
    scanf("%d", &b);
    printf("donne c : ");
    scanf("%d", &c);
    delta = pow(b, 2) - (4 * a * c);
    if (delta < 0)
        printf("L equation n a pas solution reelle");
    else
    {
        if (delta == 0)
        {
            printf("l equation a une unique solution %2.2f", -b / 2 * a);
        }
        else
        {
            float x1 = -b - sqrt(delta) / (2 * a);
            float x2 = -b + sqrt(delta) / (2 * a);
            printf("l equation a deux solution distinctes x1=%2.2f x2=%2.2f ", x1, x2);
        }
    }
}

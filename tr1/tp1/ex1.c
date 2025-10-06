#include <stdio.h>
#include <stdlib.h>
#include <time.h>

main()
{
    int max = 50, min = 10;
    int a, b;
    printf("donne a = ");
    scanf("%d", &a);
    printf("donne b = ");
    scanf("%d", &b);
    if (a > b)
    {
        printf("a>b\n");
    }
    else
    {
        if (b < a)
        {
            printf("b>a\n");
        }
        else
        {
            printf("a=b\n");
        }
    }
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %f.2\n", a, b, (float)a / b);
    int c;
    srand(time(NULL));
    c = rand() % 51;
    c = min + rand() % (max - min + 1);
    printf("c = %d\n", c);
    printf("octal %o\n", c);
    printf("decimal %d\n", c);
    printf("hexadicimal %x\n", c);
    const double PI = 3.14;
}

#include <stdio.h>

main()
{
    printf("\n******************test1******************\n");
    int i;
    printf("donner un entier");
    scanf("%d", &i);
    int x;
    printf("donner un entier");
    scanf("%d", &x);
    for (i = 1, x = 0; i <= 8; i++, x += 1)
    {
        printf("x=%d,i=%d ", x, i);
    }
    printf("\n******************test2******************\n");
    for (i = 1; i <= 5; printf("encore un tour \n"), i++)
    {
    }
    printf("\n******************test3******************\n");
    printf("donner un entier");
    scanf("%d", &i);
    for (i = 1; i <= 100; i++)
        ;
    printf("%d\n", i);
    float s = 0;
    int i, j;
    for (i = 1, j = 2; i < 10; i++, j++)
    {
        s += i + j;
    }
    int n;
    do
    {
        printf("donner un entier");
        scanf("%d", &n);
    } while (n < 0);
    n = -9;
    while (n < 0)
    {
        printf("donner un entier");
        scanf("%d", &n);
        /* code */
    }
}

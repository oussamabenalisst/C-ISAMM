#include <stdio.h>

main()
{
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
    printf("test ******************\n");
    for (i = 1; i <= 5; printf("encore un tour \n"), i++)
    {
    }

}

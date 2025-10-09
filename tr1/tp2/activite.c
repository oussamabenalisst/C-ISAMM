#include <stdio.h>

int main()
{
    int n;
    int i, s;
    do
    {
        printf("donne n ");
        scanf("%d", &n);
    } while (n < 0);

    i = 1;
    s = 0;
    while (i <= n)
    {
        s += i;
        i += 1;
    }
    i = 1;
    int p;
    p = 1;
    do
    {
        p *= i;
        i += 1;
    } while (i <= n);

    printf("somme = %d\n", s);
    printf("pro = %d\n", p);
    printf("moy = %d \n", s / n);

    return 0;
}

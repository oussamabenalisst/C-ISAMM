#include <stdio.h>

int main()
{
    int a, j, m;
    do
    {
        printf("Donner un entier A (4 chiffres) : ");
        scanf("%d", &a);
    } while (a > 9999 || a < 1000);
    do
    {
        printf("Donner un entier J (1-31) : ");
        scanf("%d", &j);
    } while (j < 1 || j > 31);
    do
    {
        printf("Donner un entier M (1-12) : ");
        scanf("%d", &m);
    } while (m < 1 || m > 12);

    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
    {
        printf("Annee bissextile\n");
    }
    else
    {
        printf("Annee non bissextile\n");
    }

    printf("La date est : %02d/%02d/%04d\n", j, m, a);
    return 0;
}

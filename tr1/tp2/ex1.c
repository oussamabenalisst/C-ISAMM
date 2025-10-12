#include <stdio.h>
#include <locale.h>
int main()
{
    int a, b;
    printf("Donner un entier A \n");
    scanf("%d", &a);
    printf("Donner un entier B \n");
    scanf("%d", &b);
    if (a > b)
    {
        printf("----------1eme cas----------\n");
        setlocale(LC_CTYPE, "");
        printf("A = %d est superieur a B = %d\n", a, b);
    }
    else
    {
        if (a < b)
        {
            printf("----------2eme cas----------\n");
            setlocale(LC_CTYPE, "");
            printf("A = %d est inferieur a B = %d\n", a, b);
        }
        else
        {
            setlocale(LC_CTYPE, "");
            printf("----------3eme cas----------\n");
            printf("A = %d est egale a B = %d\n", a, b);
        }
    }
    //?e2 : if else done le cas ou il ye 2 cas posible mais done cette car il ya 3 cas possible
    return 0;
}

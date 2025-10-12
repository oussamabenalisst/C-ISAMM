#include <stdio.h>

int main()
{
    int inverse, num, suite, x, d;
    suite = 0;
    num = 0;
    do
    {
        suite++;
        do
        {
            printf("donne le %d chiffre : ", suite);
            scanf("%d", &x);
        } while (x < 0 || x >= 10);
        num = num * 10 + x;
    } while (x != 0 && suite != 9);
    printf("la suite est %d \n", num);
    //? ************* inverse *************//
    //? ************* inverse *************//
    //? ************* inverse *************//
    inverse = 0;
    while (num != 0)
    {
        d = num % 10;
        inverse = (inverse * 10) + d;
        num /= 10;
    }

    printf("la suite inverse est %d ", inverse);
    return 0;
}

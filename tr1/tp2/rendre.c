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
    } while (x != 0);
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

/*res*/
/*
donne le 1 chiffre : 1
donne le 2 chiffre : 2
donne le 3 chiffre : 3
donne le 4 chiffre : 4
donne le 5 chiffre : 5
donne le 6 chiffre : 6
donne le 7 chiffre : 7
donne le 8 chiffre : 0
la suite est 12345670
la suite inverse est 7654321
*/

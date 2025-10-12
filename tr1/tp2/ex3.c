#include <stdio.h>

int main()
{
    int i, temp, x, s;
    do
    {
        printf("Donner un entier positif X : ");
        scanf("%d", &x);
    } while (x < 0);
    // *Calcul de la somme des chiffres with while
    // *Calcul de la somme des chiffres with while
    // *Calcul de la somme des chiffres with while
    s = 0;
    i = 0;
    temp = x;
    while (temp != 0)
    {
        s += (temp % 10);
        temp /= 10;
        i++;
    }
    // *Calcul de la somme des chiffres with for
    // *Calcul de la somme des chiffres with for
    // *Calcul de la somme des chiffres with for
    i = 0;
    s = 0;
    for (temp = x; temp != 0; temp /= 10)
    {
        s += (temp % 10);
        i++;
    }
    printf("le moyenne est : %0.2f\n", (float)s / i);
    //? nombre uniforme
    //? nombre uniforme
    //? nombre uniforme
    int testuniforme = 1;
    int un = x % 10;
    temp = x / 10;
    while (temp != 0 && testuniforme)
    {
        if (un == temp % 10)
        {
            temp /= 10;
        }
        else
        {
            testuniforme = 0;
        }
    }
    if (testuniforme)
    {
        printf("le nombre %d est uniforme", x);
    }
    else
    {
        printf("le nombre %d n'est pas uniforme", x);
    }

    //? palindrome
    //? palindrome
    //? palindrome
    temp = x;
    int inverse = 0;
    while (temp != 0)
    {
        inverse = (inverse * 10) + (temp % 10);
        temp /= 10;
    }
    if (x == inverse)
    {
        printf("et palindrome");
    }
    else
    {
        printf("et non palindrome");
    }

    //?parfait
    //?parfait
    //?parfait
    i = 1;
    s = 0;
    while (i < x)
    {
        if (x % i == 0)
        {
            s += i;
        }
        i++;
    }
    if (s == x)
    {
        printf(" et parfait\n");
    }
    else
    {
        printf(" et non parfait\n");
    }

    return 0;
}

#include <stdio.h>

int main()
{
    int i, temp, x, testuniforme, un, s, choix;
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
    return 0;
}

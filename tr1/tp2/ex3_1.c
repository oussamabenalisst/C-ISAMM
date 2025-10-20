#include <stdio.h>

int main()
{
    int i, temp, x, testuniforme, un, s, choix = 0;
    while (choix > -1)
    {
        do
        {
            printf("\nDonner un entier positif X : ");
            scanf("%d", &x);
        } while (x < 0);
        printf("donne votre choix : ");
        printf("\n1.uniforme\n2.palindrome\n3.parfait\n> ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            testuniforme = 1;
            un = x % 10;
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

            break;
        case 2:
            temp = x;
            int inverse = 0;
            while (temp != 0)
            {
                inverse = (inverse * 10) + (temp % 10);
                temp /= 10;
            }
            if (x == inverse)
            {
                printf("le nombre %d est palindrome", x);
            }
            else
            {
                printf("le nombre %d n'est pas palindrome", x);
            }

            break;
        case 3:
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
                printf("le nombre %d est parfait\n", x);
            }
            else
            {
                printf("le nombre %d n'est pas parfait\n", x);
            }

            break;
        default:
            printf("Aucun test effectue.\n");
            break;
        }
    };
    return 0;
}

#include <stdio.h>
#define SIZE 50
int main()
{
    int n, T[SIZE] = {0};
    char choix;
    do
    {
        printf("donnez un entier positif n < %d: ", SIZE);
        scanf("%d", &n);
    } while (n < 0 || n >= SIZE);

    for (int i = 0; i < n; i++)
    {
        do
        {
            printf("T[%d] = ", i + 1);
            scanf("%d", &T[i]);
        } while (T[i] < 100 || T[i] >= 1000);
    }
    printf("Choisissez une option:\n-a:Afficher la plus grande valeur\n-b :afficher la moyenne\n-c:permuter deux valeurs\n-d inserter une valeur\n-e Supprimer un element\n-f:Afficher tous les elements uniques\n-g:Construire la matrice\n-h:Tri dans l ordre croissant\n-i:Tri dans l ordre decroissant\n-s:help\n-q:quit\n");
    do
    {
        do
        {
            printf(">");
            scanf(" %c", &choix);
        } while (choix == ' ');

        switch (choix)
        {
        case 's':
            printf("Choisissez une option:\n-a:Afficher la plus grande valeur\n-b :afficher la moyenne\n-c:permuter deux valeurs\n-d inserter une valeur\n-e Supprimer un element\n-f:Afficher tous les elements uniques\n-g:Construire la matrice\n-h:Tri dans l ordre croissant\n-i:Tri dans l ordre decroissant\n-s:help\n-q:quit\n");
            break;
        case 'q':
            printf("Au revoir!\n");
            break;
        case 'a':
        {
            int max = T[0];
            for (int i = 1; i < n; i++)
            {
                if (T[i] > max)
                    max = T[i];
            }
            printf("La plus grande valeur est: %d\n", max);
        }
        break;
        case 'b':
        {
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += T[i];
            }
            printf("La moyenne est: %.2f\n", (float)sum / n);
        }
        break;
        case 'c':
        {
            int idx1, idx2, temp;
            printf("Entrez les indices des deux valeurs a permuter (1 a %d): ", n);
            scanf("%d %d", &idx1, &idx2);
            if (idx1 < 1 || idx1 > n || idx2 < 1 || idx2 > n)
            {
                printf("Indices invalides.\n");
            }
            else
            {
                temp = T[idx1 - 1];
                T[idx1 - 1] = T[idx2 - 1];
                T[idx2 - 1] = temp;
                printf("Valeurs permutees.\n");
            }
        }
        break;

        default:
            printf("Option non valide. Veuillez reessayer.\n");
            break;
        }
    } while (choix != 'q');

    return 0;
}

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
    printf("Choisissez une option:\n-a:Afficher la plus grande petite valeur\n-b :afficher la moyenne\n-c:permuter deux valeurs\n-d inserter une valeur\n-e Supprimer un element\n-f:Afficher tous les elements uniques\n-g:Construire la matrice\n-h:Tri dans l ordre croissant\n-i:Tri dans l ordre decroissant\n-z:afficher tous les elements\n-s:help\n-q:quit\n");
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
            printf("Choisissez une option:\n-a:Afficher la plus grande petite valeur\n-b :afficher la moyenne\n-c:permuter deux valeurs\n-d inserter une valeur\n-e Supprimer un element\n-f:Afficher tous les elements uniques\n-g:Construire la matrice\n-h:Tri dans l ordre croissant\n-i:Tri dans l ordre decroissant\n-z:afficher tous les elements\n-s:help\n-q:quit\n");
            break;
        case 'q':
            printf("Au revoir!\n");
            break;
        case 'a':
        {
            int min = T[0];
            int max = T[0];
            for (int i = 1; i < n; i++)
            {
                if (T[i] > max)
                    max = T[i];
                if (T[i] < min)
                {
                    min = T[i];
                }
            }
            printf("La plus petite valeur est: %d\n", min);
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
        case 'z':
        {
            printf("Elements du tableau:\n");
            for (int i = 0; i < n; i++)
            {
                printf("%d ", T[i]);
            }
            printf("\n");
        }
        break;
        case 'd':
        {
            int newValue, position;
            do
            {
                printf("Entrez la nouvelle valeur: ");
                scanf("%d", &newValue);
            } while (newValue < 100 || newValue >= 1000);
            do
            {
                printf("Entrez la position d'insertion (1 a %d): ", n + 1);
                scanf("%d", &position);
            } while (position < 1 || position > n + 1);
            for (int i = n; i >= position; i--)
            {
                T[i] = T[i - 1];
            }
            T[position - 1] = newValue;
            n++;
            printf("Valeur inseree.\n");
        }
        break;
        case 'e':
        {
            int position;
            do
            {
                printf("Entrez la position a supprimer (1 a %d): ", n);
                scanf("%d", &position);
            } while (position < 1 || position > n);
            for (int i = position - 1; i < n - 1; i++)
            {
                T[i] = T[i + 1];
            }
            n--;
            printf("Element supprime.\n");
        }
        break;
        case 'f':
        {
            printf("Elements uniques:\n");
            int unique[SIZE] = {0};
            for (int i = 0; i < n; i++)
            {
                int isUnique = 1;
                for (int j = 0; j < n; j++)
                {
                    if (unique[j] == T[i])
                    {
                        isUnique = 0;
                        break;
                    }
                }
                if (isUnique)
                {
                    unique[i] = T[i];
                    printf("%d ", T[i]);
                }
            }
            printf("\n");
        }
        break;
        case 'g':
        {
            printf("Matrice carree construite a partir du tableau:\n");
            int M[SIZE][SIZE] = {0};
            for (int i = 0; i < n; i++)
            {
                M[i][i] = T[i];
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    printf("%d ", M[i][j]);
                }
                printf("\n");
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

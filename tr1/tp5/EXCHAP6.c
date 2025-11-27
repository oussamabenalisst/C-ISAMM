#include <stdio.h>
#include <string.h>
// EX1
int EX1()
{
    char chaines[5][100];
    char recherche[100];
    int i, trouve = 0;
    printf("Saisir 5 chaines de caracteres :\n");
    for (i = 0; i < 5; i++)
    {
        printf("Chaine %d : ", i + 1);
        fgets(chaines[i], 100, stdin);
        chaines[i][strcspn(chaines[i], "\n")] = '\0';
    }
    printf("\nSaisir une chaine a rechercher : ");
    fgets(recherche, 100, stdin);
    recherche[strcspn(recherche, "\n")] = '\0';
    for (i = 0; i < 5; i++)
    {
        if (strcmp(chaines[i], recherche) == 0)
        {
            trouve = 1;
            break;
        }
    }
    if (trouve)
        printf("La chaine \"%s\" existe dans le tableau.\n", recherche);
    else
        printf("La chaine \"%s\" n'existe pas dans le tableau.\n", recherche);
    return 0;
}
// EX2
int main()
{
    char chaine[200];
    char c;
    int i, compteur = 0;
    printf("Saisir une chaine : ");
    fgets(chaine, 200, stdin);
    chaine[strcspn(chaine, "\n")] = '\0';
    printf("Saisir un caractere : ");
    c = getchar();
    for (i = 0; chaine[i] != '\0'; i++)
    {
        if (chaine[i] == c)
            compteur++;
    }
    printf("Le caractere '%c' apparait %d fois dans la chaine.\n", c, compteur);
    EX1();
    return 0;
}

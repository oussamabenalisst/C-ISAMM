#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char titre[50];
    char auteur[50];
    int annee;
    char ISBN[20];
    int Etat;
} Livre;

int saisire()
{
    int n;
    do
    {
        printf("Donne le nombre de livres: ");
        scanf("%d", &n);
    } while (n < 0);
    return n;
}
Livre saisireLivre()
{
    Livre livre;
    printf("Titre: ");
    scanf("%s", livre.titre);
    printf("Auteur: ");
    scanf("%s", livre.auteur);
    printf("Annee: ");
    scanf("%d", &livre.annee);
    printf("ISBN: ");
    scanf("%s", livre.ISBN);
    livre.Etat = 1;
    return livre;
}

void RemplirLivres(Livre Livres[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Livre %d:\n", i + 1);
        Livres[i] = saisireLivre();
    }
}

int main()
{
    int n = saisire();
    Livre Livres[100];
    RemplirLivres(Livres, n);
    RechercherLivre(Livres, n);
    return 0;
}

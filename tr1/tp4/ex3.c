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
void RechercherLivre(Livre Livres[], int n)
{
    printf("----------Recherche d'un livre par son titre:----------\n");
    int annee;
    do
    {
        printf("Donne lannee de publication du livre : ");
        scanf("%d", &annee);
    } while (annee < 1000 || annee > 9999);
    for (int i = 0; i < n; i++)
    {
        if (Livres[i].annee == annee)
        {
            printf("Titre : %s Auteur : %s Annee : %d ISBN : %s Etat : %d\n",
                   Livres[i].titre, Livres[i].auteur, Livres[i].annee, Livres[i].ISBN, Livres[i].Etat);
        }
    }
}
int main()
{
    int n = saisire();
    Livre Livres[100];
    RemplirLivres(Livres, n);
    RechercherLivre(Livres, n);
    RemplacerAuteur(Livres, n);
    return 0;
}

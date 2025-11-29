#include <stdio.h>
#include <string.h>
#include <ctype.h>
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
void RemplacerAuteur(Livre t[], int n)
{
    int pos = -1;
    char new[] = "Salah";
    for (int i = 0; i < n; i++)
    {
        if (strlen(t[i].auteur) >= strlen(new))
        {
            // pos = strstr(toupper(t[i].auteur), toupper(new)) != NULL ? strstr(toupper(t[i].auteur), toupper(new)) : -1;
            if (strstr(t[i].auteur, new) != NULL)
            {
                pos = strstr(t[i].auteur, new) - t[i].auteur;
            }
            else
            {
                pos = -1;
            }

            if (pos != -1)
            {
                for (int j = pos; j < pos + strlen(new); j++)
                {
                    t[i].auteur[j] = new[j - pos];
                }
            }
        }
    }
}
float MoyenneTaile(Livre Livres[], int n)
{
    int somme = 0;
    for (int i = 0; i < n; i++)
    {
        somme += strlen(Livres[i].titre);
    }
    return somme / n;
}
void afficherLivres(Livre Livres[], int n)
{
    int moy = MoyenneTaile(Livres, n);
    for (int i = 0; i < n; i++)
    {
        if (strlen(Livres[i].titre) >= moy)
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
    afficherLivres(Livres, n);
    return 0;
}

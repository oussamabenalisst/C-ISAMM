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
    printf("----------Remplacement de l'auteur:----------\n");
    const char new[] = "Salah";
    int position = -1;
    int test;
    for (int i = 0; i < n; i++)
    {
        if (strlen(new) < strlen(t[i].auteur))
        {
            if (stricmp(t[i].auteur, new) == 0)
            {
                strcpy(t[i].auteur, new);
            }
            else
            {
                for (int j = 0; j < strlen(t[i].auteur) - strlen(new); j++)
                {
                    test = 0;
                    for (int k = 0; k < strlen(new); k++)
                    {
                        test = test && (tolower(t[i].auteur[j + k]) == tolower(new[k]));
                    }
                    if (test)
                    {
                        position = j;
                        break;
                    }
                }
                if (position != -1)
                {
                    for (int k = 0; k < strlen(new); k++)
                    {
                        t[i].auteur[position + k] = new[k];
                    }
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

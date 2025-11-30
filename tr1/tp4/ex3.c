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
    const char old[] = "Ali";
    char sh1[50];
    char sh2[50];
    int position = -1;
    for (int i = 0; i < n; i++)
    {
        if (strlen(old) <= strlen(t[i].auteur))
        {
            if (stricmp(t[i].auteur, old) == 0)
            {
                strcpy(t[i].auteur, new);
            }
            else
            {
                for (int j = 0; j <= strlen(t[i].auteur) - strlen(old); j++)
                {
                    if (strnicmp(&t[i].auteur[j], old, strlen(old)) == 0)
                    {
                        position = j;
                        break;
                    }
                }
                if (position != -1)
                {
                    for (int k = 0; k < position; k++)
                    {
                        sh1[k] = t[i].auteur[k];
                    }
                    sh1[position] = '\0';
                    for (int k = position + strlen(old); k <= strlen(t[i].auteur); k++)
                    {
                        sh2[k - (position + strlen(old))] = t[i].auteur[k];
                    }
                    sh2[strlen(t[i].auteur) - (position + strlen(old))] = '\0';
                    strcpy(t[i].auteur, sh1);
                    strcat(t[i].auteur, new);
                    strcat(t[i].auteur, sh2);
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

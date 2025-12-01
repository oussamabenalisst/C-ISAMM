#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_ETUDIANTS 100
typedef struct
{
    char titre[50];
    char auteur[50];
    int annee;
    char ISBN[20];
    int Etat;
} Livre;
typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;
typedef struct
{
    char nom[50];
    char prenom[50];
    char cin[20];
    Date date
} Etudiant;

typedef struct
{
    Etudiant etudiant;
    Livre livre;
    Date dateEmprunt;
    Date dateRetour;
} EMPRUNT;

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
    livre.Etat = -1;
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
void RemplirEtudiants(Etudiant etudiants[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Etudiant %d:\n", i + 1);
        printf("Nom: ");
        scanf("%s", etudiants[i].nom);
        printf("Prenom: ");
        scanf("%s", etudiants[i].prenom);
        printf("CIN: ");
        scanf("%s", etudiants[i].cin);
        printf("Date de naissance (jj mm aaaa): ");
        scanf("%d %d %d", &etudiants[i].date.jour, &etudiants[i].date.mois, &etudiants[i].date.annee);
    }
}
Date dateretour15(Date dateEmprunt)
{
    Date dateRetour = dateEmprunt;
    dateRetour.jour += 15;
    if (dateRetour.jour > 30)
    {
        dateRetour.jour -= 30;
        dateRetour.mois += 1;
        if (dateRetour.mois > 12)
        {
            dateRetour.mois = 1;
            dateRetour.annee += 1;
        }
    }
    return dateRetour;
}
void RemplirEmprunts(EMPRUNT emprunts[], Livre Livres[], Etudiant etudiants[], int n_livres)
{
    for (int i = 0; i < 3; i++)
    {
        int livre_index, etudiant_index;
        printf("Emprunt %d:\n", i + 1);
        printf("Date d'emprunt (jj mm aaaa): ");
        scanf("%d %d %d", &emprunts[i].dateEmprunt.jour, &emprunts[i].dateEmprunt.mois, &emprunts[i].dateEmprunt.annee);
        emprunts[i].livre.Etat = -1;
        emprunts[i].dateRetour = dateretour15(emprunts[i].dateEmprunt);
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
    Etudiant etudiants[MAX_ETUDIANTS];
    int n_etudiants = saisire();
    RemplirEtudiants(etudiants, n_etudiants);
    EMPRUNT emprunts[3];
    RemplirEmprunts(emprunts, Livres, etudiants, n);
    return 0;
}

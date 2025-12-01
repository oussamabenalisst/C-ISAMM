#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int jj, mm, aa;
} DATE;

typedef struct
{
    char titre[100];
    char auteur[100];
    int annee;
    char ISBN[30];
    int Etat;
} LIVRE;

typedef struct
{
    char nom[50];
    char prenom[50];
    long CIN;
} ETUDIANT;

typedef struct
{
    ETUDIANT etud;
    LIVRE livre;
    DATE date_emprunt;
    DATE date_retour;
} EMPRUNT;

DATE Ajouter15Jours(DATE d)
{
    d.jj += 15;
    int m[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    while (d.jj > m[d.mm - 1])
    {

        d.jj -= m[d.mm - 1];
        d.mm++;
        if (d.mm > 12)
        {
            d.mm = 1;
            d.aa++;
        }
    }
    return d;
}

int comparer_dates(DATE d1, DATE d2)
{
    if (d1.aa != d2.aa)
        return d1.aa - d2.aa;
    if (d1.mm != d2.mm)
        return d1.mm - d2.mm;
    return d1.jj - d2.jj;
}

void RemplirLivres(LIVRE L[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Saisir les informations du livre n°%d (titre auteur annee ISBN):\n", i + 1);
        scanf("%s %s %d %s", L[i].titre, L[i].auteur, &L[i].annee, L[i].ISBN);
        L[i].Etat = -1;
    }
}

void Recherche(LIVRE L[], int n)
{
    int A;
    printf("Entrez l'année à rechercher:\n");
    scanf("%d", &A);
    printf("Livres publiés en %d:\n", A);
    for (int i = 0; i < n; i++)
    {
        if (L[i].annee == A)
            printf("%s\n", L[i].titre);
    }
}

void RemplacerAli(LIVRE L[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (strcasecmp(L[i].auteur, "Ali") == 0)
        {
            strcpy(L[i].auteur, "Salah");
            printf("Auteur 'Ali' remplacé par 'Salah' pour le livre %s\n", L[i].titre);
        }
    }
}

void AfficherPlusLong(LIVRE L[], int n)
{
    int max = 0;
    for (int i = 1; i < n; i++)
    {
        if (strlen(L[i].titre) > strlen(L[max].titre))
            max = i;
    }
    printf("Le titre le plus long est : %s\n", L[max].titre);
}

void RemplirEtudiants(ETUDIANT E[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Saisir les informations de l'étudiant n°%d (nom prenom CIN):\n", i + 1);
        scanf("%s %s %ld", E[i].nom, E[i].prenom, &E[i].CIN);
    }
}

int rech_lineaire(ETUDIANT E[], int n, char nom[], char prenom[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(E[i].nom, nom) == 0 && strcmp(E[i].prenom, prenom) == 0)
            return i;
    }
    return -1;
}

int chercher_livre(LIVRE L[], int n, char isbn[])
{
    for (int i = 0; i < n; i++)
    {
        if (strcmp(L[i].ISBN, isbn) == 0)
            return i;
    }
    return -1;
}

void mise_a_jour_etat(LIVRE L[], int n, EMPRUNT emp[], int nb, DATE act)
{
    for (int i = 0; i < n; i++)
        L[i].Etat = -1;

    for (int i = 0; i < nb; i++)
    {
        int k = chercher_livre(L, n, emp[i].livre.ISBN);
        if (k != -1)
        {
            if (comparer_dates(act, emp[i].date_retour) > 0)
                L[k].Etat = 1;
            else
                L[k].Etat = 0;
        }
    }
}

void AfficherEtudiants(ETUDIANT E[], int n)
{
    printf("=== Liste des étudiants ===\n");
    for (int i = 0; i < n; i++)
    {
        printf("Etudiant %d : %s %s CIN: %ld\n", i + 1, E[i].nom, E[i].prenom, E[i].CIN);
    }
    printf("\n");
}

void AfficherEmprunts(EMPRUNT emp[], int nb)
{
    printf("=== Liste des emprunts ===\n");
    for (int i = 0; i < nb; i++)
    {

        printf("Emprunt %d : Etudiant %s %s, Livre %s, Date emprunt: %02d/%02d/%04d, Date retour: %02d/%02d/%04d\n",
               i + 1,
               emp[i].etud.nom, emp[i].etud.prenom,
               emp[i].livre.titre,
               emp[i].date_emprunt.jj, emp[i].date_emprunt.mm, emp[i].date_emprunt.aa,
               emp[i].date_retour.jj, emp[i].date_retour.mm, emp[i].date_retour.aa

        );
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Saisir le nombre de livres:\n");
    scanf("%d", &n);
    LIVRE L[100];
    RemplirLivres(L, n);
    Recherche(L, n);
    RemplacerAli(L, n);
    AfficherPlusLong(L, n);

    int ne;
    printf("Saisir le nombre d'étudiants:\n");
    scanf("%d", &ne);
    ETUDIANT E[50];
    RemplirEtudiants(E, ne);

    EMPRUNT emp[50];
    int nb_emp = 3;
    printf("Saisir les dates d'emprunt des 3 premiers emprunts (jour mois annee):\n");
    for (int i = 0; i < 3; i++)
    {
        emp[i].etud = E[i];
        emp[i].livre = L[i];
        scanf("%d %d %d", &emp[i].date_emprunt.jj, &emp[i].date_emprunt.mm, &emp[i].date_emprunt.aa);

        emp[i].date_retour = Ajouter15Jours(emp[i].date_emprunt);
    }

    DATE actuelle;
    printf("Saisir la date actuelle (jour mois annee):\n");
    scanf("%d %d %d", &actuelle.jj, &actuelle.mm, &actuelle.aa);
    mise_a_jour_etat(L, n, emp, nb_emp, actuelle);

    printf("Livres actuellement disponibles:\n");
    for (int i = 0; i < n; i++)
    {
        if (L[i].Etat == 1)
            printf("%s\n", L[i].titre);
    }

    printf("Saisir un étudiant pour emprunter un livre (nom prenom CIN):\n");
    ETUDIANT x;
    char isbn[30];
    scanf("%s %s %ld", x.nom, x.prenom, &x.CIN);
    int pos = rech_lineaire(E, ne, x.nom, x.prenom);
    if (pos == -1)
    {
        E[ne] = x;
        pos = ne;
        ne++;
        AfficherEtudiants(E, ne);
    }

    int k = -1;
    while (1)
    {
        printf("Saisir l'ISBN du livre à emprunter:\n");
        scanf("%s", isbn);
        k = chercher_livre(L, n, isbn);
        if (k != -1 && L[k].Etat == 1)
        {
            printf("Livre disponible, vous pouvez l'emprunter.\n");
            break;
        }
        else
        {
            printf("Livre non disponible ou ISBN invalide, ressaisir.\n");
        }
    }

    if (nb_emp < 50)
    {
        emp[nb_emp].etud = E[pos];
        emp[nb_emp].livre = L[k];
        printf("Saisir la date d'emprunt (jour mois annee):\n");
        scanf("%d %d %d", &emp[nb_emp].date_emprunt.jj, &emp[nb_emp].date_emprunt.mm, &emp[nb_emp].date_emprunt.aa);
        emp[nb_emp].date_retour = Ajouter15Jours(emp[nb_emp].date_emprunt);
        L[k].Etat = 0;
        nb_emp++;
    }

    int s;
    printf("Saisir l'indice de l'emprunt à supprimer:\n");
    scanf("%d", &s);
    if (s >= 0 && s < nb_emp)
    {
        int ks = chercher_livre(L, n, emp[s].livre.ISBN);
        if (ks != -1)
            L[ks].Etat = -1;
        for (int i = s; i < nb_emp - 1; i++)
            emp[i] = emp[i + 1];
        nb_emp--;
    }

    AfficherEmprunts(emp, nb_emp);
    return 0;
}
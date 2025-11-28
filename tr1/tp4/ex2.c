#include <stdio.h>
#include <string.h>
#define N 5

typedef struct
{
    char name[30];
    char prename[30];
    float md[3];
    float moyenne;
} etudiants;

void afficher(etudiants t[])
{
    printf("\n--- Liste des etudiants ---\n");
    for (int i = 0; i < N; i++)
    {
        printf("Etudiant %d: %s %s, Notes: [Math: %.2f, Physique: %.2f, Sciences: %.2f], Moyenne: %.2f\n", i + 1, t[i].name, t[i].prename, t[i].md[0], t[i].md[1], t[i].md[2], t[i].moyenne);
    }
}

etudiants LireEtudiants()
{
    etudiants e;
    do
    {
        printf("donner le nom de l etudiant: ");
        scanf("%s", e.name);
    } while (strlen(e.name) < 3 || strlen(e.name) > 30);
    do
    {
        printf("donner le prenom de l etudiant: ");
        scanf("%s", e.prename);
    } while (strlen(e.prename) < 3 || strlen(e.prename) > 30);
    do
    {
        printf("donner la note de math: ");
        scanf("%f", &e.md[0]);
    } while (e.md[0] < 0 || e.md[0] > 20);
    do
    {
        printf("donner la note de physique: ");
        scanf("%f", &e.md[1]);
    } while (e.md[1] < 0 || e.md[1] > 20);
    do
    {
        printf("donner la note de sciences: ");
        scanf("%f", &e.md[2]);
    } while (e.md[2] < 0 || e.md[2] > 20);
    return e;
}

void Lire(etudiants t[])
{
    etudiants e;
    for (int i = 0; i < N; i++)
    {
        e = LireEtudiants();
        t[i] = e;
    }
}

void CalculerMoyenne(etudiants t[])
{
    for (int i = 0; i < N; i++)
    {
        t[i].moyenne = (t[i].md[0] + t[i].md[1] + t[i].md[2]) / 3;
        printf("la moyenne de %s %s est: %.2f\n", t[i].name, t[i].prename, t[i].moyenne);
    }
}
void TriCroissant(etudiants t[])
{
    etudiants temp;
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (t[i].moyenne > t[j].moyenne)
            {
                temp = t[i];
                t[i] = t[j];
                t[j] = temp;
            }
        }
    }
}

void main()
{
    etudiants t[N];
    Lire(t);
    CalculerMoyenne(t);
    TriCroissant(t);
}

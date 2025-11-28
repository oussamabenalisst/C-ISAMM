#include <stdio.h>
#include <string.h>
#define N 5
typedef struct
{
    float math;
    float Physique;
    float Sciences;
} modules;

typedef struct
{
    char name[30];
    char prename[30];
    modules md;
    float moyenne;
} etudiants;

etudiants LireEtudiants()
{
    etudiants e;
    printf("donner le nom de l etudiant: ");
    scanf("%s", e.name);
    printf("donner le prenom de l etudiant: ");
    scanf("%s", e.prename);
    printf("donner la note de math: ");
    scanf("%f", &e.md.math);
    printf("donner la note de Physique: ");
    scanf("%f", &e.md.Physique);
    printf("donner la note de Sciences: ");
    scanf("%f", &e.md.Sciences);
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
        t[i].moyenne = (t[i].md.math + t[i].md.Physique + t[i].md.Sciences) / 3;
        printf("la moyenne de %s %s est: %.2f\n", t[i].name, t[i].prename, t[i].moyenne);
    }
}

void main()
{
    etudiants t[N];
    Lire(t);
    CalculerMoyenne(t);
}

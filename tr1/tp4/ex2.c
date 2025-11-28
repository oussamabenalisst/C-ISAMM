#include <stdio.h>
#include <string.h>
#define N 4
typedef struct
{
    char name[30];
    char prename[30];
    float md[3];
    float moyenne;
} etudiants;

void afficher(etudiants t[], int count)
{
    printf("\n--- Liste des etudiants ---\n");
    for (int i = 0; i < count; i++)
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

void Lire(etudiants t[], int count)
{
    etudiants e;
    for (int i = 0; i < count; i++)
    {
        e = LireEtudiants();
        t[i] = e;
    }
}

void CalculerMoyenne(etudiants t[], int count)
{
    for (int i = 0; i < count; i++)
    {
        t[i].moyenne = (t[i].md[0] + t[i].md[1] + t[i].md[2]) / 3;
    }
}

void Tri(etudiants t[], int count)
{
    etudiants temp;
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = i + 1; j < count; j++)
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
int RecherchDichotomique(etudiants t[], int low, int high, char *name)
{
    if (low >= high)
        return low;
    int mid = (low + high) / 2;
    if (strcmp(t[mid].name, name) < 0)
        return RecherchDichotomique(t, mid + 1, high, name);
    else
        return RecherchDichotomique(t, low, mid, name);
}

void move(etudiants t[], int idx, int count, etudiants nv)
{
    // for (int i = count; i > idx; --i)
    //     t[i] = t[i - 1];
    // t[idx] = nv;
    if (count <= idx)
    {
        t[idx] = nv;
        return;
    }
    t[count] = t[count - 1];
    move(t, idx, count - 1, nv);
}

int main()
{
    etudiants t[N + 1];
    int count = N;
    Lire(t, count);
    CalculerMoyenne(t, count);
    Tri(t, count);
    afficher(t, count);
    printf("\n--- Insertion dun nouvel etudiant (par nom) ---\n");
    etudiants nv = LireEtudiants();
    nv.moyenne = (nv.md[0] + nv.md[1] + nv.md[2]) / 3;
    int idx = RecherchDichotomique(t, 0, count, nv.name);
    move(t, idx, count, nv);
    count++;
    printf("\nListe apres insertion:\n");
    afficher(t, count);
    return 0;
}

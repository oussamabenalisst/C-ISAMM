#include <stdio.h>
#define PI 3.14159

int main()
{
    char forme;
    float surface = 0;
    float longueur, largeur, rayon, base, hauteur;

    printf("Entrez le caractère correspondant à la forme :\n");
    printf("Carre (R/r), Rectangle (C/c), Triangle (T/t), Cercle (O/o) : ");
    scanf(" %c", &forme);

    switch (forme)
    {
    case 'R':
    case 'r':
        printf("Entrez la longueur du cote : ");
        scanf("%f", &longueur);
        surface = longueur * longueur;
        break;
    case 'C':
    case 'c':
        printf("Entrez la longueur et la largeur : ");
        scanf("%f %f", &longueur, &largeur);
        surface = longueur * largeur;
        break;
    case 'T':
    case 't':
        printf("Entrez la base et la hauteur : ");
        scanf("%f %f", &base, &hauteur);
        surface = (base * hauteur) / 2;
        break;
    case 'O':
    case 'o':
        printf("Entrez le rayon : ");
        scanf("%f", &rayon);
        surface = PI * rayon * rayon;
        break;
    default:
        printf("Caractère non reconnu.\n");
        return 1;
    }
    printf("******************m2IF*****************\n");
    if (forme == 'r' || forme == 'R')
    {
        printf("Entrez la longueur du cote : ");
        scanf("%f", &longueur);
        surface = longueur * longueur;
    }
    else if (forme == 'O' || forme == 'o')
    {
        printf("Entrez le rayon : ");
        scanf("%f", &rayon);
        surface = PI * rayon * rayon;
    }
    else if (forme == 'T' || forme == 't')
    {
        printf("Entrez la base et la hauteur : ");
        scanf("%f %f", &base, &hauteur);
        surface = (base * hauteur) / 2;
    }
    else if (forme == 'C' || forme == 'c')
    {
        printf("Entrez la longueur et la largeur : ");
        scanf("%f %f", &longueur, &largeur);
        surface = longueur * largeur;
    }

    printf("La surface est : %.2f\n", surface);
    return 0;
}

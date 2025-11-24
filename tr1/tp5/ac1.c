#include <stdio.h>
#include <string.h>

int main()
{
    char t[5][100];
    int test = 0;
    char ch[100];
    for (int i = 0; i < 5; i++)
    {
        printf("Entrez le mot %d : ", i + 1);
        scanf("%s", t[i]);
    }
    printf("Entrez un mot a rechercher : ");
    scanf("%s", ch);
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(t[i], ch) == 0)
        {
            test = 1;
            break;
        }
    }
    if (test == 1)
    {
        printf("Le mot %s est present dans le tableau.\n", ch);
    }
    else
    {
        printf("Le mot %s n'est pas present dans le tableau.\n", ch);
    }
    return 0;
}

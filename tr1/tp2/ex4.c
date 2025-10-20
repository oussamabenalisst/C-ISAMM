#include <stdio.h>

int main()
{
    printf("Table de multiplication\n");
    for (int j = 0; j <= 10; j++)
    {
        if (j == 0)
            printf(" X|");
        printf("%3d ", j);
    }
    printf("\n");
    for (int i = 0; i <= 10; i++)
    {
        printf("____");
    }

    for (int i = 0; i <= 10; i++)
    {
        printf("\n");
        printf("%2d|", i);
        for (int j = 0; j <= 10; j++)
        {
            printf("%3d ", i * j);
        }
    }
    return 0;
}

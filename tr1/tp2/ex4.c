#include <stdio.h>

int main()
{
    printf("Table de multiplication\n");
    for (int j = 0; j <= 10; j++)
    {
        if (j == 0)
            printf("0X|");
        printf("%03d|", j);
    }
    for (int i = 0; i <= 10; i++)
    {
        printf("\n");
        printf("%02d|", i);
        for (int j = 0; j <= 10; j++)
        {
            printf("%03d|", i * j);
        }
    }
    return 0;
}

#include <stdio.h>

main()
{
    int i;
    float x;
    printf("i | x\n");
    for (i = 1, x = 0; i <= 8; i++, x += 0.1)
    {
        printf("%d | %f\n", i, x);
    }
}

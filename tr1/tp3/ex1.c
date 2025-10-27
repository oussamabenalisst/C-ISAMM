#include <stdio.h>
int main()
{
    char Tab[3];
    int N = 5;
    for (int i = 0; i < N; i++)
    {

        Tab[i] = i + 1;
    }
    for (int i = N - 1; i >= 0; i--)
    {
        printf("%d\n", Tab[i]);
    }
    return 0;
}
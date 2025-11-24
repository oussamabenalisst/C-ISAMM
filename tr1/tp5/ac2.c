#include <stdio.h>
#include <string.h>

typedef struct
{
    char ch;
    int count;
} CharCount;

void saisi(char (*ch)[100])
{
    printf("Enter a string: ");
    scanf("%s", *ch);
}
int recherch(char c, CharCount charCounts[100], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (charCounts[i].ch == c)
            return 1;
    }
    return 0;
}
void calcule(char ch[100], CharCount charCounts[100], int *size)
{
    int count;
    for (int i = 0; i < strlen(ch); i++)
    {
        count = 0;
        if (!recherch(ch[i], charCounts, *size))
        {
            for (int j = 0; j < strlen(ch); j++)
                if (ch[i] == ch[j])
                    count++;
            (*size)++;
            charCounts[*size - 1].ch = ch[i];
            charCounts[*size - 1].count = count;
        }
    }
}

void affichage(CharCount charCounts[100], int size)
{
    printf("Character counts:\n");
    for (int i = 0; i < size; i++)
    {
        if (charCounts[i].count != 0)
            printf("Character '%c' occurs %d times\n", charCounts[i].ch, charCounts[i].count);
    }
}
void main()
{
    char ch[100];
    CharCount charCounts[100];
    int size = 0;
    saisi(&ch);
    calcule(ch, charCounts, &size);
    affichage(charCounts, size);
}

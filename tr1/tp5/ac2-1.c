#include <stdio.h>
#include <string.h>
char ch[100];
char c;

void saisi1()
{
    printf("Enter a string: ");
    scanf("%s", ch);
}

void saisi2()
{
    printf("Enter a character: ");
    scanf(" %c", &c);
}
int countch(char *ch, char c)
{
    int count = 0;
    for (int i = 0; i < strlen(ch); i++)
    {
        if (ch[i] == c)
            count++;
    }
    return count;
}
int main()
{

    saisi1();
    saisi2();
    printf("le caractere %c apparait %d fois\n", c, countch(ch, c));
    return 0;
}

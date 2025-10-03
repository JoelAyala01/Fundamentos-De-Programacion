#include <stdio.h>
#include <string.h>
int son_rotaciones(char *, char *);

int main()
{
    char s1[10];
    char s2[10];

    printf("\nEscribe una cadena: ");
    gets(s1);
    printf("\nEscribe otra cadena: ");
    gets(s2);

    son_rotaciones(s1,s2);

    return 0;
}

int son_rotaciones(char *s1, char *s2)
{
    int n = strlen(s1);
    if(n != strlen(s2))
    {
        printf("\n---Cadenas diferentes---\n");
        return 0;
    }
    printf("\n\n");
    for(int j=0; j<n; j++)
    {
        char temp = s2[0];
        for(int i=0; i<n; i++)
        {
            s2[i] = s2[i+1];
        }
        s2[n-1] = temp;
        puts(s2);

        if(strcmp(s1,s2) == 0){
            printf("\nGanaste!\n\n");
            puts(s2);
            return 1;
        }
    }
    puts(s2);
    printf("\nPerdiste!\n");
    return 0;
}

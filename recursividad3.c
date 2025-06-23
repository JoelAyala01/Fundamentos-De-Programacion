
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

int cont_pal(char *);

int main()
{
    char texto[MAX];
    printf("\nIngrese el texto: ");
    gets(texto);

    printf("\n\nEl texto tiene %d palabras ", cont_pal(texto));
}

int cont_pal(char *text)
{
    if(*text == '\0')
        return 0;
    else if(*text != ' ' && (*(text+1) == ' ' || *(text+1) == '\0'))
    {
        return 1 + cont_pal(text+1);

    }
    return cont_pal(text+1);
}

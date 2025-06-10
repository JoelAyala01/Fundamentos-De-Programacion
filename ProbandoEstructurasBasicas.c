//Joel De Jesus Ayala Peguero
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char titulo[50];
    char autor[50];
    int agno;
}info_libros;

int main()
{
    info_libros libros1;

    printf("Digite un titulo: ");
    gets(libros1.titulo);

    printf("Digite un autor: ");
    gets(libros1.autor);

    printf("Digite el agno: ");
    scanf("%d",&libros1.agno);

    printf("\n\nEl libro es: ");
    puts(libros1.titulo);
    puts(libros1.autor);
    printf("%d", libros1.agno);



    system("PAUSE");
    return 0;
}

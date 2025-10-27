#include <stdio.h>
#include <stdlib.h>
/*Crecer dinámicamente — usar realloc() */

typedef struct
{
    char nombre[20];
    float nota;
} ESTUDIANTE;

int main()
{
    ESTUDIANTE *e = NULL;
    int cantidad = 0;
    char continuar;

    do{
    cantidad++;
    e = realloc(e, cantidad * sizeof(ESTUDIANTE));
    if(e == NULL)
    {
        printf("\nError! Problemas de memoria!\a\n");
        return 1;
    }
        printf("\nEstudiante #%d: ",cantidad);
        printf("\nNombre: ");
        gets((e+cantidad-1)->nombre);
        printf("\nNota: ");
        scanf("%f",&e[cantidad-1].nombre);

        printf("\nDesea agregar otro estudiante? (s/n) ");
        scanf(" %c",&continuar);

    } while(continuar == 's' || continuar == 'S');

    return 0;
}

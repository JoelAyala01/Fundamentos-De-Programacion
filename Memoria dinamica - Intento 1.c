#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Pedir al usuario la cantidad de notas → reservar memoria → llenarlas → calcular el promedio → liberar memoria.*/

int main()
{
    int n;
    printf("Ingresa la cantidad de notas a ingresar: ");
    //Leo la cantidad de notas que el usuario ingresara
    scanf("%d",&n);

    /*
    Reservo la memoria que necesitare para la cantidad de notas que el usuario va a ingresar.
    Creo la variable float *notas, es un puntero porque guardara la direccion de memoria donde se creo su espacio en memoria.
    Entonces es igual a (float*), que dice que esa direccion de memoria almacena valores float, (basicamente un convertidor de tipo).
    malloc(n*sizeof(float)) calcula cuantos bloques de 4 byte(valor de float creo) debe reservar. Ej: n=2, float=4bytes, n*float=8 */
    float *notas = (float *) malloc(n * sizeof(float));
    if(notas == NULL)/*NULL significa que no apunta a ningun valor valido en memoria.
        En otras palabras, un puntero con valor NULL no tiene dirección válida.
        -> No hay suficiente memoria disponible → malloc() devuelve NULL. (notas==NULL: no hay memoria (puntero vacio)). */
    {
        printf("\nError al asignar memoria!\n\a");
        return 1;
    }

    for(int i=0; i<n; i++)
    {
        printf("\nNota #%d: ",i+1);
        scanf("%f",(notas+i));
    }

    for(int i=0; i<n; i++)
    {
        printf("\nNota #%d: %.2f ",i+1, *(notas+i));
    }

    float suma = 0;
    for(int i=0; i<n; i++)
    {
        suma += *(notas+i);
    }

    printf("\n\nPrmedio: %.2f", suma/n);

    free(notas);

    return 0;
}

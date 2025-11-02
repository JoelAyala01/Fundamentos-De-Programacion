//Joel Ayala Peguero
#include <stdio.h>
#include <stdlib.h>

///Punteros a estructuras
/*Ejercicio 1: Mostrar datos de un estudiante
Crea una estructura llamada ESTUDIANTE con los campos:
char nombre[30], int edad, float promedio.
Declara un estudiante, crea un puntero que apunte a él y muestra los datos usando el operador ->.

Objetivo: practicar ptr->campo y manejo básico de punteros. */

typedef struct
{
    char nombre[30];
    int edad;
    float promedio;
}ESTUDIANTE;

void llenarE(ESTUDIANTE *, int);
void mostrarE(ESTUDIANTE *, int);
float promedioGeneral(ESTUDIANTE *, int);

int main()
{
    int n;
    printf("Cantidad de estudiantes a registrar: ");
    scanf("%d",&n);
    ESTUDIANTE *e = (ESTUDIANTE *)malloc(n*sizeof(ESTUDIANTE));
    if(e==NULL)
    {
        printf("\n\tError al asignar memoria!...\a\n");
        return 1;
    }

    llenarE(e,n);
    mostrarE(e,n);

    printf("\n");
    float prom = (promedioGeneral(e,n) / n);
    printf("\npromedio final: %.2f\n\n", prom);
    system("PAUSE");
    free(e);


    return 0;
}

float promedioGeneral(ESTUDIANTE *e, int n)
{
    float suma;
    if(n==0)
    {
        return 0;
    }
    else
    {
        suma = e[n-1].promedio;
        return (suma + promedioGeneral(e,n-1));
    }
}

void llenarE(ESTUDIANTE *e, int n)
{
    printf("\nIngresa los datos del estudiante: \n");
    for(int i=0; i<n; i++)
    {
        printf("\n\tESTUDIANTE #%d",i+1);
        printf("\nNombre: ");
        scanf("%s",(e+i)->nombre);
        printf("Edad: ");
        scanf("%d",&(e+i)->edad);
        printf("Promedio: ");
        scanf("%f",&(e+i)->promedio);
    }
}

void mostrarE(ESTUDIANTE *e, int n)
{
    printf("\n\nDatos del estudiante: \n");
    for(int i=0; i<n; i++)
    {
        printf("\n\tESTUDIANTE #%d",i+1);
        printf("\nNombre: %s", (e+i)->nombre);
        printf("\nEdad: %d", (e+i)->edad);
        printf("\nPromedio: %.2f", (e+i)->promedio);
    }
}

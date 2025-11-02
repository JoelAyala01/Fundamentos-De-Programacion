//Joel Ayala Peguero
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*Ejercicio 2: Lista de estudiantes dinámica
Pide al usuario cuántos estudiantes va a registrar y reserva memoria con malloc.
Por cada estudiante: Pide nombre, edad y promedio.
Al final, imprime toda la lista.
Requisitos: Usa typedef struct, malloc y free.*/

typedef struct
{
    char nombre[30];
    int edad;
    float promedio;
} ESTUDIANTE;

void mi_fflush()
{
    int c;
    while((c=getchar())!='\n' && c!=EOF)
    {
    }
}


void llenarEstud(ESTUDIANTE *, int);
void mostrarEstud(ESTUDIANTE *, int);

int main()
{
    int n;
    printf("Cuantos estudiantes se registraran: ");
    scanf("%d",&n);

    ESTUDIANTE *e = (ESTUDIANTE *)malloc(n*sizeof(ESTUDIANTE));
    llenarEstud(e,n);
    system("CLS");
    mostrarEstud(e,n);

    free(e);
    printf("\n\n");
    system("PAUSE");
    return 0;
}

void mostrarEstud(ESTUDIANTE *e, int n)
{
    printf("\n\nDatos de los estudiantes: \n");
    printf("\nNombre: \t\tEdad: \tPromedio: ");
    for(int i=0; i<n; i++)
    {
        printf("\n%-20s \t%d \t%.2f", (e+i)->nombre, (e+i)->edad, (e+i)->promedio);
    }
}

void llenarEstud(ESTUDIANTE *e, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\nEstudiante #%d: \n",i+1);
        //getchar(); // limpia el salto de línea previo a fgets
        //fflush(stdin);
        mi_fflush();
        printf("Nombre: ");
        gets((e+i)->nombre);
        printf("Edad: ");
        scanf("%d",&(e+i)->edad);
        printf("Promedio: ");
        scanf("%f",&(e+i)->promedio);
    }
}

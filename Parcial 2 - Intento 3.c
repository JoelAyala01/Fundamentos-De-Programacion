//Joel Ayala Peguero
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nombre[30];
    int edad;
    float promedio;
} ESTUDIANTE;

void llenarEstud(ESTUDIANTE *, int, int);
void mostrarEstud(ESTUDIANTE *, int, int);
float promGeneral_rec(ESTUDIANTE *, int);
float notaMayor_rec(ESTUDIANTE *, int);

int main()
{
    int n=0;
    printf("Estudiantes a registrar: ");
    scanf("%d",&n);
    ESTUDIANTE *e = (ESTUDIANTE *)malloc(n*sizeof(ESTUDIANTE));
    if(e==NULL)
    {
        printf("\n\tError al asignar memoria!\a\n");
        return 1;
    }
    llenarEstud(e,0,n);
    system("CLS");
    mostrarEstud(e,0,n);
    printf("\n\n");
    system("PAUSE");

    float promFinal = (promGeneral_rec(e,n)/n);
    printf("\n\nPromedio Final General: %.3f", promFinal);
    printf("\nNota mas alta: %.3f\n\n",notaMayor_rec(e,n));

    system("CLS");

    int nuevos;
    int total, totalviejo;
    char opcion;

    do{
    printf("\nDesea agregar mas estudiantes: (S/N)");
    scanf(" %c",&opcion);
    if(opcion == 'S' || opcion == 's')
    {
        printf("\nCuantos nuevos agregaras? ");
        scanf("%d",&nuevos);

        totalviejo = n;
        total = n+nuevos;
        e = (ESTUDIANTE *)realloc(e,total*sizeof(ESTUDIANTE));
        if(e==NULL)
        {
            printf("\n\tError de memoria!\a\n");
            return 1;
        }

        llenarEstud(e,totalviejo,total);
        mostrarEstud(e,0,total);
        n = total;
    }
    }while(opcion == 'S' || opcion == 's');

    free(e);
    system("PAUSE");
    return 0;
}

float notaMayor_rec(ESTUDIANTE *e, int n)
{
    if(n==0)
        return 0;
    else if(n==1)
        return e[0].promedio;

    float mayor = notaMayor_rec(e,n-1);

    if(mayor > e[n-1].promedio)
        return mayor;
    else
        return e[n-1].promedio;
}

float promGeneral_rec(ESTUDIANTE *e, int n)
{
    float suma;
    if(n==0)
        return 0;
    else
    {
        suma = e[n-1].promedio;
        return suma + promGeneral_rec(e,n-1);
    }
}

void llenarEstud(ESTUDIANTE *e, int inicio, int fin)
{
    for(int i=inicio; i<fin; i++)
    {
        printf("\nEstudiante #%d: \n",i+1);
        getchar();
        //fflush(stdin);
        printf("\nNombre: ");
        gets((e+i)->nombre);
        printf("Edad: ");
        scanf("%d",&(e+i)->edad);
        printf("Promedio: ");
        scanf("%f",&(e+i)->promedio);
    }
}

void mostrarEstud(ESTUDIANTE *e, int inicio, int fin)
{
    printf("=== Datos de los estudiantes ===\n\n");
    printf("\n%-20s %-5s %10s \n","Nombre: ", "Edad: ", "Promedio: ");
    for(int i=inicio; i<fin; i++)
    {
        printf("\n%-20s %5d %9.2f", (e+i)->nombre, (e+i)->edad, (e+i)->promedio);
    }
}

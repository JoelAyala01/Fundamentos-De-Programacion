#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char nombre[20];
char apellido[20];
float nota;
}ESTUDIANTE;

/*
Ejemplo #2 de memoria dinamica, usando malloc para reservar memoria, en este caso para un arreglo de estructura.
*/

int main(){
int n;
printf("Ingresa cuantos estudiantes ingresaras: ");
scanf("%d",&n);

ESTUDIANTE *e = (ESTUDIANTE*) malloc(n*sizeof(ESTUDIANTE));
if(e==NULL)
{
    printf("\n\aError!, Fallo de memoria!\n");
    return 1;
}

for(int i=0; i<n; i++)
{
    printf("\nEstudiante #%d ",i+1);
    printf("\nNombre: ");
    scanf("%s",(e+i)->nombre);
    printf("\nApellido: ");
    scanf("%s",(e+i)->apellido);
    printf("\nNota: ");
    scanf("%f",&(e+i)->nota);
}

for(int i=0; i<n; i++)
{
    printf("\nEstudiante #%d ",i+1);
    printf("\nNombre: %s", (e+i)->nombre);
    printf("\nApellido: %s", (e+i)->apellido);
    printf("\nNota: %.2f", (e+i)->nota);
}

free(e);

return 0;}

//Joel De Jesus Ayala Peguero
#include <stdio.h>
#include <string.h>
#define MAX 50

void elimstr(char *, int, int);

int main()
{
    printf("Escribe un texto: \n");
    char texto[MAX];
    gets(texto);
    printf("\n---El texto ingresado es: ");
    puts(texto);

    int desde, hasta;
    printf("\n\nIngresa desde que posicion desea eliminar hasta cual: \n");

    do{
    printf("Desde: ");
    scanf("%d",&desde);
    if(desde<=0)
    {
       printf("\nIngresa valores validos!\n");
    }
    }while(desde<=0);

    do{
    printf("\nHasta: ");
    scanf("%d",&hasta);
    if(hasta >= (strlen(texto)))
    {
        printf("\nIngresa valores validos!\n");
    }
    }while(hasta >= (strlen(texto)));

    elimstr(texto,desde,hasta);
    puts(texto);

    return 0;
}

/*
Funcion: elimstr
Objetivo: Recibe una cadena de caracteres y esta elimina los caracteres que se encuentes entre
la posicion inicial hasta la posicion final indicada ingresada por el usuario
Retorna: retorna la cadena modificada
*/
void elimstr(char *st, int pos, int numcar)
{
    int cont = 0;
    int i;
    for(i=pos; *(st+i+numcar) != '\0'; i++)
    {
        *(st+i) = *(st+i+numcar);
    }
    *(st+i) = '\0';
}




///Joel De Jesus Ayala Peguero

#include<stdio.h>
#include<stdlib.h>
#define MAX 10

void print_matriz1(int [][MAX], int);
void print_matriz2(int [][MAX], int);
void print_matriz3(int [][MAX], int);
void sumar_matrices(int [][MAX], int [][MAX], int [][MAX], int);

int main()
{
    int dim;
    int M1[MAX][MAX];
    int M2[MAX][MAX];
    int M3[MAX][MAX];

    //Validar filas
    do
    {
        printf("Digite dimensi%cn: ",162);
        scanf("%d",&dim);

       if(dim<2)
       {
           printf("\aError\nDigite un valor mayor que uno (1)\n");
           system("PAUSE");
           system("CLS");
       }

    }while(dim<2);

    int f, c;


    //Llenar matrices
    for(f=0;f<dim;f++)
    {
        for(c=0;c<dim;c++)
        {
            printf("Digite valor en M1[%d][%d]: ",f,c);
            scanf("%d",&M1[f][c]);
        }
    }

    //Llenar segunda matriz
    for(f=0;f<dim;f++)
    {
        for(c=0;c<dim;c++)
        {
            printf("Digite valor en M2[%d][%d]: ",f,c);
            scanf("%d",&M2[f][c]);
        }
    }

    print_matriz1(M1,dim);
    printf("\n");
    print_matriz2(M2,dim);
    printf("\n");
    sumar_matrices(M1, M2, M3, dim);
    print_matriz3(M3,dim);

    system("PAUSE");
    return 0;
}

/*
Funcion: sumar_matrices
Objetivo: recibe dos matrices cuadradas para sumarlas y almacenarlas en la tercera matriz
*/
void sumar_matrices(int M1[][MAX], int M2[][MAX], int M3[][MAX], int dim)
{
    for(int f=0; f<dim; f++)
    {
        for(int c=0; c<dim; c++)
        {
            M3[f][c] = M1[f][c] + M2[f][c];
        }

    }

}


/*
Función: print_matriz
Objetivo: recibe una matriz cuadrada de valores enteros e imprimes sus valores
NO retorna
*/
void print_matriz1(int M1[][MAX], int dim)
{
    int f,c;
    for(f=0;f<dim;f++)
    {
        for(c=0;c<dim;c++)
            printf("%4d",M1[f][c]);

        printf("\n"); //para visualizar el cambio de fila
    }
}

void print_matriz2(int M2[][MAX], int dim)
{
    int f,c;
    for(f=0;f<dim;f++)
    {
        for(c=0;c<dim;c++)
            printf("%4d",M2[f][c]);

        printf("\n"); //para visualizar el cambio de fila
    }
}

void print_matriz3(int M3[][MAX], int dim)
{
    int f,c;
    for(f=0;f<dim;f++)
    {
        for(c=0;c<dim;c++)
            printf("%4d",M3[f][c]);

        printf("\n"); //para visualizar el cambio de fila
    }
}

#include <stdio.h>
#include <stdlib.h>

void llenar(int n, int M[n][n]);
void imprimir(int n, int M[n][n]);
int espejo(int n, int M[n][n]);

int main()
{
    int n;

    do{
        printf("\nIngrese la dimension de la matriz: ");
        scanf("%d",&n);
        if(n<2)
        {
            printf("\n\aEl numero debe ser mayor que dos (2)\n");
        }
    }while(n<2);

    int Matriz[n][n];

    llenar(n,Matriz);
    imprimir(n,Matriz);
    if(espejo(n,Matriz)==1)
    {
        printf("\n\aLa matriz ES espejo horizontal!\n");
    }
    else
    {
        printf("\n\aLa matriz NO es espejo horizontal!\n");

    }

    system("PAUSE");

    return 0;
}

int espejo(int n, int M[n][n])
{
    for(int f=0; f<n/2; f++)
    {
        for(int c=0; c<n; c++)
        {
            if(M[f][c] != M[n-1-f][c])
            {
                return 0;
            }
        }
    }
    return 1;
}

void llenar(int n, int M[n][n])
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            printf("\nIngresa los valores de: M[%d][%d]: ",i,j);
            scanf("%d",&M[i][j]);
        }
    }
}


void imprimir(int n, int M[n][n])
{
    for(int i=0; i<n; i++)
    {
        printf("\n");
        for(int j=0; j<n; j++)
        {
            printf("%d ",M[i][j]);
        }
    }
}

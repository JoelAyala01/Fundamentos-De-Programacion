#include <stdio.h>
#include <stdlib.h>
#include <String.h>

#define MAX 3

int matriz_segura(int m[][MAX]);
void llenar(int m[MAX][MAX]);
void imprimir(int m[MAX][MAX]);

int main()
{
    int matriz[MAX][MAX];
    llenar(matriz);
    imprimir(matriz);
    printf("\n");
    if(matriz_segura(matriz) == 1)
    {
        imprimir(matriz);
        printf("\nLa matriz es segura! \n");
    }
    else{printf("\n\nLa matriz NO es segura\n");}

    system("PAUSE");
    return 0;
}

int matriz_segura(int m[MAX][MAX])
{
    float promedio = 0;
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            if(i==j)
            {
                if(m[i][j] % 2 != 0)
                {
                    printf("\n\aError! El valor no es par!\n");
                    return 0;
                }

                promedio += m[i][j];
            }
        }
    }
    promedio = promedio/MAX;

    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            if(j>i)
            {
                if(m[i][j] > 0 && m[i][j] < promedio)
                {
                    continue;
                }
                else
                {
                    printf("\nLos valores encima de la diagonal son INCORRECTOS! \n");
                    return 0;
                }

            }

            if(i>j)
            {
                if(m[i][j] > promedio && m[i][j] < (promedio*2))
                {
                    continue;
                }
                else
                {
                    printf("\nLos valores debajo de la diagonal son INCORRECTOS! \n");
                    return 0;
                }
            }
        }
    }
    return 1;
}

void imprimir(int m[MAX][MAX])
{
    printf("\n\nImprimir Matriz: \n\n");
    for(int i=0; i<MAX; i++)
    {
        printf("\n");
        for(int j=0; j<MAX; j++)
        {
            printf(" %d ", m[i][j]);
        }
    }
}

void llenar(int m[MAX][MAX])
{
    printf("\n\nLlenar Matriz: \n\n");
    for(int i=0; i<MAX; i++)
    {
        for(int j=0; j<MAX; j++)
        {
            printf("\nIngresa la posicion [%d][%d]: ", i+1, j+1);
            scanf("%d", &m[i][j]);
        }
    }
}


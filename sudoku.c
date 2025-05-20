//Joel De Jesus Ayala Peguero

#include <stdio.h>
#include <stdlib.h>

void llenar_sudoku(int n, int sudoku[n][n]);
void imprimir_sudoku(int n, int sudoku[n][n]);
int verifica_fila(int n, int sudoku[n][n]);
int verifica_columna(int n, int sudoku[n][n]);

int main()
{
    int n;
    do{
    printf("\aIngresa el tamano del sudoku (4 o 9): ");
    scanf("%d",&n);
    if(n!=4 && n!=9)
    {
        printf("\a\nERROR!, Valor Inv%clido\a\n", 162);
    }
    }while(n!=4 && n!=9);
    int sudoku[n][n];


    llenar_sudoku(n,sudoku);
    imprimir_sudoku(n,sudoku);

    if(verifica_fila(n,sudoku)==1)
    {
        printf("\a\n\nLo siento!, numeros repetidos en las filas!!!\n");
    }
    else
    {
        printf("\a\n\nTodas las filas son correctas, ningun numero se repite!!!\n");
    }

    if(verifica_columna(n,sudoku)==1)
    {
        printf("\a\n\nLo siento!, numeros repetidos en las columnas!!!\n");

    }
    else
    {
        printf("\a\n\nTodas las columnas son correctas, ningun numero se repite!!!\n");

    }


    return 0;
}



///*****************************IMPLEMENTACION DE FUNCIONES*********************************///
/*
    Funcion: llenar_sudoku
    Objetivo: Recorrer la matriz pidiendole valores al usuario y llenandola
    NO retorna
    */
void llenar_sudoku(int n, int sudoku[n][n])
{
    for(int f=0; f<n; f++)
    {
        for(int c=0; c<n; c++)
        {
            printf("\nIntroduce valores al sudoku [%d][%d]: ", f,c);
            scanf("%d",&sudoku[f][c]);
        }
    }
}

/*
    Funcion: imprimir_sudoku
    Objetivo: Recorrer la matriz imprimiendo cada valor
    NO retorna`
    */
void imprimir_sudoku(int n, int sudoku[n][n])
{
    for(int f=0; f<n; f++)
    {
        printf("\n");
        for(int c=0; c<n; c++)
        {
            printf("%d ", sudoku[f][c]);
        }
    }
}


 /*
    Funcion: verificar_fila
    Objetivo: Recorrer la matriz fila por fila buscando numeros repetidos en la misma fila
    Retorna: falso o verdadero
    */
int verifica_fila(int n, int sudoku[n][n])
{
    for(int fila=0; fila<n; fila++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(sudoku[fila][i]==sudoku[fila][j])
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}


/*
    Funcion: verificar_columna
    Objetivo: Recorrer la matriz columna por columna buscando numeros repetidos en la misma columna
    Retorna: falso o verdadero
    */
int verifica_columna(int n, int sudoku[n][n])
{
    for(int columna=0; columna<n; columna++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                if(sudoku[i][columna]==sudoku[j][columna])
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

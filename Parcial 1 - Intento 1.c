
//Joel De Jesus Ayala Peguero
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct
{
    char codempleado[7];
    char nombre[30];
    char puesto[30];
    float sueldo;
} EMPLEADO;

typedef struct
{
    char coddepto[7];
    char nombre[30];
    int cantemp;
    EMPLEADO emp[50];
} DEPARTAMENTO;

void depto_mayor_paga(DEPARTAMENTO depto[],int n, DEPARTAMENTO *d);
void imprimir(DEPARTAMENTO depto[], int n);
int main()
{
    /*int n;
    printf("\nIngresa cuantos departamentos hay: ");
    scanf("%d",&n);*/

    DEPARTAMENTO depto[2] = {
    {
        //Departamento 1
        "D0001", //Codigo del departamento
        "Tech", //Nombre del departamento
        2,     //Cantdad de empleados
        {
            {"EMP001", "Joel", "Ingeniero", 120000},
            {"EMP002", "Adelso", "Ingeniero", 130000}
        }
    },

    {
        //Departmento 2
        "D0002", //Codigo del departamento
        "Admin", //Nombre del departamento
        3,
        {
            //3 empleados
            {"EMP010", "Ayala", "Disenador", 70000},
            {"EMP012", "Jimenez", "Disenador", 70000},
            {"EMP013", "Francisco", "Operador", 105000}
        }
    }
};
    DEPARTAMENTO deptoMayor;
    imprimir(depto,2);
    depto_mayor_paga(depto,2,&deptoMayor);


    printf("\n\n=== DEPARTAMENTO CON MAYOR SUELDO PROMEDIO ===\n");
    printf("Codigo: %s\n", deptoMayor.coddepto);
    printf("Nombre: %s\n", deptoMayor.nombre);
    printf("Cantidad de empleados: %d\n", deptoMayor.cantemp);
    return 0;
}

void depto_mayor_paga(DEPARTAMENTO depto[],int n, DEPARTAMENTO *d)
{
    int indiceMayor;
    float mayor_depto = 0;
    for(int i=0; i<2; i++)
    {
        float suma = 0;
        for(int j=0; j<depto[i].cantemp; j++)
        {
            suma = suma + depto[i].emp[j].sueldo;
        }
        float promedio = 0;
        promedio = suma / depto[i].cantemp;

        printf("\nPromedio del departamento #%d: %.2f", i+1, promedio);

        if(promedio > mayor_depto)
        {
            mayor_depto = promedio;
            indiceMayor = i;
        }
    }
    *d = depto[indiceMayor];
}

void imprimir(DEPARTAMENTO depto[], int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\n\n\t---DEPARTAMENTOS---\n");
        printf("\nCodigo del Departamento: %s", depto[i].coddepto);
        printf("\nNombre del Departamento: %s", depto[i].nombre);
        printf("\nCantidad de empleados: %d", depto[i].cantemp);
        printf("\n");

        printf("\n\n\t---EMPLEADOS---\n");
        for(int j=0; j<depto[i].cantemp; j++)
        {
            printf("\nEmpleado #%d: ",j+1);
            printf("\nCodigo del Empleado: %s", depto[i].emp[j].codempleado);
            printf("\nNombre del empleado: %s", depto[i].emp[j].nombre);
            printf("\nPuesto del empleado: %s", depto[i].emp[j].puesto);
            printf("\nSueldo del empleado: %.2f", depto[i].emp[j].sueldo);
        }
    }
}

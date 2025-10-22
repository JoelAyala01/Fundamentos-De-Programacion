//Joel Ayala Peguero
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char codasig[7];
    char descripcion[30];
    int creditos;
    float p1;
    float p2;
    float p3;
    float p4;
} ASIGNATURA;

typedef struct
{
    char matricula[9];
    char nombre[20];
    char apellido[20];
    char carrera[5];
    int CantAsig;
    ASIGNATURA asig[20];
} ESTUDIANTE;

/*Desarrollar la funcion int Estud_Aprobaron_Asig(Estud e[],int n,char *cod_asig), la cual de un
valor de n estudiantes devuelve la cantidad de estudiantes que aprobaron la asignatura
cod_asig. */

int Estud_Aprobaron_Asig(ESTUDIANTE e[],int n,char *cod_asig);

int main()
{
   ESTUDIANTE e[3] = {
        {
            "10155386", "Joel", "Ayala", "ITT", 2,
            {
                {"ICC103", "Fundamentos", 4, 10.0, 15.0, 20.0, 18.0},
                {"ITT234", "Ing. Tráfico", 3, 20.0, 20.0, 20.0, 20.0}
            }
        },
        {
            "10103457", "Adelso", "Jimenez", "ITT", 2,
            {
                {"ITT234", "Ing. Tráfico", 3, 15.0, 12.0, 14.0, 10.0},
                {"ITT789", "Programación", 3, 20.0, 20.0, 20.0, 20.0}
            }
        },
        {
            "10153698", "William", "Francisco", "ITT", 2,
            {
                {"ITT234", "Ing. Tráfico", 3, 18.0, 18.0, 18.0, 18.0},
                {"ITT342", "Sist. Teleco", 3, 15.0, 14.0, 16.0, 12.0}
            }
        }
    };

    printf("\nResultado: %d pasaron \n", Estud_Aprobaron_Asig(e,3,"ITT234"));

    return 0;
}

int Estud_Aprobaron_Asig(ESTUDIANTE *e,int n,char *cod_asig)
{
    int cont = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<(e+i)->CantAsig; j++)
        {
            if(strcmp((e+i)->asig[j].codasig, cod_asig) == 0)
            {
                float suma = (e+i)->asig[j].p1 + (e+i)->asig[j].p2 + (e+i)->asig[j].p3 + (e+i)->asig[j].p4;

                if(suma >= 60)
                {
                    cont++;
                }
                break;
            }
        }
    }
    return cont;
}

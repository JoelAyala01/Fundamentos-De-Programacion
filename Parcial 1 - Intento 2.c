//Joel Ayala
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
 char codasig[7];
 char descripcion [30];
 int creditos;
 float p1;
 float p2;
 float p3;
 float p4;
}ASIGNATURA;

typedef struct
{
 char matricula[9];
 char nombre[20];
 char apellido[20];
 char carrera[5];
 int  CantAsig;
 ASIGNATURA asig[20];
}ESTUDIANTE;

/*Desarrollar la funcion int Estud_Aprobaron_Asig(Estud e[],int n,char *cod_asig), la cual de un
valor de n estudiantes devuelve la cantidad de estudiantes que aprobaron la asignatura
cod_asig.*/

int Estud_Aprobaron_Asig(ESTUDIANTE e[],int n,char *cod_asig);

int main()
{
    ESTUDIANTE e[3] = {
        //Estudiante 1
        {
            "10155386",
            "Joel",
            "Ayala",
            "ITT",
            3,
            {
                {"ICC103", "Fundamentos", 4, 8.0, 7.0, 5.5, 14.0},
                {"ITT234", "ING Trafico", 2, 18.0, 19, 15.2, 21},
                {"ITT342", "Sistema de Teleco", 3, 21.0, 17, 15.2, 21}
            }
        },
        //Estudiante 2
        {
            "10103457",
            "Adelso",
            "Jimenez",
            "ITT",
            3,
            {
                {"ITT456", "Teoria de codigo", 3, 12.0, 15.0, 18.0, 21.5},
                {"ITT234", "ING Trafico", 2, 15.0, 20.0, 16.0, 20.0},
                {"ITT453", "Electromagnetismo", 4, 12.0, 13.0, 17.0, 19.0},
            }
        },
        //Estudiante 3
        {
            "10153698",
            "William",
            "Francisco",
            "ITT",
            3,
            {
                {"ICC103", "Fundamentos", 4, 8.0, 7.0, 5.5, 14.0},
                {"ITT234", "ING Trafico", 2, 14.0, 16, 15.5, 20},
                {"FIS129", "Fisica", 4, 11.0, 13, 15.2, 17}
            }
        }
    };
    printf("\n\nResultado escolar: %d\n", Estud_Aprobaron_Asig(e,3,"ITT234"));

    return 0;
}

int Estud_Aprobaron_Asig(ESTUDIANTE e[],int n,char *cod_asig){
    int estAprov = 0;
    for(int i=0; i<n; i++)
    {//Estudiante
        for(int j=0; j<e[i].CantAsig; j++)
        {
            if(strcmp(cod_asig, e[i].asig[j].codasig)==0)
            {
                float Ps = e[i].asig[j].p1 + e[i].asig[j].p2 + e[i].asig[j].p3 + e[i].asig[j].p4;
                printf("\nLa nota de %s %s en %s es: %.2f ", e[i].nombre, e[i].apellido, e[i].asig[j].codasig, Ps);
                if(Ps >= 59.5)
                {
                    estAprov++;
                }
            }
        }

    }
    return estAprov;
}

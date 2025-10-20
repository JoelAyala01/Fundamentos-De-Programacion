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
} ASIGNATURA;

typedef struct
{
    char matricula[9];
    char nombre[20];
    char apellido[20];
    char carrera[5];
    int  CantAsig;
    ASIGNATURA asig[20];
} ESTUDIANTE;

/*Desarrollar la funcion float Total_Estud_Pasaron(Estud e[],int n), la cual devuelve el
promedio de los estudiantes que pasaron en A’s de un total de n estudiantes.*/

float Total_Estud_Pasaron(ESTUDIANTE e[],int n);

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
                {"ICC103", "Fundamentos", 4, 12.0, 10.0, 20.5, 14.0},
                {"ITT234", "ING Trafico", 2, 22.0, 19, 25.2, 25.5},
                {"ITT342", "Sistema de Teleco", 3, 30.0, 20.4, 22.2, 21}
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
                {"ITT234", "ING Trafico", 2, 25.0, 20.0, 20.0, 28.0},
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
                {"ITT234", "ING Trafico", 2, 20.0, 20, 20.5, 30},
                {"FIS129", "Fisica", 4, 20.0, 13, 15.2, 17}
            }
        }
    };

    float resultado = Total_Estud_Pasaron(e,3) * 100;
    printf("\nResultado: %.1f\n",resultado);
    return 0;
}

float Total_Estud_Pasaron(ESTUDIANTE e[],int n)
{
    float prom = 0;
    float sumaP = 0;
    for(int i=0; i<n; i++)
    {//Estudiantes
        for(int j=0; j<e[i].CantAsig; j++)
        {//Asignaturas
            sumaP = e[i].asig[j].p1 + e[i].asig[j].p2 + e[i].asig[j].p3 + e[i].asig[j].p4;
            if(sumaP >= 89.5)
            {
                printf("\nLa asignatura %s esta en 'A' ", e[i].asig[j].descripcion);
                prom++;
                break; //Rompe el bucle for de las asignaturas ya que al menos una se paso en 'A'
            }
        }
    }
    //Divide la cantidad de estudiantes en A entre los n estudiantes
    prom /= n;
    return prom;
}

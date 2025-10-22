#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char matricula[8];
    char nombre[20];
    char carrera[3];
    float puntos;
    int creditos;
} EST;

/*Realice una funci�n void EstudiantesPromedios(EST *data,int n),  que imprima los estudiantes
que est�n por encima del �ndice promedio, de un total de n estudiantes y que sean de la carrera
de ISC o ITT. El �ndice es igual a puntos entre cr�ditos.  */

void EstudiantesPromedios(EST *data,int n);

int main()
{
    EST e[3] = {
        {//Estudiante 1
            "1015538", "Joel Ayala", "ITT", 30.0, 12
        },
        {
            "1015546", "Adelso Jimenez", "ITT", 30.0, 12
        },
        {
            "1015590", "William Franc.", "ITT", 48.0, 14
        },
    };

    EstudiantesPromedios(e,3);

    return 0;
}

void EstudiantesPromedios(EST *data,int n)
{
    float indice = 0;
    float indice_prom = 0;
    for(int i=0; i<n; i++)
    {
        indice = (data+i)->puntos / (data+i)->creditos;
        indice_prom += indice;
        printf("\nIndice de %s es: %.3f\n",(data+i)->nombre,indice);
    }
    indice_prom /= n;
    printf("\nIndice promedio es: %.3f\n",indice_prom);

    printf("\nEstudiantes por encima del promedio: %.2f",indice_prom);
    printf("\nMatricula: \tNombre: \tCarrera: \tPuntos: \tCreditos: \tIndice: \n");
    for(int i=0; i<n; i++)
    {
        indice = (data+i)->puntos / (data+i)->creditos;
        if(indice > indice_prom && ( (strcmp((data+i)->carrera, "ITT")) || (strcmp((data+i)->carrera, "ISC"))))
        {

            printf("\n%s \t%s \t%s \t\t%2.f \t\t%d \t\t%.2f",(data+i)->matricula,(data+i)->nombre,(data+i)->carrera,(data+i)->puntos,(data+i)->creditos,indice);
        }
    }
    printf("\n\n");

}

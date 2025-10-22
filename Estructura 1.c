//Joel Ayala
#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    char cedula[12];
    char nombres[50];
    char apellidos[50];
    char sexo;
    char estadocivil;

}PERSONA;

int main()
{
    PERSONA per[MAX];
    int n;

    printf("\nDigite cantidad: ");
    scanf("%d",&n);

   for(int i=0; i<n; i++)
   {
       fflush(stdin);
    printf("\n\nDigite cedula: ");
    //gets(per[i].cedula);
    scanf("%s",&per[i].cedula);

    printf("\nDigite nombre: ");
    gets(per[i].nombres);

    printf("\nDigite apellido: ");
    gets(per[i].apellidos);

    printf("\nDigite sexo: ");

    scanf("%c",&per[i].sexo);

    printf("\nDigite estadocivil: ");
    scanf("%c",&per[i].estadocivil);

    printf("\n\nDatos de persona: \n");

    printf("\nCed: %s\n",per[i].cedula);

    printf("\nNombre: %s\n",per[i].nombres);

    printf("\nApellido: %s\n",per[i].apellidos);

    printf("\nSexo: %c\n",per[i].sexo);

    printf("\nEstado Civil: %c\n",per[i].estadocivil);
   }



    system("PAUSE");
    return 0;
}

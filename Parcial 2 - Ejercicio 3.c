//Joel Ayala Peguero
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char marca[20];
    int ano;
    float precio;
}VEHICULO;

VEHICULO *registrarAuto(int);
void filtrarAuto(VEHICULO *, int, char *, int *, float *);

int main()
{
    int n;
    printf("Cuantos autos a registrar: ");
    scanf("%d",&n);

    VEHICULO *v = registrarAuto(n);
    if(v==NULL)
    {
        system("CLS");
        printf("\nError al asignar memoria!\n");
        return 1;
    }

    //Filtrar por marca:
    char marcaB[20];
    int anoB;
    float precioB;
    getchar();
    printf("\nMarca a buscar: ");
    gets(marcaB);
    printf("Desde el ano: ");
    scanf("%d",&anoB);
    printf("Con precio superior a: ");
    scanf("%f",&precioB);

    filtrarAuto(v,n,marcaB,&anoB,&precioB);

    system("PAUSE");
    return 0;
}

void filtrarAuto(VEHICULO *v, int n, char *marcaB, int *ano, float *precio)
{
    printf("\n\nRESULTADOS DE AUTOS: \n\n");
    printf("\n---------------------------------------------------------------");
    printf("\n%-3s %-15s %-5s %7s", "No. ", "Marca: ", "Ano: ", "Precio: ");
    int cont = 0;
    for(int i=0; i<n; i++)
    {
        if(strcmp((v+i)->marca, marcaB) == 0 && ((v+i)->ano >= *ano) && ((v+i)->precio) >= *precio)
        {
            cont++;
            printf("\n%-4d %-15s %-5d %7.4f ", cont, (v+i)->marca, (v+i)->ano, (v+i)->precio);
        }
        if(i == (n-1) && cont == 0)
        {
            printf("\n\n\t\aNo se encontraron autos con esas especificaciones!...\a\n");
        }
    }
    printf("\n---------------------------------------------------------------\n\n");
    printf("\nSe encontraron %d autos con esas especificaciones!\n", cont);

}


VEHICULO *registrarAuto(int n)
{
    VEHICULO *v = (VEHICULO *)calloc(n,sizeof(VEHICULO));

    for(int i=0; i<n; i++)
    {
        printf("\nVehiculo #%d: \n",i+1);
        getchar();
        printf("Marca: ");
        gets((v+i)->marca);
        printf("Ano: ");
        scanf("%d",&(v+i)->ano);
        printf("Precio: ");
        scanf("%f",&(v+i)->precio);
    }
    system("PAUSE");
    system("CLS");

    printf("%-20s %-5s %7s ", "Marca: ", "Ano: ", "Precio: ");
    for(int i=0; i<n; i++)
    {
        printf("\n%-20s %-5d %7.3f", (v+i)->marca, (v+i)->ano, (v+i)->precio);
    }
    return v;
}

//JOEL DE JESUS AYALA PEGUERO
#include <stdio.h>

void imprimir(int n, float huracan[n], int categ[n]);
float cat(int n, float huracan[n], int categ[n]);

int main()
{
    int n;
    do{
    printf("\nCuantas tormentas desa analizar? ");
    scanf("%d",&n);
    }while(n<1);

    float huracanes[n];
    int categoria[n];

    for(int i=0; i<n; i++)
    {
        do{
            printf("\nIngresa la velocidad de la tormenta #%d: ", i+1);
            scanf("%f",&huracanes[i]);
            if(huracanes[i]<1)
            {
                printf("\nIngrese velocidad valida!!!\n");
            }
        }while(huracanes[i]<1);

    }

    cat(n, huracanes, categoria);
    imprimir(n, huracanes, categoria);

return 0;
}

void imprimir(int n, float huracan[n], int categ[n])
{
    printf("\n\n");
    printf("%-8s %-17s %-15s %-15s", "Ciclon", "Velocidad(Km/h)", "Categoria", "Descripcion");
    printf("\n-------------------------------------------------------------------------------");
    for(int i=0; i<n; i++)
    {
        printf("\n%-8d %-18.2f %-14d ", i+1, huracan[i], categ[i]);
        if(categ[i]==-2)
        {
            printf("%15s","Depresion Tropical (0-62 km/h)");
        }
        else if(categ[i]==-1)
        {
            printf("%15s","Tormenta Tropical (63-118 km/h)");
        }
        else if(categ[i]==1)
        {
            printf("%15s","Huracan Cat. 1 (119-153 km/h)");
        }
        else if(categ[i]==2)
        {
            printf("%15s","Huracan Cat. 2 (154-177 km/h)");
        }
        else if(categ[i]==3)
        {
            printf("%15s","Huracan Cat. 3 (178-208 km/h)");
        }
        else if(categ[i]==4)
        {
            printf("%15s","Huracan Cat. 4 (209-251 km/h)");
        }
        else
        {
            printf("%15s","Huracan Cat. 5 (>= 252 km/h)");
        }
    }
}

float cat(int n, float huracan[n], int categ[n])
{
    for(int i=0; i<n; i++)
    {
        if(huracan[i]<=62)
        {
            categ[i]=-2;
        }
        else if(huracan[i]>=63 && huracan[i]<=118)
        {
            categ[i]=-1;
        }
        else if(huracan[i]>=119 && huracan[i]<=153)
        {
            categ[i]=1;
        }
        else if(huracan[i]>=154 && huracan[i]<=177)
        {
            categ[i]=2;
        }
        else if(huracan[i]>=178 && huracan[i]<= 208)
        {
            categ[i]=3;
        }
        else if(huracan[i]>=209 && huracan[i]<=251)
        {
            categ[i]=4;
        }
        else if(huracan[i]>=252)
        {
            categ[i]=5;
        }
        else
        {
            printf("\a\nError! ----- ALGO SALI%c MAL, INTENTALO DE NUEVO...");
        }
    }
}


#include <stdio.h>
#include <stdlib.h>

int potencia(int a, int b);
int main()
{
    int a, b;
    do{
        printf("\nIngresa un numero: ");
        scanf("%d",&a);
        if(a <= 0)
        {
            printf("\nEl numero debe ser mayor a cero! ");
        }
    }while(a<=0);

    do{
        printf("\nIngresa el numero a elevar: ");
        scanf("%d",&b);
        if(a <= 0)
        {
            printf("\nEl numero debe ser mayor a cero! ");
        }
    }while(a<=0);

    printf("\n\nPotencia: %d \n\n", potencia(a,b));
    system("PAUSE");
    return 0;

}

int potencia(int a, int b)
{
    if(a==0)
        return 0;
    if(b==0)
        return 1;
    return a * potencia(a,b-1);
}

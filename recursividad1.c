
#include <stdio.h>
#include <stdlib.h>

int multiplicar_recur(int a, int b);
int multiplicar(int x, int y);

int main()
{
    int a, b;
    printf("\nIngresa un numero: ");
    scanf("%d",&a);
    printf("\nIngresa otro numero: ");
    scanf("%d",&b);

    printf("\nHola!, %d ", multiplicar_recur(a,b));
    //multiplicar_recur(a,b);



    return 0;
}

int multiplicar(int x, int y)
{

}


int multiplicar_recur(int a, int b)
{
    if(b==0)
    {
        return 0;
    }
    else
    {
        return a + multiplicar_recur(a,b-1);
    }
}


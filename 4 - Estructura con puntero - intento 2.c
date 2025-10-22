#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    float x;
    float y;

} PUNTO;

/*Dos puntos en el plano se pueden representar mediante una estructura de dos campos.
Escriba la  función void medio (struct punto p1, struct punto p2, struct punto * p3), que
guarde en p3 el punto medio.   */

void medio(PUNTO p1, PUNTO p2, PUNTO *p3);

int main()
{
    PUNTO A = {2,4}; //Valores fijos
    PUNTO B = {1,3}; //Valores fijos
    PUNTO M;

    printf("\nLas cordenadas del punto A: (%.2f , %.2f) ",A.x,A.y);
    printf("\nLas cordenadas del punto B: (%.2f , %.2f) ",B.x,B.y);

    medio(A,B,&M);

    printf("\n\nLas cordenadas del punto Medio: (%.2f , %.2f) \n\n",M.x,M.y);

    system("PAUSE");
    return 0;
}

void medio(PUNTO p1, PUNTO p2, PUNTO *p3)
{
    p3->x = (p1.x + p2.x)/2;
    p3->y = (p1.y + p2.y)/2;
}

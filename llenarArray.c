void llenar(int *arr, int n){
    printf("\n\nLlena el arreglo: ");
    for(int i=0; i<n; i++)
    {
        printf("\nIngresa el valor de la posicion [%d]: ", i+1);
        scanf("%d",(arr+i));
    }
}

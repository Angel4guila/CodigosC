#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void LeerArchivo(int A[], int numeros){
    FILE *archivo;
    
    if(numeros == 1000){
        archivo = fopen("milnumeros.txt", "r");
    }else if(numeros == 10000){
        archivo = fopen("diezmilnumeros.txt", "r");
    }else if(numeros == 100000){
        archivo = fopen("cienmilnumeros.txt", "r");
    }else if(numeros == 1000000){
        archivo = fopen("millonnumeros.txt", "r");
    }else if(numeros == 2000000){
        archivo = fopen("dosmillonesnumeros.txt", "r");
    }

    if(archivo == NULL){
        printf("No se pudo abrir el archivo\n");
        return;
    }

    for(int i = 0; i < numeros; i++){
        fscanf(archivo, "%d", &A[i]);
    }

    fclose(archivo);
}

void ArchivoOrdenado(int A[], int numeros){
    FILE *archivoO;

    if(numeros == 1000){
        archivoO = fopen("milOrdenados.txt", "w");
    }else if(numeros == 10000){
        archivoO = fopen("diezmilOrdenados.txt", "w");
    }else if(numeros == 100000){
        archivoO = fopen("cienmilOrdenados.txt", "w"); 
    }else if(numeros == 1000000){
        archivoO = fopen("millonOrdenados.txt", "w");  
    }else if(numeros == 2000000){
        archivoO = fopen("dosmillonesOrdenados.txt", "w");
    }

    if(archivoO == NULL){
        printf("El archivo no se pudo crear\n");
        return;
    }

    printf("Archivo ordenado correctamente con Shell Sort...\n");

    for(int i = 0; i < numeros; i++){
        fprintf(archivoO, "%d\n", A[i]);
    }
    fclose(archivoO);
}

void ShellSort(int A[], int n){
    int paso,i,j,temp;

    paso = n/2;

    while(paso >0){

        for(i=paso; i<n;i++){
            temp = A[i];
            for(j=i;j>=paso;j-=paso){
                if(A[j-paso] > temp){
                    A[j]=A[j-paso];
                }else{
                    break;
                }
            }
            A[j] = temp;
        }

        paso = paso/2;
    }

}

int main(){
    int *A = NULL;
    int n = 3;
    int numeros = 0;

    if(n == 1){
        numeros = 1000;
    }else if(n == 2){
        numeros = 10000;    
    }else if(n == 3){
        numeros = 100000;
    }else if(n == 4){
        numeros = 1000000;
    }else if(n == 5){
        numeros = 2000000;  
    }else{
        printf("Opcion invalida\n");
        return 0;    
    }

    A = (int *)malloc(numeros * sizeof(int));

    if(A == NULL){
        printf("Error, no hay memoria suficiente\n");
        return 0;
    }

    LeerArchivo(A, numeros);
    ShellSort(A, numeros);
    ArchivoOrdenado(A, numeros);

    free(A);

    return 0;
}


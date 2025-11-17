#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CrearyGenerar(int numeros){
    FILE *archivo;
    if(numeros == 1000){
        archivo = fopen("milnumeros.txt", "w");
    }else if(numeros==10000){
        archivo = fopen("diezmilnumeros.txt", "w");
    }else if(numeros==100000){
        archivo = fopen("cienmilnumeros.txt", "w");
    }else if(numeros==1000000){
        archivo = fopen("millonnumeros.txt", "w");
    }else if(numeros==2000000){
        archivo = fopen("dosmillonesnumeros.txt", "w");
    }
    
    if (archivo != NULL){
        printf("Archivo correctamente creado\n");
    }else{
        printf("El archivo no se pudo crear\n");
    }


    if(numeros > 0){
        for(int i=0; i < numeros; i++){
            int numero = rand() %100;
            fprintf(archivo, "%d\n", numero);   
            
        } 
        printf("Numeros generados correctamente\n");
        fclose(archivo);
    }else{
        printf("No fue posible generar los numeros\n");
    }

    
    

};//Fin de crearygenerar

void LeerArchivo( int A[], int numeros){
    FILE *archivo;
    
    if(numeros == 1000){
        archivo = fopen("milnumeros.txt", "r");
    }else if(numeros==10000){
        archivo = fopen("diezmilnumeros.txt", "r");
    }else if(numeros==100000){
        archivo = fopen("cienmilnumeros.txt", "r");
    }else if(numeros==1000000){
        archivo = fopen("millonnumeros.txt", "r");
    }else if(numeros==2000000){
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
};//Fin leerarchivo

void ArchivoOrdenado( int A[], int numeros){
    FILE *archivoO;

    if(numeros == 1000){
        archivoO = fopen("milOrdenados.txt", "w");
    }else if(numeros==10000){
        archivoO = fopen("diezmilOrdenados.txt", "w");
    }else if(numeros==100000){
        archivoO = fopen("cienmilOrdenados.txt", "w"); 
    }else if(numeros==1000000){
        archivoO = fopen("millonOrdenados.txt", "w");  
    }else if(numeros==2000000){
        archivoO = fopen("dosmillonesOrdenados.txt", "w");
    }

    if (archivoO != NULL){
        printf("Archivo de ordenamiento correctamente creado...\n");
    }else{
        printf("El archivo no se pudo crear\n");
    }

    for(int i = 0; i < numeros; i++){
        fprintf(archivoO, "%d\n", A[i]);
    }
    fclose(archivoO);
};//Fin archivoordenado


void Burbuja(int A[], int n){
    int aux;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < n-1; j++){
            if(A[j] > A[j+1]){
            aux = A[j];
            A[j] = A[j+1];
            A[j+1] = aux;
            }
        }
    }
}//fin burbuja

int main (){

    srand(time(NULL));
    int *A = NULL;
    int n = 0;
    int numeros = 0;

    printf("==============Ordenaminto Burbuja===============\n");
    printf("Cantidades Recordadas:\n");
    printf("1. 1000 numeros\n");
    printf("2. 10,000 numeros\n");          
    printf("3. 100,000 numeros\n");
    printf("4. 1,000,000 numeros\n");
    printf("5. 2,000,000 numeros\n");
    printf("Opcion: ");
    scanf("%d", &n );

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
    }

    CrearyGenerar(numeros);
    A = (int *)malloc(numeros * sizeof(int));

    if(A == NULL){
    printf("Error, no hay memoria suficiente\n");
    return 0;
}

    LeerArchivo( A, numeros);
    Burbuja(A, numeros);
    ArchivoOrdenado( A, numeros);

    free(A);
    A = NULL;
    return 0;


}
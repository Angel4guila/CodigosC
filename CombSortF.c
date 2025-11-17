#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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


void Combsort(int A[], int n){
    int fd = n;
    int cambio;
    int ayuda;  

    do{

        fd = floor (fd/1.3);

        if(fd < 1) fd = 1;

        cambio = 0;

        for(int i = 0 ; i + fd <n ; i++ ){
            if(A[i] > A[i + fd]){
                ayuda = A[i];
                A[i] = A[i + fd];
                A[i+ fd] = ayuda;
                cambio = 1;

            }
        }
    } while (fd != 1 || cambio == 1);

}//fin combsort

int main (){

    srand(time(NULL));
    int *A = NULL;
    int n = 0;
    int numeros = 0;

    printf("==============Ordenaminto Comb Sort===============\n");
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
    Combsort(A, numeros);
    ArchivoOrdenado( A, numeros);

    free(A);
    A = NULL;
    return 0;


}
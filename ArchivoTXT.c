#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void CrearyGenerar(int n){
    FILE *archivo;
    if(n == 1000){
        archivo = fopen("milnumeros.txt", "w");
    }else if(n==10000){
        archivo = fopen("diesmilnumeros.txt", "w");
    }else if(n==100000){
        archivo = fopen("cielmilnumeros.txt", "w");
    }else if(n==1000000){
        archivo = fopen("millonnumeros.txt", "w");
    }else if(n==2000000){
        archivo = fopen("dosmillonesnumeros.txt", "w");
    }
    
    if (archivo != NULL){
        printf("Archivo correctamente creado\n");
    }else{
        printf("El archivo no se pudo crear\n");
    }


    if(n > 0){
        for(int i=0; i < n; i++){
            int numero = rand() %100;
            fprintf(archivo, "%d\n", numero);   
            
        } 
        printf("Numeros generados correctamente\n");
        fclose(archivo);
    }else{
        printf("No fue posible generar los numeros\n");
    }

    fclose(archivo);
    

};




int main(){

    srand(time(NULL));

    int op;
    int n;

    do
    {
        printf("===========Menu===========\n");
        printf("1. Crear y llenar archivo\n");
        printf("2. Salir\n");
        scanf("%d", &op);

        switch(op){

            case 1: 
                int opp;
                do{
                    printf("====Elija la cantidad de numeros====\n");
                    printf("1. 1000 numeros\n");
                    printf("2. 10,000 numeros\n");
                    printf("3. 100,000 numeros\n");
                    printf("4. 1,000,000 numeros\n");
                    printf("5. 2,000,000 numeros\n");
                    scanf("%d", &opp);
                
                    switch (opp){
                        case 1:
                            n = 1000;
                            break;
                        case 2:
                            n = 10000;
                            break;
                        case 3:
                            n = 100000;
                            break;
                        case 4:
                             n = 1000000;
                             break;
                        case 5:
                            n = 2000000;
                            break;
                        default:
                        break;
                    }
                } while (opp != 5 && opp !=4 && opp !=3 && opp !=2 && opp !=1);

                CrearyGenerar(n);
                

                break;

            case 2:
                printf("Saliendo...\n");
                
                
                break;

            default:
                printf("Opcion invalida\n");
                break;
        }
       
    } while (op != 2);
    



    return 0;
}
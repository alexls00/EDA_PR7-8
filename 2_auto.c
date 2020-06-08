#include<stdio.h>
#include<stdlib.h>
#include "listacirc_auto.h"

void menu(Lista lista1);
void main(){
	
    Lista lista1=crearLista();
 	printf("->Seleccione una opcion: \n");
    menu(lista1);
}

void menu(Lista lista1){
    int opcion;
    Auto auto1;
    do{
        print_list(lista1);
        printf("\n\t1) Agregar al principio");
        printf("\n\t2) Agregar al final");
        printf("\n\t3) Eliminar al inicio");
        printf("\n\t4) Eliminar al final");
        printf("\n\t5) Recorrer lista");
        printf("\n\t6) Buscar auto por su marca");
        printf("\n\t7) Salir\n");
        scanf("%d",&opcion);
        system("cls"); 
    
        switch (opcion)
        {
        case 1:
            auto1 = leerAuto();
            addPrincipioLista(&lista1,auto1);
            system("cls"); 
            break;
        case 2:
            auto1 = leerAuto();
            addFinalLista(&lista1,auto1);
            system("cls"); 
            break;
        case 3:
            borrarPrimero(&lista1);
            system("cls"); 
            break;
        case 4:
            borrarUltimo(&lista1);
            system("cls"); 
            break;
        case 5:
            recorrerLista(&lista1);
            break;
        case 6:
            buscarAuto(&lista1);
            break;
        }
    } while(opcion!=7);

}
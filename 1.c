#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

void menu(Lista lista1);
void main(){
	
    Lista lista1=crearLista();
 	printf("->Seleccione una opcion: \n");
    menu(lista1);
}

void menu(Lista lista1){
    int n,opcion,num;
    do{
        print_list(lista1);
        printf("\n\t1) Agregar al principio");
        printf("\n\t2) Agregar al final");
        printf("\n\t3) Agregar i-esimo");
        printf("\n\t4) Eliminar al inicio");
        printf("\n\t5) Eliminar al final");
        printf("\n\t6) Buscar");
        printf("\n\t7) Eliminar n-esimo");
        printf("\n\t8) Eliminar mayores");
        printf("\n\t9) Salir\n");
        scanf("%d",&opcion);
        system("cls"); 
    
        switch (opcion)
        {
        case 1:
            printf("\n\n\t Ingrese el elemento que desea agregar: ");
            scanf("%d",&num);
            addPrincipioLista(&lista1,num);
            system("cls"); 
            break;
        case 2:
            printf("\n\n\t Ingrese el elemento que desea agregar: ");
            scanf("%d",&num);
            addFinalLista(&lista1,num);
            system("cls"); 
            break;
        case 3:
            printf("\n\n\t Ingrese el elemento que desea agregar: ");
            scanf("%d",&num);
            addIesimoLista(&lista1,num);
            system("cls"); 
            break;
        case 4:
            borrarPrimero(&lista1);
            system("cls"); 
            break;
        case 5:
            borrarUltimo(&lista1);
            system("cls"); 
            break;
        case 6:
            buscar(lista1);
            break;
        case 7:
            borrarEnesimo(&lista1);
            break;
        case 8:
            lista1 = borrarMayores(&lista1);
            break;
        }
    } while(opcion!=9);

}
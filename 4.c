#include<stdio.h>
#include<stdlib.h>
#include "listaDobleCircular.h"

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
        printf("\n\t3) Eliminar al inicio");
        printf("\n\t4) Eliminar al final");
        printf("\n\t5) Recorrer lista");
        printf("\n\t6) Salir\n");
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
        }
    } while(opcion!=6);

}
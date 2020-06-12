#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Auto{
    char marca[20];
	char modelo[20];
	char placas[20];
	char color[20];
}Auto;

typedef struct Nodo{
    Auto carro;
    struct Nodo* next;
}Nodo;

typedef struct{
	struct Nodo* head;
	int tamano;
}Lista;

Lista crearLista();
void print_list(Lista);
void addPrincipioLista(Lista*,Auto);
void addFinalLista(Lista*,Auto);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
void recorrerLista(Lista*);
void buscarAuto(Lista*);
Auto leerAuto();

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	lista.tamano = 0;
	return lista;
}

Auto leerAuto(){
	Auto auto1;
	printf("Ingrese los elementos del auto:\n");
	printf("->Marca: ");
	scanf("%s",&auto1.marca);
	printf("->Modelo: ");
	scanf("%s",&auto1.modelo);
	printf("->Color: ");
	scanf("%s",&auto1.color);
	printf("->Placas: ");
	scanf("%s",&auto1.placas);
	return auto1;
}

void print_list(Lista lista) {
    if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
		int i=0;
    	int tamano = lista.tamano;				//se define el tama�o
		printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head;
   		while (tamano > 0 ) {					//tama�o como condicional
		    printf("\n->Auto %d\n",i);
        	printf("\tMarca: %s \n", current->carro.marca);
			printf("\tModelo: %s \n", current->carro.modelo);
			printf("\tColor: %s \n", current->carro.color);
			printf("\tPlacas: %s \n", current->carro.placas);
        	current = current->next;
        	tamano--;                           //se reduce tama�o
			i++;
		}
	}
}

void addFinalLista(Lista *lista, Auto auto1) {
	int posicion=lista->tamano;
	if(lista->head==NULL){
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
		nodo->carro = auto1;
    	nodo->next = nodo;
    	lista->head = nodo;
	}	
	else
	{
		Nodo *current = lista->head;
		while (posicion!=1) {
       		current = current->next;
       		posicion--;
 		}
		Nodo *nuevoNodo;
		nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    	current->next = nuevoNodo;
		nuevoNodo->carro = auto1;
    	nuevoNodo->next = lista->head;
 		
	}	
	lista->tamano++; 
}
void addPrincipioLista(Lista *lista, Auto auto1) {
	
	Nodo *node,*temp;
    node = (Nodo*)malloc(sizeof(Nodo));
    node->carro = auto1;
    if(lista->head==NULL){
    	node->next=node;
	}
    else{
    	node->next = lista->head;
		temp = lista->head;
    	while(temp->next != lista->head){
    		temp=temp->next;
		}
		temp->next=node;
	}
	lista->head = node;
    lista->tamano++;
}
void borrarPrimero(Lista *lista) {
    if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	Nodo *nuevo_head = NULL;
    	Nodo *temp = lista->head;
    	nuevo_head=temp->next;
    	free(lista->head);
    	lista->head = nuevo_head;
		lista->tamano--;
	}
}

void borrarUltimo(Lista *lista) {
    Nodo *tmp = lista->head;
	if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	Nodo *tmp=lista->head;
		while(tmp->next->next != lista->head){
			tmp=tmp->next;
		}
		free(tmp->next);
		tmp->next=lista->head;
	lista->tamano--;
	}
}

void buscarAuto(Lista *lista){
	system("cls");
	char marca[20];
	Nodo *tmp = lista->head;
	Lista encontrados=crearLista();
	printf("Ingrese la marca a buscar: ");
	scanf("%s",&marca);
	for (int i=0; i<lista->tamano; i++){
		tmp=tmp->next;
		if (strcmp(marca,tmp->carro.marca)==0){
			addFinalLista(&encontrados,tmp->carro);
		}
	}
	printf("COINCIDENCIAS: ");
	print_list(encontrados);
	system("timeout 10");
	system ("cls");
	return;
}

void recorrerLista(Lista* lista){
	system("cls");
	int i = 0;
	Nodo *tmp;
	tmp = lista->head;
	char bot;
	while (1){
		printf("s+Enter para ver siguiente elemento\n");
		printf("q+Enter para regresar al menu\n");
		printf("Auto %d: \n",i);
		printf("\tMarca: %s \n", tmp->carro.marca);
		printf("\tModelo: %s \n", tmp->carro.modelo);
		printf("\tColor: %s \n", tmp->carro.color);
		printf("\tPlacas: %s \n", tmp->carro.placas);
		getchar();
		scanf("%c",&bot);
		if (bot=='s'){
			system("cls");
			tmp=tmp->next;
			i++;
			if (tmp==lista->head){i=0;}
		}
		else if (bot=='q'){
			system("cls");
			return;
		}
		else{
			system("cls");
			printf("error. Intente de nuevo\n");
		}
		
	} 
}


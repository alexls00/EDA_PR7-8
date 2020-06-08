#include<stdio.h>
#include<stdlib.h>
typedef struct Nodo{
    int val;
    struct Nodo* next;
}Nodo;

typedef struct{
	struct Nodo* head;
	int tamano;
}Lista;

Lista crearLista();
void print_list(Lista);
void addPrincipioLista(Lista*,int);
void addFinalLista(Lista*,int);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
void recorrerLista(Lista);

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	lista.tamano = 0;
	return lista;
}

void print_list(Lista lista) {
    if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
    	int tamano = lista.tamano;				//se define el tama�o
		printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head;
   		while (tamano > 0 ) {					//tama�o como condicional
        	printf("%d \n", current->val);
        	current = current->next;
        	tamano--;                           //se reduce tama�o
   	 	}
	}
}

void addFinalLista(Lista *lista, int val) {
	int posicion=lista->tamano;
	if(lista->head==NULL){
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
		nodo->val = val;
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
		nuevoNodo->val = val;
    	nuevoNodo->next = lista->head;
 		
	}	
	lista->tamano++; 
}
void addPrincipioLista(Lista *lista, int val) {
	
	Nodo *node,*temp;
    node = (Nodo*)malloc(sizeof(Nodo));
    node->val = val;
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
	}
	lista->tamano--;
}

void borrarUltimo(Lista *lista) {
    Nodo *temp = lista->head;
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



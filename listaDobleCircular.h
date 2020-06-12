#include<stdio.h>
#include<stdlib.h>


typedef struct Nodo{
    int val;
    struct Nodo* next;
    struct Nodo* prev;
}Nodo;

typedef struct{
	int tamano;
	struct Nodo* head;
}Lista;

Lista crearLista();
void print_list(Lista);
void addPrincipioLista(Lista*,int);   
void addFinalLista(Lista*,int);
void primerNodo(Lista*,int);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
void recorrerLista(Lista*);

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	lista.tamano=0;
	return lista;
}

void print_list(Lista lista) {
    int tamano = lista.tamano;
	if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
    	printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head;
   		while (tamano>0){
		   printf("%d\n",current->val) ;
		   current = current->next; 
		   tamano--;
		}	
	}
}

void addFinalLista(Lista *lista, int val) {
	if(lista->head==NULL){
		primerNodo(lista,val);
	}	
	else
	{
		Nodo *new_node, *temp;
    	new_node = (Nodo*)malloc(sizeof(Nodo));
    	new_node->val = val;
    	new_node->next = lista->head;
    	new_node->prev = lista->head->prev;
		lista->head->prev=new_node;
		temp=lista->head;
		
		while(temp->next!=lista->head)
			temp=temp->next;
    	temp->next=new_node;
	}	
	lista->tamano++;
}

void addPrincipioLista(Lista *lista, int val) {
	if(lista->head==NULL){
		primerNodo(lista,val);
	}	
	else{
		Nodo *new_node, *temp;
    	new_node = (Nodo*)malloc(sizeof(Nodo));
    	new_node->val = val;
    	new_node->next = lista->head;
    	new_node->prev = lista->head->prev;
    	lista->head->prev=new_node;
		
		temp=lista->head;
		
		while(temp->next!=lista->head)
			temp=temp->next;
    	temp->next=new_node;
		
		lista->head = new_node;
	}
	lista->tamano++;
}

void primerNodo(Lista *lista, int val){
	Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
	nodo->val = val;
    nodo->next = nodo;
    nodo->prev = nodo;
    lista->head = nodo;
}

void borrarPrimero(Lista *lista) {
    if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	Nodo *nuevo_head = NULL;
		Nodo *tmp=lista->head;
		nuevo_head=tmp->next;
		free(lista->head);
		lista->head = nuevo_head;
		lista->tamano--;
	}
}

void borrarUltimo(Lista *lista) {
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
		lista->head->prev = tmp;
		lista->tamano--;
	}

}

void recorrerLista(Lista* lista){
	system("cls");
	int i = 1;
	Nodo *tmp;
	tmp = lista->head;
	char bot;
	while (1){
		printf("s+Enter para ver siguiente elemento\n");
		printf("a+Enter para ver elemento anterior\n");
		printf("q+Enter para regresar al menu\n");
		printf("Elemento %d: %d\n",i,tmp->val);
		getchar();
		scanf("%c",&bot);
		if (bot=='s'){
			system("cls");
			tmp=tmp->next;
			i++;
			if (tmp==lista->head){i=1;}
		}
		else if(bot=='a'){
			system("cls");
			tmp=tmp->prev;
			i--;
			if (tmp->next==lista->head){i=lista->tamano;}
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




#include<stdio.h>
#include<stdlib.h>


typedef struct Nodo{
    int val;
    struct Nodo* next;
}Nodo;

typedef struct{
	struct Nodo* head;
}Lista;

Lista crearLista();
void print_list(Lista);
void addPrincipioLista(Lista*,int);  
void addFinalLista(Lista*,int);
void addIesimoLista(Lista *lista, int val);
void borrarPrimero(Lista*);
void borrarUltimo(Lista*);
int primerElemento(Lista);
void buscar(Lista lista);
void borrarEnesimo(Lista *lista);
Lista borrarMayores(Lista *lista);

Lista crearLista(){
	Lista lista;
	lista.head = NULL;
	return lista;
}

void print_list(Lista lista) {
    if(lista.head==NULL){
    	printf("LA LISTA ESTA VACIA \n");
    }
    else{
    	printf("Los elementos de la lista son: \n");
    	Nodo *current = lista.head;
   		while (current != 0) {
        	printf("%d \n",current->val);
			current = current->next;
   	 	}
	}
}

void addFinalLista(Lista *lista, int val) {
	if(lista->head==NULL){
		
		Nodo *nodo = (Nodo*)malloc(sizeof(Nodo));
		nodo->val = val;
    	nodo->next = NULL;
    	lista->head = nodo;
	}	
	else
	{
		Nodo *current = lista->head;
		while (current->next != 0) {
       		current = current->next;
 		}
		Nodo *nuevoNodo;
		nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    	nuevoNodo->val = val;
    	nuevoNodo->next = NULL;
 		current->next = nuevoNodo;
	}	
}
void addPrincipioLista(Lista *lista, int val) {
	Nodo *new_node;
    new_node = (Nodo*)malloc(sizeof(Nodo));
    new_node->val = val;
    new_node->next = lista->head;
    lista->head = new_node;
}

void addIesimoLista(Lista *lista, int val){
	
	int contador, posicion;
	printf("Ingrese la posicion");
	scanf("%d",&posicion);
	Nodo *temp;   //creacion de nodo temporal para recorrer la lista
    temp=lista->head;
		
	for(contador=1;contador<posicion-1;contador++)   {
	      temp=temp->next;
    
	}
	Nodo *nuevoNodo;
	nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
   	nuevoNodo->val = val;
   	nuevoNodo->next = temp->next;
	temp->next = nuevoNodo;
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
}

void borrarUltimo(Lista *lista) {
    Nodo *temp = lista->head;
	if (lista->head == NULL) {
        printf("La lista esta vacia");
    }
    else{
    	if(temp->next==NULL){
    		lista->head = NULL;
			free(lista->head);	
    	}else{
    		Nodo *current = lista->head;
    		while (current->next->next != NULL) {
        		current = current->next;
    		}
    		current->next = NULL;
			free(current->next);
    		
    	}
	}

}

int primerElemento(Lista lista){
	return lista.head->val;
}
void buscar(Lista lista){
		
		Nodo *tmp = lista.head;
		int num;
		int c=0;
		printf("Elemento que desea buscar: ");
		scanf("%d",&num);

		while(tmp->val != num){
			if(lista.head==NULL){
    			printf("LA LISTA ESTA VACIA \n");
				return;
    		}
			if(tmp->next == NULL){
				printf("No hay coincidencias\n");
				return;
			} 
			c++; 
			tmp = tmp->next;
			
		}
		printf("Coincidencia en la posicion %d\n",c);			
	}
void borrarEnesimo(Lista *lista){
	int pos;
	printf("Ingrese la posicion: ");
	scanf("%d",&pos);
	Nodo *tmp; 
	Nodo *tmp2; 
    tmp=lista->head;
	if (lista->head == NULL) {
        printf("La lista esta vacia");
		return;
    }
    else{
		for(int c=0;c<pos-1;c++){
			tmp=tmp->next;
		}
		tmp2=tmp->next;
		tmp->next=tmp2->next;
		free(tmp2);
		return;
	}
}

Lista borrarMayores(Lista *lista){

	Lista trash=crearLista();
	Lista listaChida=crearLista();
	int num;
	printf("Se eliminaran los numeros mayores a: ");
	scanf("%d",&num);
	Nodo* tmp;
	tmp=lista->head;
	while(1){
		if (tmp->val <= num){
			addFinalLista(&listaChida,tmp->val);
		}
		else{
			addFinalLista(&trash,tmp->val);
		}

		if (tmp->next==NULL){
			break;
		}
		else{
		tmp=tmp->next;
		}
	}
	if(trash.head==NULL){
    	printf("NO HUBO ELEMENTOS MAYORES \n");
		return listaChida;
    }
	else{
		printf("Los elementos eliminados fueron: \n");
		Nodo *current1 = trash.head;
   		while (current1 != 0) {
        	printf("%d \n",current1->val);
			current1 = current1->next;
		}
		return listaChida; 
	}
}

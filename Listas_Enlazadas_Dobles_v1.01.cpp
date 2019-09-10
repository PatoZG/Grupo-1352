 /*----------------------------------------*/
/*-----Librería de Listas Enlazadas Dobles-----*/
/*----------------------------------------*/
/*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*
 * Descripción:
        Este programa utiliza Listas Enlazadas Sencillas
        Las operaciones que realiza son:
                Crear Nodo
                Size()
                PushFront(val)
                PopFront()
                PushBack(val)
                PopBack()
                Insert(i, val)

  Este programa es de código abierto (Open Source). Te invitamos a mejorarlo y
extender sus funcionalidades!
  Cuando termines por favor registrate y cambia el nombre del archivo.

  Registro de Revisiones
  ----------------------------------------------------------------------------
  | Fecha                       Revisión                Desarrollador                   Comentarios      |
  ----------------------------------------------------------------------------
  | 26/8/2019          1.01                    Grupo 1352                          Revisión Inicial


*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*/

#include<stdio.h>
#include<stdlib.h>

//Se declara la estructura
typedef struct nodo
{
	float e;
	struct nodo *sig;
	struct nodo *ant;
}NODO;

//Se inicializan las variables a utilizar.

float val;
float e;
int tam = 0;

NODO *cab = NULL;
NODO *aux1 = NULL;
NODO *aux2 = NULL;

//Se inicializan las funciones a utilizar.

NODO* crearNodo(float val);
void ListaDoble_PushFront(float val);
void ListaDoble_PopFront(NODO* ptr);
void imprimir(NODO *ptr);
int ListaDoble_Size(NODO *ptr);
void ListaDoble_Remove(NODO ** ptr, float val);
NODO* ListaDoble_buscar(float val);
    
int main()
{
    
    int op = 1;
    
    while(op != 0)
    {
    	
		printf("\nSelecciona la opcion deseada:\n");
		printf("1.- PushFront\n");
		printf("2.- Imprimir valores de Lista\n");
		printf("3.- PopFront\n");
		printf("4.- Remove\n");
		printf("5.- Size\n");
		printf("6.- Buscar nodo\n");
		printf("0.- Salir\n");
		scanf("%d", &op);
		
		switch (op){
			case 1:
				printf("\nIngresa el valor para PushFront:\n");
				scanf("%f", &val);
				
				ListaDoble_PushFront(val);
		    
		        break;

			case 2:
				imprimir(cab);
				break;
				
			case 3:
				ListaDoble_PopFront(cab);
				break;
			
			case 4:
				printf("\nIngresa el valor del nodo a eliminar:\n");
				scanf("%f", &val);
				
				ListaDoble_Remove(&cab, val);
				break;
			
			case 5:
				tam  = ListaDoble_Size(cab);
				printf("\nEl tamaño de la lista es: %d\n", tam);
				break;
			
			case 6:
				printf("\nIngresa el valor del nodo a buscar:\n");
				scanf("%f", &val);
				
				aux1 = ListaDoble_buscar(val);
				
				if (aux1 != NULL)
				{
					printf("\nNodo encontrado en la direccion: %d\n", aux1);
				}else
				{
					printf("\nNodo no encontrado\n");
				}
		}
		
    }

}

NODO* crearNodo(float val)
{
	NODO *ptr;
	
	ptr = (NODO*) malloc(sizeof(NODO));
	
	ptr->e = val;
	ptr->sig = NULL;
	ptr->ant = NULL;
	
	return ptr;
}


void ListaDoble_PushFront(float val)
{
	NODO* ptr;
	ptr = (NODO*)malloc(sizeof(NODO));
	
	ptr->e = val;
	ptr->sig = cab;
	cab = ptr;
	
	if(ptr->sig != NULL)
	{
		ptr->sig->ant = ptr;
	}
	
}

void imprimir(NODO *ptr)
{
	printf("%f ", ptr->e);
	
	if(ptr->sig != NULL)
	{
		imprimir(ptr->sig);
	}
}

void ListaDoble_PopFront(NODO *ptr)
{
	/*NODO* aux= ptr->sig ;
	
	(ptr->sig)->ant=NULL;
	free(ptr);
	ptr = aux;*/
	aux1=cab;
	aux2=cab->sig;
	cab=aux2;
	cab->ant = NULL;
	free(aux1);
	
}

int ListaDoble_Size(NODO *ptr)
{
	if(ptr->sig != NULL){
		return ListaDoble_Size(ptr->sig)+1;
	}
	else{
		return 1;
	}
}

void ListaDoble_Remove(NODO ** ptr, float val)
{
	NODO * aux = *ptr;
	
	while (aux != NULL) {
		if (aux->e == val) 
		{
				
			if (cab == aux)
			{
				cab=aux->sig;
				aux->sig->ant = NULL;
				free(aux);
				return;
			}
			if (aux->sig == NULL)
			{
				aux->ant->sig= NULL;
				free (aux);
				return;
			}
			else{
				aux->ant->sig = aux->sig;
				aux->sig->ant = aux->ant;
			
				free(aux);
				return;
			}
		
		}
		
		aux= aux->sig;
	}
}

NODO* ListaDoble_buscar(float val)
{
	NODO *ptr=NULL;
	ptr=cab;
	
	while( ptr != NULL){
		if(ptr->e == val){
		break;
		}
		ptr= ptr->sig;
	}
		
	return ptr;
	
		
	
	
	
}

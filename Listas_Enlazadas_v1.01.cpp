 /*----------------------------------------*/
/*-----Librería de Listas Enlazadas-----*/
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
void ListaSimple_PushFront(float val);
void ListaSimple_PopFront(NODO* ptr);
void imprimir(NODO *ptr);
int ListaSimple_Size(NODO *ptr);
void ListaSimpe_InsertAfter(NODO * ptr, float val, float elem);
NODO recorrer(NODO*,float);
    
int main()
{
    
    int op = 1;
    
    while(op != 0)
    {
    	
		printf("\nSelecciona la opcion deseada:\n");
		printf("1.- PushFront\n");
		printf("2.- Imprimir valores de Lista\n");
		printf("3.- PopFront\n");
		printf("4.- Insert After\n");
		printf("5.- Size\n");
		printf("0.- Salir\n");
		scanf("%d", &op);
		
		switch (op){
			case 1:
				printf("\nIngresa el valor para PushBack:\n");
				scanf("%f", &val);
				
				ListaSimple_PushFront(val);
		    
		        break;

			case 2:
				imprimir(cab);
				break;
				
			case 3:
				ListaSimple_PopFront(cab);
				break;
			
			case 4:
				printf("\nIngresa el valor para insertar:\n");
				scanf("%f", &val);
				
				printf("\nIngresa el valor del nodo previo a la inserción:\n");
				scanf("%f", &e);
				
				ListaSimpe_InsertAfter(cab, val, e);
				break;
			
			case 5:
				tam  = ListaSimple_Size(cab);
				printf("\nEl tamaño de la lista es: %d\n", tam);
			
		}
		
    }

}

NODO* crearNodo(float val)
{
	NODO *ptr;
	
	ptr = (NODO*) malloc(sizeof(NODO));
	
	ptr->e = val;
	ptr->sig = NULL;
	
	return ptr;
}


void ListaSimple_PushFront(float val)
{
	aux2=(NODO*)malloc(sizeof(NODO));
	aux2->e=val;
	aux2->sig=cab;
	cab=aux2;
	aux2 = NULL;
	
}

void imprimir(NODO *ptr)
{
	printf("%f ", ptr->e);
	
	if (ptr->sig != NULL)
	{
		imprimir(ptr->sig);
	}
}

void ListaSimple_PopFront(NODO *ptr)
{
	//aux1=(NODO*)malloc(sizeof(NODO));
	//aux2=(NODO*)malloc(sizeof(NODO));
	//aux2=ptr->sig->sig;
	//ptr->sig=NULL;
	//free(ptr);
	//ptr->sig=aux2;
	//funcion pop front
	aux1=cab->sig;
	aux2=cab;
	cab=aux1;
	free(aux2);
	
}

int ListaSimple_Size(NODO *ptr)
{
	if (ptr->sig != NULL)
	{
		return ListaSimple_Size(ptr->sig) + 1;
	}
	else
	{
		return 1;
	}
}

void ListaSimpe_InsertAfter(NODO * ptr, float val, float elem)
{
	
	if (ptr->e == val)
	{
		aux2 = crearNodo(elem);
		aux2->sig = ptr->sig;
		ptr->sig = aux2;
		return;
	} else
	{
		ListaSimpe_InsertAfter(ptr->sig, val, elem);
	}

}
/*NODO recorrer(NODO*z,float n)
{
	if(z->sig!=NULL)
	{
		if(z->e==n)
		{
			return(z);
		}else
		{
			recorrer(z->sig,n);
		}
	}
}*/

 /*----------------------------------------*/
/*-----Librería de Arreglos Dinámicos-----*/
/*----------------------------------------*/
/*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*
 * Descripción:
        Este programa utiliza Arreglos Dinámicos
        Las operaciones que realiza son:
                Extender Arreglo !No funciona!
                Reducir Arreglo
				Get(i)
                Set(i, val)
                Size()
                PushFront(val)
                PopFront()
                Insert(i, val)
                Remove(i) O(1)

  Este programa es de código abierto (Open Source). Te invitamos a mejorarlo y
extender sus funcionalidades!
  Cuando termines por favor registrate y cambia el nombre del archivo.

  Registro de Revisiones
  ----------------------------------------------------------------------------
  | Fecha                       Revisión                Desarrollador                   Comentarios      |
  ----------------------------------------------------------------------------
  | 16/8/2019          1.01                    Grupo 1352                          Revisión Inicial


*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*--*-*-*-*-*-*-*-*-*-*-*/

#include<stdio.h>
#include<stdlib.h>

typedef struct arreglo
{
    int *ptr; //Apuntador.
    int tam;   //Variable para guardar el valor del tamaño.
    int cap;   //Variable para guardar el valor de la capacidad.
};

//Se inicializan las variables a utilizar.
arreglo arreglo1 = {(int*) malloc(1 * sizeof(int)),0, 1}; ///modifique esta linea, el tamaño ahora esta inicializado en 1 y la capacidad inicial es de 4

int val;

//Se inicializan las funciones a utilizar.
    
void ArregloD_PushBack(int input);
void ArregloD_PopBack();
void imprimir();
void extenderArreglo();

int main()
{
    
    int op = 1;
    
    while(op != 0)
    {
    	
		printf("\nSelecciona la opcion deseada:\n");
		printf("1.- PushBack\n");
		printf("2.- Imprimir Arreglo\n");
		printf("3.- PopBack\n");
		printf("0.- Salir\n");
		scanf("%d", &op);
		
		switch (op){
			case 1:
				printf("\nIngresa el valor para PushBack:\n");
				scanf("%d", &val);
		    
		        ArregloD_PushBack(val);
		        break;

			case 2:
				imprimir();
				break;
				
			case 3:
				ArregloD_PopBack();
				break;
			
		}
		
    }

}

void ArregloD_PushBack(int input) ///modifique esta  funcion, faltaba aumentar el tamaño en uno cada vez que se agrega un elemento
{
	
	if(arreglo1.tam == arreglo1.cap){
		extenderArreglo();
	}
	
	*(arreglo1.ptr + (arreglo1.tam)*sizeof(int))=input;
	arreglo1.tam++;
	printf("Tamano del arreglo: %d \tCapacidad del arreglo: %d\n", arreglo1.tam, arreglo1.cap);

}

void imprimir()
{
	printf("\nEl arreglo tiene los siguientes valores\n");
	
	for (int i = 0; i < arreglo1.tam; i++)
	{
		printf("%d ", *(arreglo1.ptr + i*sizeof(int)));
	}
	
	printf("\n");
}

void ArregloD_PopBack()
{

	*(arreglo1.ptr + (arreglo1.tam)*sizeof(int)) = 0;
	arreglo1.tam--;

	if (arreglo1.tam == arreglo1.cap/2)
	{
		//reducir arreglo
	}
	
}

void extenderArreglo()
{
	arreglo1.cap = arreglo1.cap * 2;
	
	int *ptr2;
	
	ptr2 = (int*) malloc(arreglo1.cap * sizeof(int));
	for (int i = 0; i < arreglo1.tam; i++)
	{
		*(ptr2 + i*sizeof(int)) = *(arreglo1.ptr + i*sizeof(int));
	}
	
	free(arreglo1.ptr);
	arreglo1.ptr = ptr2;
	
	
	printf("Capacidad aumentada de %d a %d\n", arreglo1.tam, arreglo1.cap);
}

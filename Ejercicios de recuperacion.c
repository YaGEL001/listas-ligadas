#include <stdio.h>
#include <stdlib.h>

// Estructura de un nodo de la lista
struct Nodo {
	int dato;
	struct Nodo* siguiente;
};

// Función para insertar un nodo al principio de la lista
struct Nodo* insertarAlPrincipio(struct Nodo* cabeza, int dato) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = cabeza;
	return nuevoNodo;
}

// Función para insertar un nodo al inicio de la lista 2
struct Nodo* insertarAlInicioLista2(struct Nodo* cabeza2, int valor) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = valor;
	nuevoNodo->siguiente = cabeza2;
	
	return nuevoNodo;
}

// Función para insertar un nodo al final de la lista 2
struct Nodo* insertarAlFinalLista2(struct Nodo* cabeza2, int valor) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = valor;
	nuevoNodo->siguiente = NULL;
	
	if (cabeza2 == NULL) {
		return nuevoNodo; // Si la lista 2 está vacía, el nuevo nodo se convierte en la cabeza.
	}
	
	struct Nodo* actual = cabeza2;
	while (actual->siguiente != NULL) {
		actual = actual->siguiente;
	}
	
	actual->siguiente = nuevoNodo;
	
	return cabeza2;
}


// Función para insertar un nodo al final de la lista
struct Nodo* insertarAlFinal(struct Nodo* cabeza, int dato) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = NULL;
	
	if (cabeza == NULL) {
		return nuevoNodo;
	}
	
	struct Nodo* actual = cabeza;
	while (actual->siguiente != NULL) {
		actual = actual->siguiente;
	}
	
	actual->siguiente = nuevoNodo;
	return cabeza;
}

// Función para imprimir la lista
void imprimirLista(struct Nodo* cabeza) {
	struct Nodo* actual = cabeza;
	
	printf("\n-----------------------------------------------------------------------------------------\n");
	while (actual != NULL) {
		printf("|%d| -> ", actual->dato);
		actual = actual->siguiente;
	}
	printf("| NULL |\n");
	printf("-----------------------------------------------------------------------------------------\n");
}

// Función para insertar un nodo a la derecha de un valor específico
struct Nodo* insertarDerecha(struct Nodo* cabeza, int valor, int dato) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = NULL;
	
	if (cabeza == NULL) {
		return nuevoNodo;
	}
	
	struct Nodo* actual = cabeza;
	while (actual->dato != valor && actual->siguiente != NULL) {
		actual = actual->siguiente;
	}
	
	if (actual->dato == valor) {
		nuevoNodo->siguiente = actual->siguiente;
		actual->siguiente = nuevoNodo;
	}
	
	return cabeza;
}

struct Nodo* insertarIzquierda(struct Nodo* cabeza, int valor, int dato) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = NULL;
	
	if (cabeza == NULL) {
		return nuevoNodo;
	}
	
	if (cabeza->dato == valor) {
		nuevoNodo->siguiente = cabeza;
		return nuevoNodo;
	}
	
	struct Nodo* actual = cabeza;
	while (actual->siguiente != NULL && actual->siguiente->dato != valor) {
		actual = actual->siguiente;
	}
	
	if (actual->siguiente != NULL) {
		nuevoNodo->siguiente = actual->siguiente;
		actual->siguiente = nuevoNodo;
	}
	
	return cabeza;
}

struct Nodo* insertarEnPosicion(struct Nodo* cabeza, int dato, int posicion) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = NULL;
	
	if (cabeza == NULL) {
		return nuevoNodo;
	}
	
	if (posicion == 1) {
		nuevoNodo->siguiente = cabeza;
		return nuevoNodo;
	}
	
	struct Nodo* actual = cabeza;
	int i = 1;
	
	while (i < posicion - 1 && actual->siguiente != NULL) {
		actual = actual->siguiente;
		i++;
	}
	
	nuevoNodo->siguiente = actual->siguiente;
	actual->siguiente = nuevoNodo;
	
	return cabeza;
}

struct Nodo* insertarOrdenado(struct Nodo* cabeza, int dato) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = dato;
	nuevoNodo->siguiente = NULL;
	
	if (cabeza == NULL || cabeza->dato >= dato) {
		nuevoNodo->siguiente = cabeza;
		return nuevoNodo;
	}
	
	struct Nodo* actual = cabeza;
	while (actual->siguiente != NULL && actual->siguiente->dato < dato) {
		actual = actual->siguiente;
	}
	
	nuevoNodo->siguiente = actual->siguiente;
	actual->siguiente = nuevoNodo;
	
	return cabeza;
}

// Función para eliminar el nodo al principio de la lista
struct Nodo* eliminarAlPrincipio(struct Nodo* cabeza) {
	if (cabeza == NULL) {
		return NULL;  // La lista ya está vacía
	}
	
	struct Nodo* temp = cabeza;
	cabeza = cabeza->siguiente;
	free(temp);
	
	return cabeza;
}

// Función para eliminar el nodo al final de la lista
struct Nodo* eliminarAlFinal(struct Nodo* cabeza) {
	if (cabeza == NULL) {
		return NULL;  // La lista ya está vacía
	}
	
	if (cabeza->siguiente == NULL) {
		free(cabeza);
		return NULL;
	}
	
	struct Nodo* actual = cabeza;
	while (actual->siguiente->siguiente != NULL) {
		actual = actual->siguiente;
	}
	
	free(actual->siguiente);
	actual->siguiente = NULL;
	
	return cabeza;
}


// Función para borrar el valor a la derecha de un dato específico
struct Nodo* borrarValorDerechaDeDato(struct Nodo* cabeza, int datoABuscar) {
	if (cabeza == NULL) {
		return cabeza; // Lista vacía, no se puede borrar.
	}
	
	struct Nodo* actual = cabeza;
	
	while (actual != NULL && actual->dato != datoABuscar) {
		actual = actual->siguiente;
	}
	
	if (actual == NULL || actual->siguiente == NULL) {
		return cabeza; // Dato no encontrado o último nodo, no se puede borrar.
	}
	
	struct Nodo* nodoAEliminar = actual->siguiente;
	actual->siguiente = nodoAEliminar->siguiente;
	
	free(nodoAEliminar); // Liberar la memoria del nodo eliminado
	
	return cabeza;
}

// Función para borrar el valor a la izquierda de un dato específico
struct Nodo* borrarValorIzquierdaDeDato(struct Nodo* cabeza, int datoABuscar) {
	if (cabeza == NULL) {
		return cabeza; // Lista vacía, no se puede borrar.
	}
	
	if (cabeza->dato == datoABuscar) {
		// El nodo a eliminar es el nodo cabeza, no se puede borrar el valor a la izquierda.
		return cabeza;
	}
	
	struct Nodo* actual = cabeza;
	struct Nodo* nodoAnterior = NULL;
	
	while (actual->siguiente != NULL) {
		if (actual->siguiente->dato == datoABuscar) {
			// El nodo a eliminar es el nodo siguiente al nodo actual
			if (nodoAnterior != NULL) {
				// Aquí, en lugar de eliminar el nodo, simplemente saltamos el nodo a borrar.
				nodoAnterior->siguiente = actual->siguiente;
			}
			return cabeza;
		}
		nodoAnterior = actual;
		actual = actual->siguiente;
	}
	
	return cabeza; // Dato no encontrado en la lista.
}

// Función para borrar el nodo en una posición específica
struct Nodo* borrarEnPosicion(struct Nodo* cabeza, int posicion) {
	if (cabeza == NULL || posicion <= 0) {
		return cabeza; // La lista está vacía o la posición no es válida
	}
	
	if (posicion == 1) {
		struct Nodo* temp = cabeza;
		cabeza = cabeza->siguiente;
		free(temp);
		return cabeza;
	}
	
	struct Nodo* actual = cabeza;
	int i;
	for (i = 1; i < posicion - 1 && actual != NULL; i++) {
		actual = actual->siguiente;
	}
	
	if (actual == NULL || actual->siguiente == NULL) {
		return cabeza; // La posición está más allá del final de la lista
	}
	
	struct Nodo* temp = actual->siguiente;
	actual->siguiente = temp->siguiente;
	free(temp);
	
	return cabeza;
}

// Función para borrar todos los nodos diferentes a un valor dado
struct Nodo* borrarDiferentesA(struct Nodo* cabeza, int valor) {
	while (cabeza != NULL && cabeza->dato != valor) {
		struct Nodo* temp = cabeza;
		cabeza = cabeza->siguiente;
		free(temp);
	}
	
	if (cabeza == NULL) {
		return NULL; // Todos los nodos eran diferentes al valor dado
	}
	
	struct Nodo* actual = cabeza;
	struct Nodo* siguiente = cabeza->siguiente;
	
	while (siguiente != NULL) {
		if (siguiente->dato != valor) {
			struct Nodo* temp = siguiente;
			actual->siguiente = siguiente->siguiente;
			free(temp);
		} else {
			actual = siguiente;
		}
		
		siguiente = actual->siguiente;
	}
	
	return cabeza;
}

// Función para borrar todos los nodos con un valor igual al valor dado
struct Nodo* borrarIgualesA(struct Nodo* cabeza, int valor) {
	while (cabeza != NULL && cabeza->dato == valor) {
		struct Nodo* temp = cabeza;
		cabeza = cabeza->siguiente;
		free(temp);
	}
	
	if (cabeza == NULL) {
		return NULL; // Todos los nodos eran iguales al valor dado
	}
	
	struct Nodo* actual = cabeza;
	struct Nodo* siguiente = cabeza->siguiente;
	
	while (siguiente != NULL) {
		if (siguiente->dato == valor) {
			struct Nodo* temp = siguiente;
			actual->siguiente = siguiente->siguiente;
			free(temp);
		} else {
			actual = siguiente;
		}
		
		siguiente = actual->siguiente;
	}
	
	return cabeza;
}

// Función para invertir una lista enlazada
struct Nodo* invertirLista(struct Nodo* cabeza) {
	struct Nodo* anterior = NULL;
	struct Nodo* actual = cabeza;
	struct Nodo* siguiente = NULL;
	
	while (actual != NULL) {
		siguiente = actual->siguiente; // Guarda el siguiente nodo
		actual->siguiente = anterior; // Cambia el enlace al nodo anterior
		anterior = actual; // Mueve anterior al nodo actual
		actual = siguiente; // Mueve actual al siguiente nodo
	}
	
	cabeza = anterior; // El nuevo nodo principal es el último nodo (anterior)
	
	return cabeza;
}


struct Nodo* insertarEnPosicionLista2(struct Nodo* cabeza2, int valor, int posicion) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = valor;
	
	if (posicion <= 1) {
		nuevoNodo->siguiente = cabeza2;
		return nuevoNodo;
	}
	
	struct Nodo* actual = cabeza2;
	int i;
	for (i = 1; i < posicion - 1 && actual != NULL; i++) {
		actual = actual->siguiente;
	}
	
	if (actual == NULL) {
		printf("La posición está más allá del final de la lista 2. Nodo no insertado.\n");
		free(nuevoNodo);
		return cabeza2;
	}
	
	nuevoNodo->siguiente = actual->siguiente;
	actual->siguiente = nuevoNodo;
	
	return cabeza2;
}


// Función para insertar un nodo a la derecha de un valor dado en la lista 2
struct Nodo* insertarDerechaLista2(struct Nodo* cabeza2, int valorDerecha, int valor) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = valor;
	
	struct Nodo* actual = cabeza2;
	
	while (actual != NULL) {
		if (actual->dato == valorDerecha) {
			nuevoNodo->siguiente = actual->siguiente;
			actual->siguiente = nuevoNodo;
			return cabeza2;
		}
		actual = actual->siguiente;
	}
	
	// Si no se encuentra el valorDerecha, se muestra un mensaje de error.
	printf("El valor dado para la inserción a la derecha no se encuentra en la lista 2. Nodo no insertado.\n");
	free(nuevoNodo);
	return cabeza2;
}


// Función para insertar un nodo a la izquierda de un valor dado en la lista 2
struct Nodo* insertarIzquierdaLista2(struct Nodo* cabeza2, int valorIzquierda, int valor) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = valor;
	
	if (cabeza2 == NULL) {
		return nuevoNodo; // Si la lista está vacía, el nuevo nodo se convierte en la cabeza.
	}
	
	if (cabeza2->dato == valorIzquierda) {
		nuevoNodo->siguiente = cabeza2;
		return nuevoNodo;
	}
	
	struct Nodo* actual = cabeza2;
	
	while (actual->siguiente != NULL) {
		if (actual->siguiente->dato == valorIzquierda) {
			nuevoNodo->siguiente = actual->siguiente;
			actual->siguiente = nuevoNodo;
			return cabeza2;
		}
		actual = actual->siguiente;
	}
	
	// Si no se encuentra el valorIzquierda, se muestra un mensaje de error.
	printf("El valor dado para la inserción a la izquierda no se encuentra en la lista 2. Nodo no insertado.\n");
	free(nuevoNodo);
	return cabeza2;
}



// Función para insertar un nodo en una posición ordenada en la lista 2
struct Nodo* insertarOrdenadoLista2(struct Nodo* cabeza2, int valor) {
	struct Nodo* nuevoNodo = (struct Nodo*)malloc(sizeof(struct Nodo));
	nuevoNodo->dato = valor;
	
	if (cabeza2 == NULL || valor < cabeza2->dato) {
		nuevoNodo->siguiente = cabeza2;
		return nuevoNodo;
	}
	
	struct Nodo* actual = cabeza2;
	
	while (actual->siguiente != NULL && actual->siguiente->dato < valor) {
		actual = actual->siguiente;
	}
	
	nuevoNodo->siguiente = actual->siguiente;
	actual->siguiente = nuevoNodo;
	
	return cabeza2;
}


// Función para concatenar dos listas enlazadas
struct Nodo* concatenarListas(struct Nodo* cabeza1, struct Nodo* cabeza2) {
	if (cabeza1 == NULL) {
		return cabeza2;
	}
	
	if (cabeza2 == NULL) {
		return cabeza1;
	}
	
	struct Nodo* actual = cabeza1;
	while (actual->siguiente != NULL) {
		actual = actual->siguiente;
	}
	
	actual->siguiente = cabeza2;
	
	// Imprimir la lista concatenada
	printf("Lista concatenada: ");
	actual = cabeza1;
	while (actual != NULL) {
		printf("%d -> ", actual->dato);
		actual = actual->siguiente;
	}
	printf("NULL\n");
	
	return cabeza1;
}


// Función para ordenar una lista enlazada con el método de burbuja
struct Nodo* ordenarBurbuja(struct Nodo* cabeza) {
	if (cabeza == NULL) {
		return cabeza; // No se puede ordenar una lista vacía
	}
	
	int intercambio;
	struct Nodo* actual;
	struct Nodo* ultimo = NULL;
	
	do {
		intercambio = 0;
		actual = cabeza;
		
		while (actual->siguiente != ultimo) {
			if (actual->dato > actual->siguiente->dato) {
				// Intercambiar los valores de los nodos
				int temp = actual->dato;
				actual->dato = actual->siguiente->dato;
				actual->siguiente->dato = temp;
				intercambio = 1;
			}
			actual = actual->siguiente;
		}
		ultimo = actual;
	} while (intercambio);
	
	return cabeza;
}




// Función para insertar un nodo en una lista ordenada (auxiliar)
struct Nodo* insertarEnOrden(struct Nodo* cabezaOrdenada, struct Nodo* nuevoNodo) {
	struct Nodo* actual = cabezaOrdenada;
	struct Nodo* anterior = NULL;
	
	while (actual != NULL && nuevoNodo->dato > actual->dato) {
		anterior = actual;
		actual = actual->siguiente;
	}
	
	if (anterior == NULL) {
		nuevoNodo->siguiente = cabezaOrdenada;
		return nuevoNodo;
	} else {
		anterior->siguiente = nuevoNodo;
		nuevoNodo->siguiente = actual;
		return cabezaOrdenada;
	}
}
// Función para ordenar una lista enlazada con el método de inserción
struct Nodo* ordenarInsercion(struct Nodo* cabeza) {
	if (cabeza == NULL) {
		return cabeza; // No se puede ordenar una lista vacía
	}
	
	struct Nodo* listaOrdenada = NULL;
	struct Nodo* actual = cabeza;
	
	while (actual != NULL) {
		struct Nodo* siguiente = actual->siguiente;
		listaOrdenada = insertarEnOrden(listaOrdenada, actual);
		actual = siguiente;
	}
	
	return listaOrdenada;
}






// Función para fusionar dos listas ordenadas
struct Nodo* fusionarListas(struct Nodo* listaIzquierda, struct Nodo* listaDerecha) {
	struct Nodo* resultado = NULL;
	
	if (listaIzquierda == NULL) {
		return listaDerecha;
	}
	if (listaDerecha == NULL) {
		return listaIzquierda;
	}
	
	if (listaIzquierda->dato <= listaDerecha->dato) {
		resultado = listaIzquierda;
		resultado->siguiente = fusionarListas(listaIzquierda->siguiente, listaDerecha);
	} else {
		resultado = listaDerecha;
		resultado->siguiente = fusionarListas(listaIzquierda, listaDerecha->siguiente);
	}
	
	return resultado;
}

// Función para dividir una lista en dos sublistas
void dividirLista(struct Nodo* cabeza, struct Nodo** listaIzquierda, struct Nodo** listaDerecha) {
	struct Nodo* rapido;
	struct Nodo* lento;
	
	if (cabeza == NULL || cabeza->siguiente == NULL) {
		*listaIzquierda = cabeza;
		*listaDerecha = NULL;
	} else {
		lento = cabeza;
		rapido = cabeza->siguiente;
		
		while (rapido != NULL) {
			rapido = rapido->siguiente;
			if (rapido != NULL) {
				lento = lento->siguiente;
				rapido = rapido->siguiente;
			}
		}
		
		*listaIzquierda = cabeza;
		*listaDerecha = lento->siguiente;
		lento->siguiente = NULL;
	}
}


// Función para ordenar una lista enlazada con el método de Merge Sort
struct Nodo* ordenarMergeSort(struct Nodo* cabeza) {
	if (cabeza == NULL || cabeza->siguiente == NULL) {
		return cabeza; // La lista ya está ordenada o es vacía
	}
	
	struct Nodo* listaIzquierda;
	struct Nodo* listaDerecha;
	
	dividirLista(cabeza, &listaIzquierda, &listaDerecha);
	
	listaIzquierda = ordenarMergeSort(listaIzquierda);
	listaDerecha = ordenarMergeSort(listaDerecha);
	
	return fusionarListas(listaIzquierda, listaDerecha);
}



int main() {
	struct Nodo* cabeza = NULL;
	struct Nodo* cabeza2 = NULL;

	int opcion, dato,valor,posicion,valorDerecha,valorIzquierda,datoABuscar;
	int ciclo;
	do{
		printf("---------------------\n");
		printf("Seleccione una opcion\n");
		printf("---------------------\n");
		printf("   1.insertar \n");
		printf("---------------------\n");
		printf("   2.eliminar \n");
		printf("---------------------\n");
		printf("   3.otra \n");
		printf("---------------------\n");
		scanf("%d",&ciclo);
		system("cls");
		switch(ciclo){
		case 1:
			do{
				printf("--------------------------------------------------------------------------\n");
				printf("                              Menu:\n");
				printf("--------------------------------------------------------------------------\n");
				printf("1. Insertar al principio LS1	|     2. Insertar al principio LS2        \n");
				printf("--------------------------------------------------------------------------\n");
				printf("3. Insertar al final LS1	|     4. Insertar al final LS2            \n");
				printf("--------------------------------------------------------------------------\n");
				printf("5. En una posición LS1          |     6. Insertar en una posición LS2     \n");
				printf("--------------------------------------------------------------------------\n");
				printf("7. Insertar a la derecha LS1    |     8. Insertar a la derecha LS2\n");
				printf("--------------------------------------------------------------------------\n");
				printf("9. A la izquierda LS1           |     10. Insertar a la izquierda LS2\n");
				printf("--------------------------------------------------------------------------\n");
				printf("11. Forma ordenada LS1          |     12. Insertar de forma ordenada LS2\n");
				printf("--------------------------------------------------------------------------\n");
				printf("13. Imprimir lista LS1          |     14. Imprimir lista LS2\n");
				printf("--------------------------------------------------------------------------\n");
				printf("                           15. Salir\n");
				printf("--------------------------------------------------------------------------\n");
				
				
				printf("Seleccione una opción: ");
				scanf("%d", &opcion);
				system("cls");
				switch (opcion) {
				case 1:
					printf("Ingrese el dato a insertar al principio: ");
					scanf("%d", &dato);
					cabeza = insertarAlPrincipio(cabeza, dato);
					break;
				case 2:
					printf("Ingrese el valor que desea insertar al inicio en lista 2: ");
					scanf("%d", &valor);
					cabeza2 = insertarAlInicioLista2(cabeza2, valor);
					printf("Nodo insertado al inicio en lista 2.\n");
					break;
					
				case 3:
					printf("Ingrese el dato a insertar al final: ");
					scanf("%d", &dato);
					cabeza = insertarAlFinal(cabeza, dato);
					
					break;
				case 4:
					
					printf("Ingrese el valor que desea insertar al final en lista 2: ");
					scanf("%d", &valor);
					cabeza2 = insertarAlFinalLista2(cabeza2, valor);
					printf("Nodo insertado al final en lista 2.\n");
					break;
					
				case 5:
					printf("Ingrese el dato a insertar: ");
					scanf("%d", &dato);
					printf("Ingrese la posición en la que desea insertar: ");
					scanf("%d", &posicion);
					cabeza = insertarEnPosicion(cabeza, dato, posicion);
					
					break;
				case 6:
					
					printf("Ingrese el valor que desea insertar en lista 2: ");
					scanf("%d", &valor);
					printf("Ingrese la posición en la que desea insertar: ");
					scanf("%d", &posicion);
					cabeza2 = insertarEnPosicionLista2(cabeza2, valor, posicion);
					printf("Nodo insertado en lista 2.\n");
					break;
					
				case 7:
					printf("Ingrese el valor después del cual desea insertar el dato a la derecha: ");
					scanf("%d", &valor);
					printf("Ingrese el dato a insertar a la derecha: ");
					scanf("%d", &dato);
					cabeza = insertarDerecha(cabeza, valor, dato);
					
					
					break;
					
				case 8:
					
					
					printf("Ingrese el valor después del cual desea insertar en lista 2: ");
					scanf("%d", &valorDerecha);
					printf("Ingrese el valor que desea insertar a la derecha: ");
					scanf("%d", &valor);
					cabeza2 = insertarDerechaLista2(cabeza2, valorDerecha, valor);
					printf("Nodo insertado en lista 2.\n");
					
					break;
					
				case 9:
					printf("Ingrese el valor antes del cual desea insertar el dato a la izquierda: ");
					scanf("%d", &valor);
					printf("Ingrese el dato a insertar a la izquierda: ");
					scanf("%d", &dato);
					cabeza = insertarIzquierda(cabeza, valor, dato);
					
					
					break;
					
					
				case 10:
					
					
					printf("Ingrese el valor antes del cual desea insertar en lista 2: ");
					scanf("%d", &valorIzquierda);
					printf("Ingrese el valor que desea insertar a la izquierda: ");
					scanf("%d", &valor);
					cabeza2 = insertarIzquierdaLista2(cabeza2, valorIzquierda, valor);
					printf("Nodo insertado en lista 2.\n");
					
					break;
					
				case 11:
					printf("Ingrese el dato a insertar de forma ordenada: ");
					scanf("%d", &dato);
					cabeza = insertarOrdenado(cabeza, dato);
					
					
					break;	
					
				case 12:
					
					printf("Ingrese el valor que desea insertar en lista 2 (ordenado): ");
					scanf("%d", &valor);
					cabeza2 = insertarOrdenadoLista2(cabeza2, valor);
					printf("Nodo insertado en lista 2 (ordenado).\n");
					
					break;	
					
				case 13:
					printf("Lista actual: ");
					imprimirLista(cabeza);
					
					break;
					
				case 14:
					
					printf("Lista actual: ");
					imprimirLista(cabeza2);
					
					break;	
				}
			}while(opcion!=15);
			break;
			
		case 2:
			do{
				printf("\nMenu:\n");
				printf("1. borrar al principio\n");
				printf("2. borrar al final\n");
				printf("3. borrar a la derecha\n");
				printf("4. borrar a la izquierda\n");
				printf("5. borrar en una posicion\n");
				printf("6. borrar los valores diferentes\n");
				printf("7. borrar los valores iguales\n");
				printf("8. Imprimir lista\n");
				printf("9. Salir\n");
				printf("Seleccione una opción: ");
				scanf("%d", &opcion);
				system("cls");
				switch (opcion){
				case 1:
					cabeza = eliminarAlPrincipio(cabeza);
					printf("eliminado al Principio\n");
					break;
				case 2:
					cabeza = eliminarAlFinal(cabeza);
					printf("eliminado al Final\n");
					
					break;
				case 3:
					// Borrar el valor a la derecha de un dato
					printf("Ingrese el dato cuyo valor a la derecha desea borrar: ");
					scanf("%d", &datoABuscar);
					cabeza = borrarValorDerechaDeDato(cabeza, datoABuscar);;
					break;
				case 4:
					// Borrar el valor a la izquierda de un dato
					printf("Ingrese el dato cuyo valor a la izquierda desea borrar: ");
					scanf("%d", &datoABuscar);
					cabeza = borrarValorIzquierdaDeDato(cabeza, datoABuscar);
					break;	
				case 5:
					printf("Ingrese la posición en la que desea borrar: ");
					scanf("%d", &posicion);
					cabeza = borrarEnPosicion(cabeza, posicion);
					break;
					
				case 6:
					printf("Ingrese el valor del cual desea conservar los nodos: ");
					scanf("%d", &valor);
					cabeza = borrarDiferentesA(cabeza, valor);
					break;
					
				case 7:
					printf("Ingrese el valor del cual desea borrar los nodos iguales: ");
					scanf("%d", &valor);
					cabeza = borrarIgualesA(cabeza, valor);
					break;
					
				case 8:
					printf("Lista actual: ");
					imprimirLista(cabeza);
					break;
				}
				
				
			}while(opcion!=9);
			
			break;
		case 3:
			do{
				printf("\nMenu:\n");
				printf("1. invertir\n");
				printf("2. concatenar\n");
				printf("3. ordenamiento\n");
				printf("4. salir\n");
				
				printf("Seleccione una opción: ");
				scanf("%d", &opcion);
				system("cls");
				switch (opcion){
				case 1:
					cabeza = invertirLista(cabeza);
					printf("Lista invertida.\n");
					break;
					
				case 2:
					
					printf("listas actuales :\n ");
					
					printf("Lista actual: ");
					imprimirLista(cabeza);
					printf("Lista actual: ");
					imprimirLista(cabeza2);
					cabeza = concatenarListas(cabeza, cabeza2);
					printf("Listas concatenadas.\n");
					break;
					
				case 3:
					do{
						printf("\nOrdenamiento:\n");
						printf("1. Burbuja\n");
						printf("2. Insercion\n");
						printf("3. Merge\n");
						printf("5. salir\n");
						printf("Seleccione una opción: ");
						scanf("%d", &opcion);
						switch (opcion){
						case 1:
							cabeza = ordenarBurbuja(cabeza);
							cabeza2 = ordenarBurbuja(cabeza2);
							printf("Ambas listas ordenadas con el método de burbuja.\n");
							
							// Imprimir la lista 1
							printf("Lista 1 ordenada: ");
							struct Nodo* actual = cabeza;
							while (actual != NULL) {
								printf("%d -> ", actual->dato);
								actual = actual->siguiente;
							}
							printf("NULL\n");
							
							// Imprimir la lista 2
							printf("Lista 2 ordenada: ");
							struct Nodo* actual2 = cabeza2;
							while (actual2 != NULL) {
								printf("%d -> ", actual2->dato);
								actual2 = actual2->siguiente;
							}
							printf("NULL\n");
							
							break;
							
						case 2:
							cabeza = ordenarInsercion(cabeza);
							cabeza2 = ordenarInsercion(cabeza2);
							printf("Ambas listas ordenadas con el método de inserción.\n");
							
							// Imprimir lista 1 ordenada
							printf("Lista 1 ordenada: ");
							imprimirLista(cabeza);
							
							// Imprimir lista 2 ordenada
							printf("Lista 2 ordenada: ");
							imprimirLista(cabeza2);
							break;
							
						case 3:
							cabeza = ordenarMergeSort(cabeza);
							cabeza2 = ordenarMergeSort(cabeza2);
							printf("Ambas listas ordenadas con el método de Merge Sort.\n");
							
							// Imprimir lista 1 ordenada
							printf("Lista 1 ordenada: ");
							imprimirLista(cabeza);
							
							// Imprimir lista 2 ordenada
							printf("Lista 2 ordenada: ");
							imprimirLista(cabeza2);
							break;
						}
					}while(opcion!=5);
					break;
					
				}
				
			}while(opcion!=4);
			
			break;
			
		}
	}while(ciclo!=4);
	// Liberar la memoria de los nodos antes de salir
	while (cabeza != NULL) {
		struct Nodo* temp = cabeza;
		cabeza = cabeza->siguiente;
		free(temp);
	}
	while (cabeza2 != NULL) {
		struct Nodo* temp = cabeza2;
		cabeza2 = cabeza2->siguiente;
		free(temp);
	}
	return 0;
}

/*
Programa que implementa una lista dinámica enlazada y las funciones básicas para:
Inserción de un elemento al inicio de la lista
Eliminación de un elemento de la lista
*/

#include <iostream>
using namespace std;

/*
Clase Nodo
Definición de los nodos de la lista

Datos:
 dato: valor que almacena el nodo
 *siguientePtr: apuntador al siguiente nodo en la lista

Procedimientos:
 insertarAlInicio: procedimiento encargado de insertar un nodo al inicio de la lista
 RecorreIterativo: procedimiento encargado de recorrer y mostrar el valor de cada nodo de la lista
*/
class Nodo
{
	public:
		int dato; // Variable para almacenar el valor del nodo
		Nodo *siguientePtr; // Apuntador al siguiente nodo de la lista
};

/*
Clase lista
Definición de la lista de nodos
*/
class Lista
{
	private:
		Nodo *primeroPtr; // Apuntador al primer nodo de la lista
		bool estaVacia(); // Variable que indica si la lista está vacia
		
	public:
		Lista();      // Constructor
		destruirLista();   // Destructor
		void insertarAlInicio(int valor); // inserta un nodo al inicio de la lista
		void recorreIterativo(); // muestra el contenido de la lista
};

// Definicion de las funciones de la clase Lista
// ***********************************************************
// Verifica si la lista está vacia
bool Lista::estaVacia()
{
	return primeroPtr == NULL;
}

// Constructor predeterminado
Lista::Lista()
{
	primeroPtr = NULL;
}

// Destructor predeterminado
Lista::destruirLista()
{
	if( !estaVacia() )
	{
		cout << "\n\nDestruyendo nodos...\n\n";
		
		Nodo *actualPtr = primeroPtr;
		Nodo *tempPtr;
		
		// Eliminar los nodos restantes
		while( actualPtr != NULL )
		{
			tempPtr = actualPtr;
			cout << tempPtr->dato << ' ';
			actualPtr = actualPtr->siguientePtr;
			delete tempPtr;
		}
	}
	cout << "\n\nSe destruyeron todos los nodos.\n\n";
}

// Inserta un nodo al inicio de la lista
void Lista::insertarAlInicio(int valor)
{
	Nodo *nuevoPtr = new Nodo(); // Nodo temporal para agregar el nuevo nodo
	nuevoPtr->dato = valor;
	
	if( estaVacia() ) // Si la lista esta vacia
	{
		nuevoPtr->siguientePtr = NULL; // El nuevo nodo apunta a nulo
	}
	else // Si la lista no esta vacia
	{
		nuevoPtr->siguientePtr = primeroPtr; // Apunta el nuevo nodo al nodo que era el primero
	}
	
	primeroPtr = nuevoPtr; // Apunto el primer nodo de la lista al nuevo nodo
}

void Lista::recorreIterativo()
{
	if( estaVacia() ) // Si la lista está vacia
	{
		cout << "\nLa lista esta vacia\n\n";
		system("pause");
		return;
	}
	
	Nodo *actualPtr = primeroPtr;
	
	cout << "\nLos elementos de la lista son: ";
	
	while( actualPtr != NULL ) // Se obtienen todos los datos de la lista
	{
		cout << actualPtr->dato << " -> ";
		actualPtr = actualPtr->siguientePtr;
	}
	
	cout << "\n\n";
	system("pause");
}

 // ***********************************************************

// Menu de opciones

void menu()
{
	system("cls");
	cout << "\n ..[ LISTA SIMPLE ENLAZADA ]..";
	cout << "\n ..[ Ing. Danny Colmenares ]..\n\n";
	cout << "[1] Insertar elemento al inicio de la lista \n";
	cout << "[2] Imprimir los valores de la lista \n";
	cout << "[3] SALIR \n";
	cout << "\nIngrese opcion : ";
	
}
 
int main()
{
	int opcion; // Variable para almacenar la opción seleccionada del menú
	int valor;  // Variable para almacenar el valor a ingresar en la lista
	
	Lista listaEnteros;
	
	system("color 1F");
	
	do
	{
		menu();
		cin >> opcion;
		
		switch( opcion )
		{
			case 1: // Insertar nodo al principio de la lista
				cout << "\nIngrese un valor entero: ";
				cin >> valor;
				listaEnteros.insertarAlInicio( valor );
				listaEnteros.recorreIterativo();
				break;
			case 2: // Recorrer la lista
				listaEnteros.recorreIterativo();
				break;
		}
	}while( opcion != 3 );
	
	return 0;
}

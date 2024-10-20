# Listas Enlazadas Cplusplus

Fundamentos de declaracion y uso de listas enlazadas dinámicas en el lenguaje de programacion C++

En el campo del procesamiento de datos se encuentra la necesidad de manipular datos que, según las caracteristicas del problema planteado, deben ser representados de una manera particular, a la cual llamamos estructura de datos. La construcción de los algoritmos que manipularán dichos datos dependerán de la estructura de datos definida con la finalidad de aportar eficiencia al algoritmo.

Las estructuras de datos se pueden clasificar según el modo de almacenar los datos en la memoria del computador y la forma de acceder a los mismos. Desde el punto de vista del almacenamiento en la memoria del computador, se clasifican en estructuras de datos estáticas o dinámicias.

Según la forma de acceder a los datos durante la ejecución de los algorítmos, se clasifican en lineales o no lineales.

Las listas son la estructura de datos más sencilla, es la esttructura que permite representar un conjunto finito y ordenado de elementos, se definen como colecciones de elementos donde cada uno de ellos además de almacenar información, almacena la dirección del siguiente elemento.

Una lista es una estructura lineal de datos, es decir que cada uno de sus componentes tiene un sucesor y un predecesor únicos, con excepción del último y del primero, los cuales carecen de sucesor y de predecesor respectivamente.

Las listas pueden implementarse mediante arreglos, resultando así una estructura estática, es decir que el tamaño de la misma no varía durante la ejecución del programa.

Otra alternativa para la implementación de una lista es usar memoria dinámica, lo que permite que la lista tome esta característica, obteniéndose de esta manera una estructura dinámica, lo cual implica que la cantidad de memoria ocupada puede modificarse durante la ejecución del programa.

Una lista enlazada simple es una estructura de datos lineal y dinámica, formada por una colección de elementos llamados nodos, cada nodo está conformado por dos elementos, el primero se usa para almacenar la información y el segundo elemento para guardar la dirección del siguiente nodo.

Cabe destacar que el último elemento de la lista guarda como dirección al siguiente elemento una referencia NULL, y el primer elemento es apuntado por un apuntador especifico al primer elemento de la lista.

Para implementar una lista dinámica enlazada en el lenguaje de programación C++, se procede a crear los elementos necesarios para implementar la estructura de datos necesaria para guardar de manera adecuada y eficiente los datos necesarios.

~~~c++
/*
Clase Nodo
Definición de los nodos de la lista

Datos:
 dato: valor que almacena el nodo
 *siguientePtr: apuntador al siguiente nodo en la lista

*/
class Nodo
{
	public:
		int dato; // Variable para almacenar el valor del nodo
		Nodo *siguientePtr; // Apuntador al siguiente nodo de la lista
};
~~~

En el código mostrado, podemos reconocer la estructura de un nodo de un tipo dinámico de datos, el cual está compuesto por una variable en la cual podemos almacenar un dato de un 
tipo específico y un apuntador que indica la ubicación exacta del siguiente nodo de la lista.

Para poder implementar una lista dinámica enlazada, se debe implementar un tipo abstracto de dato lista, el cual consta de una estructura de datos que permite almacenar el primer elemento
de la lista, ademas de una variable que indica si la misma esta vacia o contiene algún elemento.

Por otro lado tiene una estructura de comportamiento fomrada por los procesos que operan en dicha estructura de datos, el constructor por efecto, el proceso encargado de agregar 
un nuevo elemento al comienzo de la lista, por último el proceso encargado de recorrer la lista desde el primer elemento hasta el último.

~~~c++
/*
Clase lista
Definición de la lista de nodos

Datos:
 primeroPtr:
 estaVacia:

Procedimientos:
 insertarAlInicio: procedimiento encargado de insertar un nodo al inicio de la lista
 RecorreIterativo: procedimiento encargado de recorrer y mostrar el valor de cada nodo de la lista
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
~~~

Luego de definir la interfaz y el comportamiento de la clase Lista, se procede a definir las funciones que componen este comportamiento, el cual esta constituido por el constructor
por defecto, el destructor para liberar memoria, el procedimiento de inserción de nodos y el procedimiento de recorrido de la lista.

~~~c++
// Definicion de las funciones de la clase Lista
// ***********************************************************
// Verifica si la lista está vacia
bool Lista::estaVacia()
{
	return primeroPtr == NULL;
}
~~~

~~~c++
// Constructor predeterminado
Lista::Lista()
{
	primeroPtr = NULL;
}
~~~

~~~c++
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
~~~

~~~c++
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
~~~

~~~c++
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
~~~

Adicionalmente se tiene el proceso necesario para mostrar el menú en el cual se presentan las opciones de las operaciones a realizar con el programa.

~~~c++
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
~~~

Por último se tiene el programa principal en el cual se lee la opción del menú seleccionada para proceder a realizar el proceso seleccionado en el menú del programa

~~~c++
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
~~~

# Referencias

https://www.programacion.com.py/escritorio/c/listas-en-c

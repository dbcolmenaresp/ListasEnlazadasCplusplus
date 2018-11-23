# Listas Enlazadas Cplusplus
Fundamentos de declaracion y uso de listas enlazadas dinámicas en el lenguaje de programacion C++

Una lista se define como una colección de elementos donde cada uno de ellos además de almacenar información, almacena la dirección del siguiente elemento.

Una lista es una estructura lineal de datos, es decir que cada uno de sus componentes tiene un sucesor y un predecesor únicos, con excepción del último y del primero, los cuales carecen de sucesor y de predecesor respectivamente.

Las listas pueden implementarse mediante arreglos, resultando así una estructura estática, es decir que el tamaño de la misma no varía durante la ejecución del programa.

Otra alternativa para la implementación de una lista es usar memoria dinámica, lo que permite que la lista tome esta característica, obteniéndose de esta manera una estructura dinámica, lo cual implica que la cantidad de memoria ocupada puede modificarse durante la ejecución del programa.

Una lista enlazada simple es una estructura de datos lineal y dinámica, formada por una colección de elementos llamados nodos, cada nodo está conformado por dos elementos, el primero se usa para almacenar la información y el segundo elemento para guardar la dirección del siguiente nodo.

Cabe destacar que el último elemento de la lista guarda como dirección al siguiente elemento una referencia NUL, y el primer elemento es apuntado por un apuntador especifico al primer elemento.

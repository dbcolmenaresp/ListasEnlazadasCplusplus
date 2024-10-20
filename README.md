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



# Referencias

https://www.programacion.com.py/escritorio/c/listas-en-c

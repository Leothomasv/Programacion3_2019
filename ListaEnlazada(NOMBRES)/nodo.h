#pragma once
#ifndef Nodo_h
#define Nodo_h
#include <fstream>


struct nodo {
	char* name;
	nodo* siguiente;
	nodo* anterior;

	nodo() {
		name = 0;
		siguiente = 0;
		anterior = 0;
	 }
};

void insertarAlInicio(nodo**, const char*);//inserta un nodo al inicio de la lista
void insertarAlFinal(nodo**, const char*);//inserta un nodo al final de la lista
void ordenar(nodo**); //ordena la lista basado en el nombre haciendo uso del algoritmo de ordenacion burbuja
void checkSort(nodo**);
void guardarAArchivo(nodo**);
void cargarDesdeArchivo(nodo**);
void BuscarElemento(const char*);
void imprimir(nodo**);



#endif // !Nodo_h

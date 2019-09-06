#pragma once
#ifndef Nodo_h
#define Nodo_h

struct nodo
{
	char * name;
	nodo* siguiente;
	nodo* anterior;

	nodo() {
		siguiente = 0;
		anterior = 0;
	}
};

class ListaEnlazada {
public:
	static void insertar(nodo**, char*);
	static void eliminar(nodo**, char*);
	static bool buscar(nodo**, char*);
	static void imprimir(nodo**);

	//Nueva Funcion Para agregar los nombres...
	static nodo* AgregarNombres(int);

	
};

#endif // !Nodo_h

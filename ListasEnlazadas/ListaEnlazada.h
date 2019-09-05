#pragma once
#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "Nodo.h"

class ListaEnlazada
{
private:
	Nodo* ultimo;
	Nodo* primero;
	int cantidadElementos();
	bool estaVacia(void);

public:
	ListaEnlazada(void);
44	void agregar(int);
	void insertar(int, int);
	void imprimir(void);

	void eliminar(int);
	Nodo* buscar(int);

	


};




#endif // !LISTAENLAZADA_H

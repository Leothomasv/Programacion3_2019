#pragma once
#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H	

#include "Nodo.h"

class ListaCircular
{
private:
	Nodo* primero;
	Nodo* ultimo;

public:
	ListaCircular(void);

	bool estaVacia(void);
	void agregar(int);
	void insertar(int, int);
	void imprimir(void);
	void imprimirReversa(void);
	void eliminarEn(int);//deleteAt
	void eliminar(int);// borra el numero


	int obtenerTamano(void);
};



#endif // !LISTACIRCULAR_H

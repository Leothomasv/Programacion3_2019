#pragma once
#ifndef nodo_h
#define nodo_h


struct nodo {

	int valor;
	nodo* hijoDerecho;
	nodo* hijoIzquierdo;

	nodo()
	{
		valor = -1;
		hijoDerecho = 0;
		hijoIzquierdo = 0;
	}
};


void agregarElemento(nodo**, nodo*);
void imprimir(nodo**);




#endif // !nodo_h

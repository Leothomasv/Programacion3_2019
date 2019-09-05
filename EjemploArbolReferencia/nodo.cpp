#include "nodo.h"
#include <iostream>

using std::cout;

void agregarElemento(nodo** raiz, nodo* nuevo) {

	if (*raiz == 0)
		*raiz = nuevo;
	else {
		if (nuevo->valor >= (*raiz)->valor)
			agregarElemento(&(*raiz)->hijoDerecho, nuevo);
		else
			agregarElemento(&(*raiz)->hijoIzquierdo, nuevo);
	}
}

void imprimir(nodo** raiz) {
	if (*raiz == 0)
		return;
	cout << "[" << (*raiz)->valor << "] ";
	imprimir(&(*raiz)->hijoIzquierdo);
	imprimir(&(*raiz)->hijoDerecho);
}
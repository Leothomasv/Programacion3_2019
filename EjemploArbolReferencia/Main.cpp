#include "nodo.h"
#include <iostream>   
using namespace std;

int main() {

	nodo* raiz = 0;
	nodo* nuevo = new nodo;

	nuevo->valor = 40;
	agregarElemento(&raiz, nuevo);

	nuevo = new nodo;
	nuevo->valor = 31;
	agregarElemento(&raiz, nuevo);

	nuevo = new nodo;
	nuevo->valor = 62;
	agregarElemento(&raiz, nuevo);

	nuevo = new nodo;
	nuevo->valor = 55;
	agregarElemento(&raiz, nuevo);

	nuevo = new nodo;
	nuevo->valor = 85;
	agregarElemento(&raiz, nuevo);

	nuevo = new nodo;
	nuevo->valor = 12;
	agregarElemento(&raiz, nuevo);

	nuevo = new nodo;
	nuevo->valor = 38;
	agregarElemento(&raiz, nuevo);

	imprimir(&raiz);

	system("pause");
}


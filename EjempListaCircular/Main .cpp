#include"ListaCircular.h"
#include <iostream>

int main() {
	ListaCircular lista;

	lista.agregar(7);
	lista.agregar(11);
	lista.agregar(4);

	lista.insertar(1, 3);
	//lista.insertar(4, 5);

	lista.imprimir();

	system("pause");
}
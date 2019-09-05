#include <iostream>
#include "ListaEnlazada.h"

using namespace std;


ListaEnlazada::ListaEnlazada(void): primero(nullptr), ultimo(nullptr){
}

bool ListaEnlazada::estaVacia(void) {

	return primero == nullptr;
}

void ListaEnlazada::agregar(int _valor) {
	
	Nodo* nuevo = new Nodo(_valor, nullptr); //crear nueva lista

	if (estaVacia()) {
		primero = nuevo;
		ultimo = nuevo;
	}
	else {
		ultimo->setSiguiente(nuevo);
		ultimo = nuevo;
	}
}

void ListaEnlazada::imprimir(void) {

	Nodo* actual = primero;
	
	while (actual != nullptr) {

		cout << "[" << actual->getValor() << "] ";
		actual = actual->getSiguiente();// para ir moviendome de posicion por ejemplo 4-> 7 
	}
}

void ListaEnlazada::insertar(int pos, int valor) {


	if (pos > cantidadElementos()) {
		cout << "Posicion de nodo incorrecta! \n";
		return;
	}

	Nodo * nuevo = new Nodo(valor, nullptr); //crear nodo nuevo
	if (estaVacia()) {
		primero = nuevo;
		ultimo = nuevo;
	}
	else {

		int posRecorrido = 1;
		Nodo* actual = primero;
		Nodo* anterior = nullptr;

		while (actual != nullptr) {

			if (pos == posRecorrido) {

				if (actual == primero) {

					nuevo->setSiguiente(primero);
					primero = nuevo;
				}
				else {
					anterior->setSiguiente(nuevo);
					nuevo->setSiguiente(actual);
				}
				return;
			}

			anterior = actual;
			actual = actual->getSiguiente();
			posRecorrido++;
		}
	}

}

int ListaEnlazada::cantidadElementos() {

	int cantidad = 0;

	Nodo* actual = primero;

	while (actual != nullptr) { 
		
		cantidad++;
		actual = actual->getSiguiente();
	}

	return cantidad;
}

void ListaEnlazada::eliminar(int _valor) {

	Nodo* anterior = nullptr;
	Nodo* actual = primero;




}

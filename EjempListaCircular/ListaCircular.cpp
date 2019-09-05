#include "ListaCircular.h"
#include <iostream>

using std::cout;

ListaCircular::ListaCircular(void): primero(nullptr), ultimo(nullptr) {

}

bool ListaCircular::estaVacia(void) {
	return primero == nullptr;
}

void ListaCircular::agregar(int _valor) {
	Nodo* nuevo = new Nodo(_valor, nullptr, nullptr);
	
	if (estaVacia()) {

		primero = nuevo;
		ultimo = nuevo;
		primero->setAnterior(ultimo);
		ultimo->setSiguiente(primero);
	}
	else {

		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);
		ultimo = nuevo;
		ultimo->setSiguiente(primero);
		primero->setAnterior(ultimo);

	}
}

void ListaCircular::imprimir() {

	if (estaVacia())
		return;
	else {
		Nodo* actual = primero;


		do {
			cout << "[" << actual->getValor() << "] ";
			actual = actual->getSiguiente();

		} while (actual != primero); // hasta que la dirrecion de siguiente sea primero sale
	}
}

void ListaCircular::insertar(int pos, int _valor) {

	if (pos > obtenerTamano())
		return;

	Nodo* nuevo = new Nodo(_valor, nullptr, nullptr);
	Nodo* actual = primero;

	int posicion =1;

	do {
		if (posicion = pos) {

			if (actual = primero) {
				nuevo->setSiguiente(primero);
				primero->setAnterior(nuevo);//antiguo primero
				primero = nuevo;
				primero->setAnterior(ultimo);//nuevo primero
				ultimo->setSiguiente(primero);
			}
			else if (actual == ultimo) {
				nuevo->setSiguiente(ultimo);
				nuevo->setAnterior(ultimo->getAnterior());
				ultimo->getAnterior()->setSiguiente(nuevo);
				ultimo->setAnterior(nuevo);
			}
			else {
				nuevo->setSiguiente(actual);
				nuevo->setAnterior(actual->getAnterior());
				actual->getAnterior()->setSiguiente(nuevo);
				actual->setAnterior(nuevo);
			}

			return;
		}
		else {
			posicion++;
			actual = actual->getSiguiente();
		}

	} while (actual != primero);

}

int ListaCircular::obtenerTamano(void) {
	int cantidad = 0;

		//recorrido de atras hacia adelante
		Nodo* actual = ultimo;
		
		do {
			cantidad++;
			actual = actual->getAnterior();
		} while (actual != ultimo);

		return cantidad;
	
}

void ListaCircular::eliminar(int _valor) {

	Nodo* actual = primero;

	do {
		if (actual->getValor() == _valor) {
			if (actual == primero) {
				primero->getSiguiente()->setAnterior(ultimo);
				primero = primero->getSiguiente();
				ultimo->setSiguiente(primero);
				delete actual;
			}
			else if (actual == ultimo)
			{
				ultimo->getAnterior()->setSiguiente(primero);
				ultimo = ultimo->getAnterior();
				primero->setAnterior(ultimo);
				delete actual;
			}
			else {
				actual->getAnterior()->setSiguiente(actual->getSiguiente());
				actual->getSiguiente()->setAnterior(actual->getAnterior());
				delete actual;
			}
			return;
		}
		actual = actual->getSiguiente();

	} while (actual != primero);
}

void ListaCircular::eliminarEn(int pos ) {

}
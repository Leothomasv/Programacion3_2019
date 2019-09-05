#include "Nodo.h"
#include <iostream>

using namespace std;

Nodo::Nodo(void): valor(-1), siguiente(nullptr){



}

Nodo::Nodo(int _valor, Nodo* _siguiente) {

	setValor(_valor);
	setSiguiente(_siguiente);
}

Nodo::~Nodo(void) {}

void Nodo::setValor(int _valor) {

	this->valor = _valor;
}

int Nodo::getValor() {

	return this->valor;
}

void Nodo::setSiguiente(Nodo* _siguiente) {
	this->siguiente = _siguiente;
}

Nodo *Nodo::getSiguiente() {

	return this->siguiente;
}
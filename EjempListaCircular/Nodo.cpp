#include "Nodo.h"
#include <iostream>

using namespace std;

Nodo::Nodo(void) : valor(-1), siguiente(nullptr), anterior(nullptr) {
}

Nodo::Nodo(int _valor, Nodo* _siguiente, Nodo* _anterior) {

	setValor(_valor);
	setSiguiente(_siguiente);
	setAnterior(_anterior);
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

void Nodo::setAnterior(Nodo* _anterior) {
	this->anterior = _anterior;
}

Nodo *Nodo::getAnterior() {
	return this->anterior;
}
#include "nodo.h"
#include <iostream>


using namespace std;


void insertarAlInicio(nodo** inicio, const char* _name) {
	if (*inicio == 0) {
		nodo* nuevo = new nodo;

		nuevo->name = new char[strlen(_name)];
		strcpy(nuevo->name, _name);

		*inicio = nuevo;
	}
	else {
		nodo* nuevo = new nodo;
		nuevo->name = new char[strlen(_name)];
		strcpy(nuevo->name, _name);


		nuevo->siguiente = *inicio;
		(*inicio)->anterior = nuevo;
		
		*inicio = nuevo;
	}
}

void insertarAlFinal(nodo** inicio, const char* _name) {
	if (*inicio == 0) {
		nodo* nuevo = new nodo;

		nuevo->name = new char[strlen(_name)];
		strcpy(nuevo->name, _name);


		*inicio = nuevo;
	}
	else {
		nodo* nuevo = new nodo;
		nuevo->name = new char[strlen(_name)];
		strcpy(nuevo->name, _name);


		nodo* actual = *inicio;

		while (actual->siguiente != 0) {
			actual = actual->siguiente;
		}
		//aqui es donde se conecta //actual es el ultimo elemento cuando el apuntador de actual -> siguiente.
		actual->siguiente = nuevo;
		nuevo->anterior = actual;

	}
}

void imprimir(nodo ** lista) {
	if (*lista == 0) {
		return;
	}
	else {
		nodo *actual = new nodo;
		actual = *lista;

		while (actual != 0) {
			cout << "[" << actual->name << "] ";
			actual = actual->siguiente;
		}
	}
}

void ordenar(nodo** lista) {


}
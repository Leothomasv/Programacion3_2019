#include "nodo.h"
#include <iostream>

using namespace std;

void  ListaEnlazada::insertar(nodo** inicio, char* nombre) {
	if (*inicio == 0) {
		nodo  *nuevoNodo = new nodo();
		nuevoNodo->name = nombre;
		*inicio = nuevoNodo;
	}
	else {
		nodo *actual = *inicio;
		nodo *nuevoNodo = new nodo();
		
		while (actual->siguiente != 0) {
			if (strcmp(actual->name, nombre) > 0 && strcmp(actual->siguiente->name, nombre) < 0) {
				return;
			}
			actual = actual->siguiente;
		}
		nuevoNodo->name = nombre;
		actual->siguiente = nuevoNodo;
		actual->anterior = actual;
	}
}


//NUEVA FUNCION
nodo * ListaEnlazada::AgregarNombres(int cantidad)
{
	nodo* NuevoNodo = 0;

	for (int i = 0; i < cantidad; i++) {
		char* Nombre = new char;
		cout << "Ingrese nombre: ";
		cin >> Nombre;
		insertar(&NuevoNodo, Nombre);
	}
	return NuevoNodo;
}


void ListaEnlazada::imprimir(nodo ** lista) {
	if (*lista == 0) {
		return;
	}
	else {
		nodo *actual = new nodo;
		actual = *lista;
	
		while (actual != 0) {
			cout <<"["<< actual->name << "] ";
			actual = actual->siguiente;
		}
	}
}

bool ListaEnlazada::buscar(nodo** lista, char* nombre) {

	nodo* auxilar = *lista;
	while (auxilar != NULL) {

		if (strcmp(auxilar->name, nombre) == 0) {
			return true;
		}
		auxilar = auxilar->siguiente;
	}

	//buscar(&(auxilar)->siguiente, nombre);
	
}

void ListaEnlazada::eliminar(nodo** lista, char* nombre) {
	
	if (buscar(&(*lista), nombre) == 0)
	{
		return;
	}

	nodo* actual = *lista;


	while (actual != 0)
	{
		if (strcmp(actual->name, nombre) == 0)
		{
			if (actual == *lista)
			{
				*lista = actual->siguiente;
				delete actual;
				return;
			}
			else if (actual->siguiente == NULL)
			{
					actual->anterior->siguiente = NULL;
					delete actual;
					return;
			}
			else {
				actual->anterior->siguiente = actual->siguiente;
				actual->siguiente->anterior = actual->anterior;
				delete actual;
				return;
			}
		}
		actual = actual->siguiente;
	}
}


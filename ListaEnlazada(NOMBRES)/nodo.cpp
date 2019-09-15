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

void guardarAArchivo(nodo** lista) {

	ofstream fileNombres("nombres.txt", ios::app);

	if (!fileNombres) {
		cout << "error de apertura en archivo" << endl;
		return;
	}

	if (*lista == 0) {
		return;
	}
	else {
		nodo *actual = new nodo;
		actual = *lista;
		
		while (actual != 0) {
			fileNombres << actual->name << " ";
			actual = actual->siguiente;
		}
	}
	fileNombres.close();

}

void cargarDesdeArchivo(nodo** lista) {

	ifstream fileNombres("nombres.txt", ios::in);

	if (!fileNombres) {
		cout << "Error en lectura de archivo";
		return;
	}
	char nombre[30];
	while (fileNombres >> nombre) {

		cout << "\n {Nombre: " << nombre << "}";

	}
	cout << "\n";

	fileNombres.close();
}

void BuscarElemento(const char* name)
{
	ifstream fileNombres("nombres.txt", ios::in);

	if (!fileNombres) {
		cout << "Error en lectura de archivo";
		return;
	}
	char nombre[30];
	while (fileNombres >> nombre) {

		if (strcmp(nombre, name) == 0) {
			fileNombres.close();
			cout << "\n {Nombre encontrado: " << nombre << "}";
			cout << "\n";
		}
	}
	cout << "Nombre no encontrado..." << endl;
	cout << "\n";

	fileNombres.close();
}



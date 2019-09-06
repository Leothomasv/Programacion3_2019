#pragma warning(disable : 4996)
#include "nodo.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main() {

	//Ingresar Datos
	nodo *Lista = ListaEnlazada::AgregarNombres(5);//<- ESE NUMERO ES LA CANTIDAD DE NOMBRES QUE SE VAN A INSERTAR
	cout << "\n";
	cout << "<<<<IMPRESION DE LISTA ENLAZDA>>>>> \n";
	ListaEnlazada::imprimir(&Lista);
	cout << "\n";

	//Buscar
	char* nombre = new char;
	strcpy(nombre, "Leonel");
	if (ListaEnlazada::buscar(&Lista, nombre)) {
		cout << "\n [Dato encontrado] ";
	}
	else {
		cout << "\n [Dato No Encontrado] ";
	}


	char* nombre1 = new char;
	strcpy(nombre, "Leonel");
	ListaEnlazada::eliminar(&Lista, nombre1);

	cout << "\n";
	cout << "NUEVA LISTA ";
	ListaEnlazada::imprimir(&Lista);

	_getch();
}
#pragma warning(disable : 4996)
#include "nodo.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main() {

	//Ingresar Datos
	nodo *Lista = ListaEnlazada::AgregarNombres(5);//<- ESE NUMERO ES LA CANTIDAD DE NOMBRES QUE SE VAN A INSERTAR
	cout << "\n";
	cout << "<<<<IMPRESION DE LISTA ENLAZADA>>>>> \n";
	ListaEnlazada::imprimir(&Lista);
	cout << "\n";

	//Buscar
	char* nombre = new char;
	strcpy(nombre, "Leonel");
	if (ListaEnlazada::buscar(&Lista, nombre)) {
		cout << "\n [Dato encontrado] \n";
	}
	else {
		cout << "\n [Dato No Encontrado] \n";
	}



	//Eliminar 

	ListaEnlazada::eliminar(&Lista, (char*)"Leonel");

	cout << "\n";
	cout << "NUEVA LISTA= ";
	ListaEnlazada::imprimir(&Lista);

	_getch();
}
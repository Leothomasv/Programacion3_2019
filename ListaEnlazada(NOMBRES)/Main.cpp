#include "nodo.h"
#include <conio.h>
#include <iostream>

using namespace std;
int main() {
	nodo* inicio = 0;
	int opcion;

	do {
		cout << "<<<<<<MENU>>>>>>> \n";
		cout << " 1. Insertar al Inicio\n 2. Insertar al Final\n 3. Guardar a Archivo\n 4. Cargar el Archivo\n 5. Buscar elemento\n 6. SALIR\n";
		cout << "Ingrese opcion: ";
		cin >> opcion;

		switch (opcion)
		{

		case 1:
			int cantidad;
			char nombre[30];
			cout << "Ingrese cantidad de nombres que desea ingresar: ";
			cin >> cantidad;
			for (int i=0; i < cantidad; i++ ) {
				cout << "Ingrese nombre: ";
				cin >> nombre;
				insertarAlInicio(&inicio, nombre);
			}
			imprimir(&inicio);
			cout<<"\n";
			break;
		case 2:
			int cantidad1;
			char nombre1[30];
			cout << "Ingrese cantidad de nombres que desea ingresar: ";
			cin >> cantidad1;
			for (int y=0; y < cantidad1; y++) {
				cout << "Ingrese nombre: ";
				cin >> nombre1;
				insertarAlFinal(&inicio, nombre1);
			}
			imprimir(&inicio);
			cout << "\n";
			break;
		case 3:
			guardarAArchivo(&inicio);
			cout << "ARCHIVO GUARDADO EXITOSAMENTE"<<endl;
			cout << "\n";
			break;
		case 4:
			cargarDesdeArchivo(&inicio);
			break;
		case 5:
			char nombre2[30];
			cout << "Ingrese elemento a buscar: ";
			cin >> nombre2;
			BuscarElemento(nombre2);
			break;
		case 6:
			cout << "SALIENDO...";
			break;
		default:
			break;
		}


	} while (opcion != 6);

	_getch();

}
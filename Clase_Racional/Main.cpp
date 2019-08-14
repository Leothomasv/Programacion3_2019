#include <iostream>
#include "Racional.h"
#include <conio.h>

using std::cout;

int main() {
	Racional fraccion1;
	Racional fraccion2(7, 2);
	Racional fraccion3(6, 9);

	cout << "Fraccion 1: "; fraccion1.imprimir_flotante();
	cout << "Fraccion 2: "; fraccion2.imprimir_flotante();
	cout << "Fraccion 3: "; fraccion3.imprimir_flotante();

	fraccion1 = fraccion2.sumar(fraccion3);
	cout << "Fraccion 1: "; fraccion1.imprimir();

	fraccion1 = fraccion2.restar(fraccion3);
	cout << "Fraccion 1: "; fraccion1.imprimir();

	fraccion1 = fraccion2.multiplicar(fraccion3);
	cout << "Fraccion 1: "; fraccion1.imprimir();

	fraccion1 = fraccion2.dividir(fraccion3);
	cout << "Fraccion 1: "; fraccion1.imprimir();


	_getch();


}
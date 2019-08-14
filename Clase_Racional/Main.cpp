#include <iostream>
#include "Racional.h"
#include <conio.h>

using namespace std;

int main() {

	Racional r1(1, 5);
	Racional r2(2, 5);
	Racional r3(1, 2);

	Racional r4;

	cout << "SUMA \n";
	r4 = r1 + r2 + r3;
	r4.imprimir();
	cout << "\n";
	
	cout << "RESTA \n";
	r4 = r1 - r2 ;
	r4.imprimir();
	cout << "\n";

	cout << "MULTIPLICACION \n";
	r4 = r1 * r2;
	r4.imprimir();
	cout << "\n";
	
	cout << "DIVIDIR \n";
	r4 = r1 / r2;
	r4.imprimir();
	cout << "\n";

	

	_getch();


}
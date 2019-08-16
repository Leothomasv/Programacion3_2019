#include "Cadena.h"
#include <iostream>


Cadena::Cadena(char * c1) {
	cadena = new char[strlen(c1)]; //RESERVANDO ESPACIO EN MEMORIA
	strcpy(cadena, c1); // copiar los bytes 
}

Cadena::Cadena(Cadena &x) {
	this->cadena = x.cadena;
	this->SizeCadena = x.SizeCadena;

}

Cadena::Cadena(void) {
	cadena = new char[1];
	strcpy(cadena, " ");
}

Cadena operator +(Cadena&x, Cadena&y) {

	Cadena suma;

	suma.cadena(x.cadena + y.cadena);

	return suma;

}

ostream& operator << (ostream&x, const Cadena &y) {
	x << y.cadena;
	return x;
}






#include "Cadena.h"
#include <iostream>

using namespace std;

Cadena::Cadena(void) {
	cadena = new char[1];
	strcpy(cadena, " ");
}

Cadena::Cadena(const char* c) {
	cadena = new char[strlen(c)];
	strcpy(cadena, c); 
}


Cadena Cadena::substr(int pos, int length) {

	Cadena cad;
	int nueva = 0;
	cad.SizeCadena = length;

	for (int i = pos; i < (pos + length); i++)

	{
		cad.cadena[nueva] = cadena[i];
		if (nueva < length) {
			nueva++;
		}
	}
	return cad;
}

int Cadena::strcmp(const Cadena& x) {
	for (int i = 0; i < SizeCadena; i++)

	{
		if (cadena[i] != x.cadena[i]) {
			if (cadena[i] < x.cadena[i]) {
				return -1;
			}
			else if (cadena[i] > x.cadena[i]) {
				return 1;
			}
		}
		else if (cadena[i] == x.cadena[i && i == SizeCadena - 1]) {
			return 0;
		}
	}
}

 Cadena operator+(const Cadena&x) {
	Cadena cad;


	return cad;

}

ostream& operator<<(ostream& salida, const Cadena &x) {
	salida << x.cadena;
	return salida;
}


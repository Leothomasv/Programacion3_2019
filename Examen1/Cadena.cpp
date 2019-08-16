#include "Cadena.h"
#include <iostream>

using namespace std;

Cadena::Cadena(void) {
	cadena = new char[1];
	strcpy(cadena, " ");
}


int Cadena::strCmp(const Cadena& x) {
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





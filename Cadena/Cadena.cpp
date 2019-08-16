#include <iostream>
#include "Cadena.h"

Cadena::Cadena(char * c1) {
	cadena = new char[strlen(c1)]; //RESERVANDO ESPACIO EN MEMORIA
	strcpy(cadena, c1); // copiar los bytes 
}

Cadena::Cadena(void) {
	cadena = new char[1];
	strcpy(cadena, " ");
}

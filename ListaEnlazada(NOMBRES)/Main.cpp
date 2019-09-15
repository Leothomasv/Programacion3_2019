#include "nodo.h"
#include <conio.h>

int main() {
	nodo* inicio = 0;

	insertarAlInicio(&inicio, "Charles");
	insertarAlInicio(&inicio, "John");
	insertarAlFinal(&inicio, "Annie");

	imprimir(&inicio);

	guardarAArchivo(&inicio);//listo

	_getch();

}
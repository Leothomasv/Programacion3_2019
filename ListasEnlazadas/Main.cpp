#include <iostream>
#include "ListaEnlazada.h"

ListaEnlazada lista;


int main() {

lista.agregar(7);
lista.agregar(4);
lista.agregar(3);
lista.insertar(1, 11);
lista.insertar(4, 9);


lista.imprimir();

system("pause");
}


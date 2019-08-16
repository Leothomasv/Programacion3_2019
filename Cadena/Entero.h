#pragma once
#include <iostream>
#include "Cadena.h"
using namespace std;

#ifndef ENTERO_H
#define ENTERO_H

class Entero {

	friend istream operator >> (istream &, Entero&);
	friend Entero operator + (Cadena&, const Entero&);

private:
	int valor;

public:
	Entero(void);

};

#endif // !ENTERO_H

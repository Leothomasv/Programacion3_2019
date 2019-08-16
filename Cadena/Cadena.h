#pragma once
#include <iostream>
#include "Entero.h"

using namespace std;

#ifndef CADENA_H
#define CADENA_H

class Cadena {
	
	friend Cadena operator + (Cadena&, Cadena&);

private:
	char *cadena;


public:
	Cadena(char *);
	Cadena(void);



};






#endif // !CADENA_H

#pragma once
#include <iostream>

#ifndef CADENA_H
#define CADENA_H

using namespace std;

class Cadena {

	friend Cadena operator + (Cadena&, Cadena&);
	friend ostream& operator << (ostream& x, const Cadena & y);

private:
	int SizeCadena;
	char * cadena;

public:
	Cadena(char* x);
	Cadena(void);
	Cadena(Cadena &x);


};

#endif // !CADENA_H

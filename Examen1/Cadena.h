#pragma once
#include <iostream>

#ifndef CADENA_H
#define CADENA_H

using namespace std;

class Cadena {

	friend Cadena operator + (const Cadena& x);
	friend ostream& operator << (ostream& x, const Cadena & y);

private:
	int SizeCadena;
	char * cadena;

public:
	Cadena(const char*);
	Cadena(void);
	Cadena(Cadena &x);

	Cadena substr(int pos, int length);
	int strcmp(const Cadena& x);

};

#endif // !CADENA_H
